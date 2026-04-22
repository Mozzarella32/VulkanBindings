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
set(GENERATED_INCLUDE_DIR "${GENERATED_DIR}/include/VkBindings")
set(GENERATED_PRIVATE_INCLUDE_DIR "${GENERATED_INCLUDE_DIR}/private")
set(GENERATED_SRC_DIR "${GENERATED_DIR}/src")
set(GENERATED_HEADERS
  "${GENERATED_PRIVATE_INCLUDE_DIR}/Handles.hpp"
  "${GENERATED_PRIVATE_INCLUDE_DIR}/FunctionTables.hpp"
  "${GENERATED_INCLUDE_DIR}/Objects.hpp"
  "${GENERATED_INCLUDE_DIR}/ObjectsForward.hpp"
  "${GENERATED_INCLUDE_DIR}/ObjectReflections.hpp"
  "${GENERATED_INCLUDE_DIR}/Constants.hpp"
  "${GENERATED_INCLUDE_DIR}/Enums.hpp"
  "${GENERATED_INCLUDE_DIR}/Structs.hpp"
  "${GENERATED_INCLUDE_DIR}/StructsForward.hpp"
  "${GENERATED_INCLUDE_DIR}/Defines.hpp"
  "${GENERATED_INCLUDE_DIR}/FunctionPtrs.hpp"
  "${GENERATED_INCLUDE_DIR}/BaseTypes.hpp"
)
set(GENERATED_SRCS
  "${GENERATED_SRC_DIR}/ObjectTemplates.cpp"
  "${GENERATED_SRC_DIR}/Objects.cpp"
  "${GENERATED_SRC_DIR}/Instance.cpp"
  "${GENERATED_SRC_DIR}/PhysicalDevice.cpp"
  "${GENERATED_SRC_DIR}/Device.cpp"
  "${GENERATED_SRC_DIR}/CommandBuffer.cpp"
  "${GENERATED_SRC_DIR}/ObjectReflections.cpp"
  "${GENERATED_SRC_DIR}/EnumsCorrectAsserts.cpp"
  "${GENERATED_SRC_DIR}/EnumToString.cpp"
  "${GENERATED_SRC_DIR}/BitmaskToString.cpp"
  "${GENERATED_SRC_DIR}/Structs.cpp"
  "${GENERATED_SRC_DIR}/StructsCorrectAsserts.cpp"
  "${GENERATED_SRC_DIR}/LoadGlobals.cpp"
  "${GENERATED_SRC_DIR}/LoadInstanceTable.cpp"
  "${GENERATED_SRC_DIR}/LoadDeviceTable.cpp"
)

find_package(Vulkan QUIET)
message(STATUS "VulkanVersion: ${Vulkan_VERSION}")

set(VK_XML_URL
    "https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/v${Vulkan_VERSION}/registry/vk.xml"
    CACHE STRING "URL to vk.xml")
set(VIDEO_XML_URL
    "https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/v${Vulkan_VERSION}/registry/video.xml"
    CACHE STRING "URL to video.xml")
set(VK_PLATFORM_URL
    "https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/v${Vulkan_VERSION}/include/vulkan/vk_platform.h"
    CACHE STRING "URL to vk_platform.h")

set(VK_XML_FILE        "${CMAKE_CURRENT_BINARY_DIR}/vk.xml")
set(VIDEO_XML_FILE     "${CMAKE_CURRENT_BINARY_DIR}/video.xml")
set(VK_PLATFORM_FILE   "${CMAKE_CURRENT_SOURCE_DIR}/bindings/include/VkBindings/private/vk_platform.h")

set(VK_CACHE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.vk_cache")
file(MAKE_DIRECTORY "${VK_CACHE_DIR}")

function(download_and_cache NAME URL OUT_FILE)

  get_filename_component(_filename "${OUT_FILE}" NAME)
  set(_cache_path "${VK_CACHE_DIR}/${_filename}")

  if(NOT EXISTS "${OUT_FILE}")
    message(STATUS "Downloading ${NAME} from: ${URL}")
    file(DOWNLOAD "${URL}" "${OUT_FILE}" STATUS _dl_status)
    list(GET _dl_status 0 _dl_code)
    if(NOT _dl_code EQUAL 0)
      list(GET _dl_status 1 _dl_msg)
      if(EXISTS "${_cache_path}")
        message(WARNING "Failed to download ${NAME}: ${_dl_msg}. Using cached ${NAME} at: ${_cache_path}")
        file(COPY "${_cache_path}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
      else()
        message(FATAL_ERROR "Failed to download ${NAME}: ${_dl_msg} and no cached copy (${_cache_path}) found.")
      endif()
    else()
      if(EXISTS "${OUT_FILE}")
        # message(STATUS "Downloaded ${NAME}; caching a copy to: ${_cache_path}")
        file(COPY "${OUT_FILE}" DESTINATION "${VK_CACHE_DIR}")
      else()
        message(WARNING "Download reported success but ${OUT_FILE} not found; skipping cache write.")
      endif()
    endif()
  else()
    message(STATUS "Using existing ${NAME} at: ${OUT_FILE}")
    if(NOT EXISTS "${_cache_path}")
      message(STATUS "Caching existing ${NAME} to: ${_cache_path}")
      file(COPY "${OUT_FILE}" DESTINATION "${VK_CACHE_DIR}")
    endif()
  endif()
endfunction()

download_and_cache("vk.xml"        "${VK_XML_URL}"      "${VK_XML_FILE}")
download_and_cache("video.xml"     "${VIDEO_XML_URL}"   "${VIDEO_XML_FILE}")
download_and_cache("vk_platform.h" "${VK_PLATFORM_URL}" "${VK_PLATFORM_FILE}")

set(DOWNLOADED_VK_XML       "${VK_XML_FILE}"       CACHE PATH "Downloaded vk.xml path")
set(DOWNLOADED_VIDEO_XML    "${VIDEO_XML_FILE}"    CACHE PATH "Downloaded video.xml path")
set(DOWNLOADED_VK_PLATFORM  "${VK_PLATFORM_FILE}"  CACHE PATH "Downloaded vk_platform.h path")

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
  COMMAND $<TARGET_FILE:${GENERATOR_NAME}> "${CMAKE_CURRENT_BINARY_DIR}" "${GENERATED_DIR}"
  DEPENDS ${GENERATOR_NAME} "${VK_XML_FILE}"
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  COMMENT "Generating files into ${GENERATED_DIR}"
  VERBATIM
)

add_custom_target(${INVOKE_GENERATOR_NAME} ALL DEPENDS ${GENERATED_HEADERS})

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

target_link_libraries(${BINDINGS_NAME} PUBLIC volk_headers)

add_dependencies(${BINDINGS_NAME} ${INVOKE_GENERATOR_NAME})

add_library(VulkanBindings ALIAS ${BINDINGS_NAME})
