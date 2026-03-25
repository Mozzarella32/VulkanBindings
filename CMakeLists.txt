cmake_minimum_required(VERSION 3.16)
project(VulkanBindings LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GENERATOR_NAME "BindingsGenerator")
set(INVOKE_GENERATOR_NAME "InvokeBindingsGenerator")
set(UTILS_NAME "VkUtils")
set(BINDINGS_NAME "VkBindings")

set(GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(GENERATED_HEADERS
  "${GENERATED_DIR}/include/VkBindings/Objects.hpp"
  "${GENERATED_DIR}/include/VkBindings/Objects_Forward.hpp"
  "${GENERATED_DIR}/include/VkBindings/ObjectReflections.hpp"
  "${GENERATED_DIR}/include/VkBindings/Constants.hpp"
  "${GENERATED_DIR}/include/VkBindings/Enums.hpp"
  "${GENERATED_DIR}/include/VkBindings/Structs.hpp"
  "${GENERATED_DIR}/include/VkBindings/Defines.hpp"
  "${GENERATED_DIR}/include/VkBindings/FunctionPtrs.hpp"
)
set(GENERATED_SRCS
  "${GENERATED_DIR}/src/Objects.cpp"
  "${GENERATED_DIR}/src/Instance.cpp"
  "${GENERATED_DIR}/src/PhysicalDevice.cpp"
  "${GENERATED_DIR}/src/Device.cpp"
  "${GENERATED_DIR}/src/CommandBuffer.cpp"
  "${GENERATED_DIR}/src/ObjectReflections.cpp"
  "${GENERATED_DIR}/src/EnumsCorrectAsserts.cpp"
  "${GENERATED_DIR}/src/EnumToString.cpp"
  "${GENERATED_DIR}/src/BitmaskToString.cpp"
  "${GENERATED_DIR}/src/Structs.cpp"
  "${GENERATED_DIR}/src/StructsCorrectAsserts.cpp"
)


find_package(Vulkan QUIET)
message(STATUS "VulkanVersion: ${Vulkan_VERSION}")
set(VK_XML_URL "https://raw.githubusercontent.com/KhronosGroup/Vulkan-Docs/v${Vulkan_VERSION}/xml/vk.xml" CACHE STRING "URL to vk.xml")
set(VK_XML_FILE "${CMAKE_CURRENT_BINARY_DIR}/vk.xml")

set(VK_CACHE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.vk_cache")
file(MAKE_DIRECTORY "${VK_CACHE_DIR}")
set(VK_CACHE_XML "${VK_CACHE_DIR}/vk.xml")

message(STATUS "vk.xml will be at: ${VK_XML_FILE}")
message(STATUS "vk.xml repo-local cache dir: ${VK_CACHE_DIR}")

if(NOT EXISTS "${VK_XML_FILE}")
  message(STATUS "Downloading vk.xml from: ${VK_XML_URL}")
  file(DOWNLOAD "${VK_XML_URL}" "${VK_XML_FILE}" STATUS _dl_status)
  list(GET _dl_status 0 _dl_code)
  if(NOT _dl_code EQUAL 0)
    list(GET _dl_status 1 _dl_msg)
    if(EXISTS "${VK_CACHE_XML}")
      message(WARNING "Failed to download vk.xml: ${_dl_msg}. Using cached vk.xml at: ${VK_CACHE_XML}")
      if(EXISTS "${VK_CACHE_XML}")
        file(COPY "${VK_CACHE_XML}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
      else()
        message(FATAL_ERROR "Cached vk.xml expected at ${VK_CACHE_XML} but it's missing.")
      endif()
    else()
      message(FATAL_ERROR "Failed to download vk.xml: ${_dl_msg} and no cached copy (${VK_CACHE_XML}) found.")
    endif()
  else()
    if(EXISTS "${VK_XML_FILE}")
      message(STATUS "Downloaded vk.xml; caching a copy to: ${VK_CACHE_XML}")
      file(COPY "${VK_XML_FILE}" DESTINATION "${VK_CACHE_DIR}")
    else()
      message(WARNING "Download reported success but ${VK_XML_FILE} not found; skipping cache write.")
    endif()
  endif()
else()
  message(STATUS "Using existing vk.xml at: ${VK_XML_FILE}")
  if(EXISTS "${VK_XML_FILE}")
    if(NOT EXISTS "${VK_CACHE_XML}" OR NOT "${VK_CACHE_XML}" STREQUAL "${VK_XML_FILE}")
      file(COPY "${VK_XML_FILE}" DESTINATION "${VK_CACHE_DIR}")
    endif()
  else()
    message(WARNING "Expected vk.xml at ${VK_XML_FILE} but it does not exist; not updating cache.")
  endif()
endif()

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Werror -Wall -Wextra -Wpedantic -Wno-missing-field-initializers)
endif()

file(GLOB_RECURSE GENERATOR_SRCS
  CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/generator/src/*.cpp"
)

add_executable(${GENERATOR_NAME} ${GENERATOR_SRCS})

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/submodules/tinyxml2" EXCLUDE_FROM_ALL)

target_link_libraries(${GENERATOR_NAME} PRIVATE tinyxml2)

target_include_directories(${GENERATOR_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/generator/include")

add_custom_command(
  OUTPUT ${GENERATED_HEADERS} ${GENERATED_SRCS}
  COMMAND ${CMAKE_COMMAND} -E make_directory "${GENERATED_DIR}"
  COMMAND $<TARGET_FILE:${GENERATOR_NAME}> "${VK_XML_FILE}" "${GENERATED_DIR}"
  DEPENDS ${GENERATOR_NAME} "${VK_XML_FILE}"
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  COMMENT "Generating files into ${GENERATED_DIR}"
  VERBATIM
)

add_custom_target(${INVOKE_GENERATOR_NAME} ALL DEPENDS ${GENERATED_HEADERS})

add_subdirectory("${PROJECT_SOURCE_DIR}/submodules/volk")

file(GLOB_RECURSE BINDINGS_SRCS
  CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/bindings/src/*.cpp"
)

add_library(${BINDINGS_NAME} STATIC
  ${BINDINGS_SRCS}
  ${GENERATED_SRCS}
)

target_include_directories(${BINDINGS_NAME}
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/bindings/include"
    "${GENERATED_DIR}/include"
)

target_include_directories(${BINDINGS_NAME}
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/bindings/privat_include"
)

target_link_libraries(${BINDINGS_NAME} PUBLIC volk_headers)

add_dependencies(${BINDINGS_NAME} ${INVOKE_GENERATOR_NAME})

add_library(VulkanBindings ALIAS ${BINDINGS_NAME})
