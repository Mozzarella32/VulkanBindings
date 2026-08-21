cmake_minimum_required(VERSION 3.16)
project(VulkanBindings LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GENERATOR_NAME "BindingsGenerator")
set(INVOKE_GENERATOR_NAME "InvokeBindingsGenerator")
set(VALIDATION_NAME "Validation")
set(BINDINGS_NAME "VkBindings")

set(GENERATED_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/generated"
)

set(GENERATED_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/generated"
)

set(GENERATED_FILES_CMAKE_FILES_DIR
    "${GENERATED_DIR}/cmake"
)

set(GENERATED_MANIFEST
    "${GENERATED_FILES_CMAKE_FILES_DIR}/GeneratedFiles.cmake"
)

# This makes cmake reconfigure and discover GeneratedFiles.cmake
file(GLOB GENERATED_CMAKE_FILES
    CONFIGURE_DEPENDS
    "${GENERATED_FILES_CMAKE_FILES_DIR}/*.cmake"
)

set(GENERATED_HEADERS "${GENERATED_DIR}/src/Device.cpp")

set(GENERATED_SRCS)
set(VALIDATION_SRCS "${GENERATED_DIR}/validation/BitmaskCorrectAsserts.cpp")

file(MAKE_DIRECTORY
    "${GENERATED_DIR}"
    "${GENERATED_FILES_CMAKE_FILES_DIR}"
)

if(EXISTS "${GENERATED_MANIFEST}")
    message(STATUS "Including generated CMake file: ${GENERATED_MANIFEST}")
    include("${GENERATED_MANIFEST}")
endif()

set(VULKAN_REGISTRY_VERSION "1.4.357" CACHE STRING "Vulkan-Headers version used to generate the bindings")

set(VK_HEADERS "https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/v${VULKAN_REGISTRY_VERSION}")

set(VK_XML_URL      "${VK_HEADERS}/registry/vk.xml")
set(VIDEO_XML_URL   "${VK_HEADERS}/registry/video.xml")
set(VK_PLATFORM_URL "${VK_HEADERS}/include/vulkan/vk_platform.h")
set(VK_CORE_URL     "${VK_HEADERS}/include/vulkan/vulkan_core.h")


set(VALIDATION_DIR              "${CMAKE_CURRENT_BINARY_DIR}/validation")
set(VALIDATION_VULKAN_DIR       "${VALIDATION_DIR}/vulkan")
set(VALIDATION_VK_VIDEO_DIR     "${VALIDATION_DIR}/vk_video")

set(VK_XML_FILE                 "${CMAKE_CURRENT_BINARY_DIR}/vk.xml")
set(VIDEO_XML_FILE              "${CMAKE_CURRENT_BINARY_DIR}/video.xml")
set(VK_PLATFORM_FILE_BINDINGS   "${CMAKE_CURRENT_SOURCE_DIR}/bindings/include/VkBindings/private/vk_platform.h")
set(VK_PLATFORM_FILE_VALIDATION "${VALIDATION_VULKAN_DIR}/vk_platform.h")
set(VK_CORE_FILE_VALIDATION     "${VALIDATION_VULKAN_DIR}/vulkan_core.h")

set(VK_CACHE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.vk_cache/${VULKAN_REGISTRY_VERSION}")
file(MAKE_DIRECTORY "${VK_CACHE_DIR}")

function(download_and_cache NAME URL OUT_FILE)
    get_filename_component(_filename "${OUT_FILE}" NAME)
    get_filename_component(_out_dir "${OUT_FILE}" DIRECTORY)

    set(_cache_path "${VK_CACHE_DIR}/${_filename}")
    set(_temporary_file "${OUT_FILE}.download")

    if(EXISTS "${_cache_path}" AND EXISTS "${OUT_FILE}")
        file(SHA256 "${_cache_path}" _cache_hash)
        file(SHA256 "${OUT_FILE}" _output_hash)

        if(_cache_hash STREQUAL _output_hash)
            return()
        endif()
    endif()

    file(MAKE_DIRECTORY "${_out_dir}" "${VK_CACHE_DIR}")

    if(EXISTS "${_cache_path}")
        message(STATUS "Using cached ${NAME} from: ${_cache_path}")
        file(COPY "${_cache_path}" DESTINATION "${_out_dir}")

        if(NOT EXISTS "${OUT_FILE}")
            message(FATAL_ERROR "Failed to copy cached ${NAME} to: ${OUT_FILE}")
        endif()

        return()
    endif()

    message(STATUS "Downloading ${NAME} from: ${URL}")

    if(EXISTS "${_temporary_file}")
        file(REMOVE "${_temporary_file}")
    endif()

    file(DOWNLOAD "${URL}" "${_temporary_file}" STATUS _download_status TLS_VERIFY ON)

    list(GET _download_status 0 _download_code)
    list(GET _download_status 1 _download_message)

    # Check the download status.
    if(NOT _download_code EQUAL 0)
        if(EXISTS "${_temporary_file}")
            file(REMOVE "${_temporary_file}")
        endif()

        message(FATAL_ERROR "Failed to download ${NAME}: ${_download_message}")
    endif()

    if(NOT EXISTS "${_temporary_file}")
        message(FATAL_ERROR "Download reported success, but no file was created for ${NAME}")
    endif()

    file(SIZE "${_temporary_file}" _downloaded_size)

    if(_downloaded_size EQUAL 0)
        file(REMOVE "${_temporary_file}")
        message(FATAL_ERROR "Downloaded ${NAME}, but the resulting file is empty")
    endif()

    file(RENAME "${_temporary_file}" "${OUT_FILE}")

    if(NOT EXISTS "${OUT_FILE}")
        message(FATAL_ERROR "Downloaded ${NAME}, but failed to create: ${OUT_FILE}")
    endif()

    file(COPY "${OUT_FILE}" DESTINATION "${VK_CACHE_DIR}")

    if(NOT EXISTS "${_cache_path}")
        message(FATAL_ERROR "Downloaded ${NAME}, but failed to cache it at: ${_cache_path}")
    endif()
endfunction()


download_and_cache("vk.xml"        "${VK_XML_URL}"      "${VK_XML_FILE}")
download_and_cache("video.xml"     "${VIDEO_XML_URL}"   "${VIDEO_XML_FILE}")
download_and_cache("vk_platform.h" "${VK_PLATFORM_URL}" "${VK_PLATFORM_FILE_BINDINGS}")
download_and_cache("vk_platform.h" "${VK_PLATFORM_URL}" "${VK_PLATFORM_FILE_VALIDATION}")
download_and_cache("vulkan_core.h" "${VK_CORE_URL}"     "${VK_CORE_FILE_VALIDATION}")

set(VK_VIDEO_TREE_URL "https://api.github.com/repos/KhronosGroup/Vulkan-Headers/git/trees/v${VULKAN_REGISTRY_VERSION}?recursive=1")
set(VK_VIDEO_TREE_FILE "${CMAKE_CURRENT_BINARY_DIR}/vulkan_headers_tree.json")
download_and_cache("Vulkan-Headers repository tree" "${VK_VIDEO_TREE_URL}" "${VK_VIDEO_TREE_FILE}")

file(READ "${VK_VIDEO_TREE_FILE}" VK_HEADERS_TREE)

if(VK_HEADERS_TREE MATCHES "\"truncated\"[ \t]*:[ \t]*true")
    message(FATAL_ERROR "The Vulkan-Headers repository tree was truncated by GitHub")
endif()

string(REGEX MATCHALL "\"path\"[ \t]*:[ \t]*\"include/vk_video/[^\"]+\"[^}]*\"type\"[ \t]*:[ \t]*\"blob\"" VK_VIDEO_TREE_ENTRIES "${VK_HEADERS_TREE}")
if(NOT VK_VIDEO_TREE_ENTRIES)
    message(FATAL_ERROR "No files found under include/vk_video in Vulkan-Headers v${VULKAN_REGISTRY_VERSION}")
endif()

set(VK_VIDEO_FILES)

foreach(VK_VIDEO_ENTRY IN LISTS VK_VIDEO_TREE_ENTRIES)

    string(REGEX MATCH "include/vk_video/[^\"]+" VK_VIDEO_FULL_PATH "${VK_VIDEO_ENTRY}")
    string(REPLACE "include/vk_video/" "" VK_VIDEO_RELATIVE_PATH "${VK_VIDEO_FULL_PATH}")
    set(VK_VIDEO_OUTPUT_FILE "${VALIDATION_VK_VIDEO_DIR}/${VK_VIDEO_RELATIVE_PATH}")
    get_filename_component(VK_VIDEO_OUTPUT_DIR "${VK_VIDEO_OUTPUT_FILE}" DIRECTORY)

    file(MAKE_DIRECTORY "${VK_VIDEO_OUTPUT_DIR}")
    set(VK_VIDEO_RAW_URL "${VK_HEADERS}/include/vk_video/${VK_VIDEO_RELATIVE_PATH}")
    download_and_cache("vk_video/${VK_VIDEO_RELATIVE_PATH}" "${VK_VIDEO_RAW_URL}" "${VK_VIDEO_OUTPUT_FILE}")

    list(APPEND VK_VIDEO_FILES "${VK_VIDEO_OUTPUT_FILE}")
endforeach()

list(SORT VK_VIDEO_FILES)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Werror -Wall -Wextra -Wpedantic -Wno-missing-field-initializers)
endif()

file(GLOB_RECURSE GENERATOR_SRCS
  CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/generator/src/*.cpp"
)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/submodules/tinyxml2" EXCLUDE_FROM_ALL)

# GENERATOR

add_executable(${GENERATOR_NAME} ${GENERATOR_SRCS})

target_compile_features(${GENERATOR_NAME} PRIVATE cxx_std_23)

target_include_directories(${GENERATOR_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/generator/include")

target_link_libraries(${GENERATOR_NAME} PRIVATE tinyxml2)

# GENERATING

# First invocation: generate GeneratedFiles.cmake.
add_custom_command(
    OUTPUT "${GENERATED_MANIFEST}"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${GENERATED_DIR}"
    COMMAND $<TARGET_FILE:${GENERATOR_NAME}> -cmake "${CMAKE_CURRENT_BINARY_DIR}" "${GENERATED_DIR}"
    DEPENDS ${GENERATOR_NAME} "${VK_XML_FILE}" "${VIDEO_XML_FILE}"
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    COMMENT "Generating Vulkan bindings CMake manifest"
    VERBATIM
)

# Second invocation: generate the actual files listed by GeneratedFiles.cmake.
add_custom_command(
    OUTPUT ${GENERATED_HEADERS} ${GENERATED_SRCS} ${VALIDATION_SRCS}
    COMMAND ${CMAKE_COMMAND} -E make_directory "${GENERATED_DIR}"
    COMMAND $<TARGET_FILE:${GENERATOR_NAME}> -files "${CMAKE_CURRENT_BINARY_DIR}" "${GENERATED_DIR}"
    DEPENDS "${GENERATED_MANIFEST}" "${VK_XML_FILE}" "${VIDEO_XML_FILE}"
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    COMMENT "Generating Vulkan binding files"
    VERBATIM
)

add_custom_target(${INVOKE_GENERATOR_NAME}
    DEPENDS
        "${GENERATED_MANIFEST}"
        ${GENERATED_HEADERS}
        ${GENERATED_SRCS}
        ${VALIDATION_SRCS}
)

# Validation
add_library(${VALIDATION_NAME} STATIC ${VALIDATION_SRCS})

add_dependencies(${VALIDATION_NAME}
    ${INVOKE_GENERATOR_NAME}
)

target_include_directories(${VALIDATION_NAME}
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/bindings/include"
    "${GENERATED_DIR}/include"
    "${VALIDATION_VULKAN_DIR}"
)

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

add_dependencies(${BINDINGS_NAME} ${INVOKE_GENERATOR_NAME} ${VALIDATION_NAME})

add_library(VulkanBindings ALIAS ${BINDINGS_NAME})
