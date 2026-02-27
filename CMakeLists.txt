cmake_minimum_required(VERSION 3.16)
project(VulkanBidngingsGenerator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(VK_XML_URL "https://raw.githubusercontent.com/KhronosGroup/Vulkan-Docs/main/xml/vk.xml" CACHE STRING "URL to vk.xml")
set(VK_XML_FILE "${CMAKE_CURRENT_BINARY_DIR}/vk.xml")

set(GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(GENERATED_HEADERS
  "${GENERATED_DIR}/Structures.hpp"
  # "${GENERATED_DIR}/vk_enum_map.h"
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

add_executable(${PROJECT_NAME}
  src/main.cpp
)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/submodules/tinyxml2" EXCLUDE_FROM_ALL)

target_link_libraries(${PROJECT_NAME} PRIVATE tinyxml2)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_custom_command(
  OUTPUT ${GENERATED_HEADERS}
  COMMAND ${CMAKE_COMMAND} -E make_directory "${GENERATED_DIR}"
  COMMAND $<TARGET_FILE:${PROJECT_NAME}> "${VK_XML_FILE}" "${GENERATED_DIR}"
  DEPENDS ${PROJECT_NAME} "${VK_XML_FILE}"
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  COMMENT "Generating headers into ${GENERATED_DIR}"
  VERBATIM
)

add_custom_target(generate_vk_headers ALL DEPENDS ${GENERATED_HEADERS})

message(STATUS "Generated headers: ${GENERATED_HEADERS}")
message(STATUS "vk.xml: ${VK_XML_FILE}")
message(STATUS "Generator executable: vk_xml_processor")
