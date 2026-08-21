#pragma once

// NOLINTBEGIN(cppcoreguidelines-macro-usage, cppcoreguidelines-macro-to-enum ,modernize-macro-to-enum, bugprone-macro-parentheses)
#define VK_BINDINGS_MAKE_VERSION(major, minor, patch) \
    ((((uint32_t)(major)) << 22U) | (((uint32_t)(minor)) << 12U) | ((uint32_t)(patch)))
#define VK_BINDINGS_VERSION_MAJOR(version) ((uint32_t)(version) >> 22U)
#define VK_BINDINGS_VERSION_MINOR(version) (((uint32_t)(version) >> 12U) & 0x3FFU)
#define VK_BINDINGS_VERSION_PATCH(version) ((uint32_t)(version) & 0xFFFU)
#define VK_BINDINGS_MAKE_API_VERSION(variant, major, minor, patch) \
    ((((uint32_t)(variant)) << 29U) | (((uint32_t)(major)) << 22U) | (((uint32_t)(minor)) << 12U) | ((uint32_t)(patch)))
#define VK_BINDINGS_API_VERSION_VARIANT(version) ((uint32_t)(version) >> 29U)
#define VK_BINDINGS_API_VERSION_MAJOR(version) (((uint32_t)(version) >> 22U) & 0x7FU)
#define VK_BINDINGS_API_VERSION_MINOR(version) (((uint32_t)(version) >> 12U) & 0x3FFU)
#define VK_BINDINGS_API_VERSION_PATCH(version) ((uint32_t)(version) & 0xFFFU)
#define VKSC_BINDINGS_API_VARIANT  1
#define VK_BINDINGS_API_VERSION VK_BINDINGS_MAKE_API_VERSION(0, 1, 0, 0) // Patch version should always be set to 0
#define VK_BINDINGS_API_VERSION_1_0 VK_BINDINGS_MAKE_API_VERSION(0, 1, 0, 0)// Patch version should always be set to 0
#define VK_BINDINGS_API_VERSION_1_1 VK_BINDINGS_MAKE_API_VERSION(0, 1, 1, 0)// Patch version should always be set to 0
#define VK_BINDINGS_API_VERSION_1_2 VK_BINDINGS_MAKE_API_VERSION(0, 1, 2, 0)// Patch version should always be set to 0
#define VK_BINDINGS_API_VERSION_1_3 VK_BINDINGS_MAKE_API_VERSION(0, 1, 3, 0)// Patch version should always be set to 0
#define VK_BINDINGS_API_VERSION_1_4 VK_BINDINGS_MAKE_API_VERSION(0, 1, 4, 0)// Patch version should always be set to 0
#define VKSC_BINDINGS_API_VERSION_1_0 VK_BINDINGS_MAKE_API_VERSION(VKSC_BINDINGS_API_VARIANT, 1, 0, 0)// Patch version should always be set to 0
#define VK_BINDINGS_HEADER_VERSION  360
#define VK_BINDINGS_HEADER_VERSION_COMPLETE VK_BINDINGS_MAKE_API_VERSION(0, 1, 4, VK_BINDINGS_HEADER_VERSION)
#define VK_BINDINGS_DEFINE_HANDLE(object) typedef struct object##_T* object;

#ifndef VK_BINDINGS_USE_64_BIT_PTR_DEFINES
    #if defined(__LP64__) || defined(_WIN64) || (defined(__x86_64__) && !defined(__ILP32__) ) || defined(_M_X64) || defined(__ia64) || defined (_M_IA64) || defined(__aarch64__) || defined(__powerpc64__) || (defined(__riscv) && __riscv_xlen == 64)
        #define VK_BINDINGS_USE_64_BIT_PTR_DEFINES 1
    #else
        #define VK_BINDINGS_USE_64_BIT_PTR_DEFINES 0
    #endif
#endif

#ifndef VK_BINDINGS_DEFINE_NON_DISPATCHABLE_HANDLE
    #if (VK_BINDINGS_USE_64_BIT_PTR_DEFINES==1)
        #if (defined(__cplusplus) && (__cplusplus >= 201103L)) || (defined(_MSVC_LANG) && (_MSVC_LANG >= 201103L))
            #define VK_BINDINGS_NULL_HANDLE nullptr
        #else
            #define VK_BINDINGS_NULL_HANDLE ((void*)0)
        #endif
    #else
        #define VK_BINDINGS_NULL_HANDLE 0ULL
    #endif
#endif
#ifndef VK_BINDINGS_NULL_HANDLE
    #define VK_BINDINGS_NULL_HANDLE 0
#endif

#ifndef VK_BINDINGS_DEFINE_NON_DISPATCHABLE_HANDLE
    #if (VK_BINDINGS_USE_64_BIT_PTR_DEFINES==1)
        #define VK_BINDINGS_DEFINE_NON_DISPATCHABLE_HANDLE(object) typedef struct object##_T *object;
    #else
        #define VK_BINDINGS_DEFINE_NON_DISPATCHABLE_HANDLE(object) typedef uint64_t object;
    #endif
#endif

#define VK_BINDINGS_MAKE_VIDEO_STD_VERSION(major, minor, patch) \
    ((((uint32_t)(major)) << 22) | (((uint32_t)(minor)) << 12) | ((uint32_t)(patch)))
#define VK_BINDINGS_STD_VULKAN_VIDEO_CODEC_H264_DECODE_API_VERSION_1_0_0 VK_BINDINGS_MAKE_VIDEO_STD_VERSION(1, 0, 0)
#define VK_BINDINGS_STD_VULKAN_VIDEO_CODEC_H264_ENCODE_API_VERSION_1_0_0 VK_BINDINGS_MAKE_VIDEO_STD_VERSION(1, 0, 0)
#define VK_BINDINGS_STD_VULKAN_VIDEO_CODEC_H265_DECODE_API_VERSION_1_0_0 VK_BINDINGS_MAKE_VIDEO_STD_VERSION(1, 0, 0)
#define VK_BINDINGS_STD_VULKAN_VIDEO_CODEC_H265_ENCODE_API_VERSION_1_0_0 VK_BINDINGS_MAKE_VIDEO_STD_VERSION(1, 0, 0)
#define VK_BINDINGS_STD_VULKAN_VIDEO_CODEC_VP9_DECODE_API_VERSION_1_0_0 VK_BINDINGS_MAKE_VIDEO_STD_VERSION(1, 0, 0)
#define VK_BINDINGS_STD_VULKAN_VIDEO_CODEC_AV1_DECODE_API_VERSION_1_0_0 VK_BINDINGS_MAKE_VIDEO_STD_VERSION(1, 0, 0)
#define VK_BINDINGS_STD_VULKAN_VIDEO_CODEC_AV1_ENCODE_API_VERSION_1_0_0 VK_BINDINGS_MAKE_VIDEO_STD_VERSION(1, 0, 0)

// NOLINTEND(cppcoreguidelines-macro-usage, cppcoreguidelines-macro-to-enum ,modernize-macro-to-enum, bugprone-macro-parentheses)
