cmake_minimum_required(VERSION 3.16)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

project(VulkanBindings LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CPM_SOURCE_CACHE
    "${CMAKE_CURRENT_SOURCE_DIR}/.fetched"
    CACHE PATH "CPM source cache"
)
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/CPM.cmake")

set(GENERATED_DIR "${CMAKE_CURRENT_SOURCE_DIR}/generated")

include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/GeneratedFiles.cmake")

set(VULKAN_REGISTRY_VERSION "" CACHE STRING "Vulkan-Headers version to use. Empty means latest matching tag.")

set(GENERATED_VERSION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/.vulkan_registry_version")
set(GENERATION_TRIGGER_FILE "${CMAKE_CURRENT_BINARY_DIR}/.vulkan_generation_trigger")

if(NOT VULKAN_REGISTRY_VERSION STREQUAL "")
    message(STATUS "Using set Vulkan-Header tag: ${VULKAN_REGISTRY_VERSION}")
endif()

if(VULKAN_REGISTRY_VERSION STREQUAL "")
    find_program(GIT_EXECUTABLE git)
    if(GIT_EXECUTABLE)
        execute_process(
            COMMAND sh -c
                "${GIT_EXECUTABLE} ls-remote --refs --tags https://github.com/KhronosGroup/Vulkan-Headers | cut --delimiter='/' --fields=3 | grep --extended-regexp '^v[0-9]' | sort --version-sort | tail --lines=1"
            OUTPUT_VARIABLE VULKAN_RELEASE_TAG
            ERROR_VARIABLE VULKAN_RELEASE_TAG_ERROR
            RESULT_VARIABLE VULKAN_RELEASE_TAG_RESULT
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )

        if(VULKAN_RELEASE_TAG_RESULT EQUAL 0 AND
           NOT VULKAN_RELEASE_TAG STREQUAL "")

            # Convert v1.4.357 to 1.4.357.
            string(REGEX REPLACE "^v" ""
                   VULKAN_REGISTRY_VERSION
                   "${VULKAN_RELEASE_TAG}")

            message(STATUS
                "Using latest Vulkan-Headers tag: ${VULKAN_RELEASE_TAG}")
        else()
            message(WARNING
                "Could not determine the latest Vulkan-Headers tag; "
                "${VULKAN_RELEASE_TAG_ERROR}")
        endif()
    else()
        message(WARNING
            "Git was not found; continuing with local and hardcoded fallbacks.")
    endif()
endif()

if(VULKAN_REGISTRY_VERSION STREQUAL "" AND EXISTS ${GENERATED_VERSION_FILE})
    file(READ "${GENERATED_VERSION_FILE}" GENERATED_VULKAN_VERSION)
    string(STRIP "${GENERATED_VULKAN_VERSION}" GENERATED_VULKAN_VERSION)
    set(VULKAN_REGISTRY_VERSION ${GENERATED_VULKAN_VERSION})
    message(STATUS "Using last compilation Vulkan-Header tag: ${VULKAN_REGISTRY_VERSION}")
endif()

if(VULKAN_REGISTRY_VERSION STREQUAL "")
    set(VULKAN_REGISTRY_VERSION "1.4.362")
    message(STATUS "Using hardcoded Vulkan-Header tag: ${VULKAN_REGISTRY_VERSION}")
endif()

set(VK_CACHE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.vk_cache/${VULKAN_REGISTRY_VERSION}")

file(MAKE_DIRECTORY "${VK_CACHE_DIR}")

function(get_vk_headers_source OUT_VAR)
    set(_cache_marker "${VK_CACHE_DIR}/.cpm_fetched")

    if(EXISTS "${_cache_marker}")
        file(READ "${_cache_marker}" _cached_path)

        string(STRIP "${_cached_path}" _cached_path)

        if(EXISTS "${_cached_path}")
            set("${OUT_VAR}" "${_cached_path}" PARENT_SCOPE)

            message(STATUS "Using cached Vulkan-Headers from: ${_cached_path}")

            return()
        endif()
    endif()

    CPMAddPackage(
        NAME VulkanHeaders
        GITHUB_REPOSITORY KhronosGroup/Vulkan-Headers
        GIT_TAG v${VULKAN_REGISTRY_VERSION}
        GIT_SHALLOW TRUE
        DOWNLOAD_ONLY ON
    )

    if(NOT VulkanHeaders_ADDED)
        message(FATAL_ERROR "Failed to fetch Vulkan-Headers")
    endif()

    file(WRITE "${_cache_marker}" "${VulkanHeaders_SOURCE_DIR}")

    set("${OUT_VAR}" "${VulkanHeaders_SOURCE_DIR}" PARENT_SCOPE)
endfunction()


get_vk_headers_source(VK_HEADERS_SOURCE_DIR)


set(VULKAN_PRIVATE_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/vulkan/include")


function(copy_vk_header_tree RELATIVE_DIR)
    file(
        GLOB_RECURSE
        _vk_headers
        CONFIGURE_DEPENDS
        LIST_DIRECTORIES false
        "${VK_HEADERS_SOURCE_DIR}/include/${RELATIVE_DIR}/*.h"
    )

    if(NOT _vk_headers)
        message(FATAL_ERROR
            "No Vulkan headers found in: "
            "${VK_HEADERS_SOURCE_DIR}/include/${RELATIVE_DIR}"
        )
    endif()

    foreach(_source_header IN LISTS _vk_headers)
        file(RELATIVE_PATH _relative_header "${VK_HEADERS_SOURCE_DIR}/include" "${_source_header}")

        set(_destination_header "${VULKAN_PRIVATE_INCLUDE_DIR}/${_relative_header}")

        get_filename_component(_destination_dir "${_destination_header}" DIRECTORY)

        file(MAKE_DIRECTORY "${_destination_dir}")

        configure_file("${_source_header}" "${_destination_header}" COPYONLY)
    endforeach()
endfunction()


copy_vk_header_tree("vulkan")
copy_vk_header_tree("vk_video")


add_library(VkBindingsVulkan INTERFACE)

add_library(VkBindings::Vulkan ALIAS VkBindingsVulkan)

target_include_directories(VkBindingsVulkan
    INTERFACE
        "${VULKAN_PRIVATE_INCLUDE_DIR}"
)


set(VK_XML_FILE "${CMAKE_CURRENT_BINARY_DIR}/vk.xml")
set(VIDEO_XML_FILE "${CMAKE_CURRENT_BINARY_DIR}/video.xml")

set(VK_PLATFORM_FILE_BINDINGS "${CMAKE_CURRENT_SOURCE_DIR}/bindings/include/VkBindings/private/vk_platform.h")

function(copy_from_vk_headers SRC_RELATIVE DEST)
    get_filename_component(_dest_dir "${DEST}" DIRECTORY)

    file(MAKE_DIRECTORY "${_dest_dir}")

    set(_src "${VK_HEADERS_SOURCE_DIR}/${SRC_RELATIVE}")

    if(NOT EXISTS "${_src}")
        message(FATAL_ERROR "Source file not found in Vulkan-Headers: ${_src}")
    endif()

    file(COPY "${_src}" DESTINATION "${_dest_dir}")

    if(NOT EXISTS "${DEST}")
        message(FATAL_ERROR "Failed to copy from Vulkan-Headers: ${_src} to ${DEST}")
    endif()
endfunction()


copy_from_vk_headers("registry/vk.xml" "${VK_XML_FILE}")
copy_from_vk_headers("registry/video.xml" "${VIDEO_XML_FILE}")

copy_from_vk_headers("include/vulkan/vk_platform.h" "${VK_PLATFORM_FILE_BINDINGS}")

file(MAKE_DIRECTORY "${VALIDATION_VULKAN_DIR}")


set(NEED_REGENERATION OFF)

if(NOT EXISTS "${GENERATED_VERSION_FILE}")
    message(STATUS "Generated Vulkan bindings have no version marker; regeneration required")

    set(NEED_REGENERATION ON)
else()
    file(READ "${GENERATED_VERSION_FILE}" GENERATED_VULKAN_VERSION)

    string(STRIP "${GENERATED_VULKAN_VERSION}" GENERATED_VULKAN_VERSION)

    if(NOT GENERATED_VULKAN_VERSION STREQUAL VULKAN_REGISTRY_VERSION)
        message(STATUS "Vulkan binding version changed: " "${GENERATED_VULKAN_VERSION} -> ${VULKAN_REGISTRY_VERSION}")

        set(NEED_REGENERATION ON)
    endif()
endif()

if(NOT NEED_REGENERATION)
    foreach(GENERATED_FILE IN LISTS GENERATED_HEADERS)
        if(NOT EXISTS "${GENERATED_FILE}")
            message(STATUS "Missing generated header: ${GENERATED_FILE}")
            set(NEED_REGENERATION ON)
            break()
        endif()
    endforeach()
endif()

if(NOT NEED_REGENERATION)
    foreach(GENERATED_FILE IN LISTS GENERATED_SRCS)
        if(NOT EXISTS "${GENERATED_FILE}")
            message(STATUS "Missing generated source: ${GENERATED_FILE}")
            set(NEED_REGENERATION ON)
            break()
        endif()
    endforeach()
endif()

if(NOT NEED_REGENERATION)
    foreach(GENERATED_FILE IN LISTS VALIDATION_SRCS)
        if(NOT EXISTS "${GENERATED_FILE}")
            message(STATUS "Missing generated validation source: ${GENERATED_FILE}")
            set(NEED_REGENERATION ON)
            break()
        endif()
    endforeach()
endif()

if(PROJECT_IS_TOP_LEVEL)
    set(NEED_REGENERATION ON)
endif()

file(GLOB_RECURSE GENERATOR_SRCS
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/generator/src/*.cpp"
)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Werror -Wall -Wextra -Wpedantic -Wno-missing-field-initializers)
endif()

if(MSVC)
    set(NO_DEPRECATED_DECLARATIONS "/wd4996")
else()
    set(NO_DEPRECATED_DECLARATIONS "-Wno-deprecated-declarations")
endif()

set_source_files_properties(
    "${CMAKE_CURRENT_SOURCE_DIR}/generated/validation/StructsCorrectAsserts.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/generated/validation/EnumsCorrectAsserts.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/generated/src/EnumToString.cpp"
    PROPERTIES
        COMPILE_OPTIONS "${NO_DEPRECATED_DECLARATIONS}"
)


if(NEED_REGENERATION)
# GENERATOR
    CPMAddPackage("gh:leethomason/tinyxml2#11.0.0")

    add_executable(BindingsGenerator EXCLUDE_FROM_ALL ${GENERATOR_SRCS})

    target_compile_features(BindingsGenerator PRIVATE cxx_std_23)

    target_include_directories(BindingsGenerator
        PRIVATE
            "${CMAKE_CURRENT_SOURCE_DIR}/generator/include"
    )

    target_link_libraries(BindingsGenerator PRIVATE tinyxml2)

    set(GENERATION_DEPS
        $<TARGET_FILE:BindingsGenerator>
        ${GENERATOR_SRCS}
    )

    if(NEED_REGENERATION)
        file(TOUCH "${GENERATION_TRIGGER_FILE}")
        list(APPEND GENERATION_DEPS "${GENERATION_TRIGGER_FILE}")
    endif()

    add_custom_command(
        OUTPUT ${GENERATED_HEADERS} ${GENERATED_SRCS} ${VALIDATION_SRCS} ${GENERATED_VERSION_FILE}
        COMMAND $<TARGET_FILE:BindingsGenerator> "${CMAKE_CURRENT_BINARY_DIR}" "${GENERATED_DIR}"
        COMMAND ${CMAKE_COMMAND} -E echo "${VULKAN_REGISTRY_VERSION}" > "${GENERATED_VERSION_FILE}"
        DEPENDS ${GENERATION_DEPS}
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Generating Vulkan binding files"
        VERBATIM
    )

    add_custom_target(
        InvokeBindingsGenerator
        DEPENDS
            ${GENERATED_HEADERS}
            ${GENERATED_SRCS}
            ${VALIDATION_SRCS}
            ${GENERATED_VERSION_FILE}
    )
endif()

# Generated files
add_custom_target(VkBindingsGenerated)

if(NEED_REGENERATION)
    add_dependencies(
        VkBindingsGenerated
        InvokeBindingsGenerator
    )
endif()


# Validation
add_library(Validation STATIC
    ${VALIDATION_SRCS}
)

target_include_directories(Validation
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/bindings/include"
        "${GENERATED_DIR}/include"
)

target_link_libraries(
    Validation
    PRIVATE
        VkBindings::Vulkan
)

if(NEED_REGENERATION)
    add_dependencies(
        Validation
        InvokeBindingsGenerator
    )
endif()

file(GLOB_RECURSE BINDINGS_STATIC_SRCS
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/bindings/src/*.cpp"
)

add_library(VkBindings STATIC
    ${BINDINGS_SRCS}
    ${GENERATED_SRCS}
    ${BINDINGS_STATIC_SRCS}
)

target_include_directories(VkBindings
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/bindings/include"
        "${GENERATED_DIR}/include"
)

add_library(VkBindingsAndValidation INTERFACE)
add_library(VkBindings::Library ALIAS VkBindingsAndValidation)

target_link_libraries(VkBindingsAndValidation
    INTERFACE
        Validation
        VkBindings
)

add_library(VkBindingsHeaders INTERFACE)

target_include_directories(VkBindingsHeaders
    INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/bindings/include"
        "${GENERATED_DIR}/include"
)

add_library(VkBindings::Headers ALIAS VkBindingsHeaders)

add_dependencies(
    VkBindingsHeaders
    VkBindingsGenerated
)
