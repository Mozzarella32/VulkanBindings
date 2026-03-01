cmake_minimum_required(VERSION 3.16)
project(VulkanBindings LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GENERATOR_NAME "BindingsGenerator")
set(INVOKE_GENERATOR_NAME "InvokeBindingsGenerator")
set(UTILS_NAME "VkUtils")
set(BINDINGS_NAME "VkBindings")

set(VK_XML_URL "https://raw.githubusercontent.com/KhronosGroup/Vulkan-Docs/main/xml/vk.xml" CACHE STRING "URL to vk.xml")
set(VK_XML_FILE "${CMAKE_CURRENT_BINARY_DIR}/vk.xml")

set(GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(GENERATED_HEADERS
  "${GENERATED_DIR}/Structures.hpp"
)

if(NOT EXISTS "${VK_XML_FILE}")
  message(STATUS "Downloading vk.xml from: ${VK_XML_URL}")
  file(DOWNLOAD "${VK_XML_URL}" "${VK_XML_FILE}" SHOW_PROGRESS STATUS _dl_status)
  list(GET _dl_status 0 _dl_code)
  if(NOT _dl_code EQUAL 0)
    list(GET _dl_status 1 _dl_msg)
    message(FATAL_ERROR "Failed to download vk.xml: ${_dl_msg}")
  endif()
else()
  message(STATUS "Using existing vk.xml at: ${VK_XML_FILE}")
endif()

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Werror -Wall -Wextra -Wpedantic -Wno-missing-field-initializers)
endif()

add_executable(${GENERATOR_NAME}
  generator/src/main.cpp
)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/submodules/tinyxml2" EXCLUDE_FROM_ALL)

target_link_libraries(${GENERATOR_NAME} PRIVATE tinyxml2)

target_include_directories(${GENERATOR_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_custom_command(
  OUTPUT ${GENERATED_HEADERS}
  COMMAND ${CMAKE_COMMAND} -E make_directory "${GENERATED_DIR}"
  COMMAND $<TARGET_FILE:${GENERATOR_NAME}> "${VK_XML_FILE}" "${GENERATED_DIR}"
  DEPENDS ${GENERATOR_NAME} "${VK_XML_FILE}"
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  COMMENT "Generating headers into ${GENERATED_DIR}"
  VERBATIM
)

add_custom_target(${INVOKE_GENERATOR_NAME} ALL DEPENDS ${GENERATED_HEADERS})

add_subdirectory("${PROJECT_SOURCE_DIR}/submodules/volk")

file(GLOB_RECURSE BINDINGS_SRCS
  CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/bindings/src/*.cpp"
)

add_library(${BINDINGS_NAME} STATIC ${BINDINGS_SRCS})

target_include_directories(${BINDINGS_NAME}
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/bindings/include"
    "${GENERATED_DIR}"
)

target_link_libraries(${BINDINGS_NAME} PUBLIC volk_headers)

add_dependencies(${BINDINGS_NAME} ${INVOKE_GENERATOR_NAME})

# add_library(${UTILS_NAME} STATIC ${UTILS_SRCS})

# target_include_directories(${UTILS_NAME}
#   PUBLIC
#     "${CMAKE_CURRENT_SOURCE_DIR}/utils/include"
#     "${GENERATED_DIR}"
# )

# target_link_libraries(${UTILS_NAME} PUBLIC volk_headers)

# add_dependencies(${UTILS_NAME} ${INVOKE_GENERATOR_NAME})

# add_library(VulkanBindings::Utils ALIAS ${UTILS_NAME})
add_library(VulkanBindings ALIAS ${BINDINGS_NAME})
