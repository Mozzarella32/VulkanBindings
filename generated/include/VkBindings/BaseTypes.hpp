#pragma once

#include <cstdint>

namespace VkBindings {
using Bool32 = uint32_t;
using DeviceAddress = uint64_t;
using DeviceSize = uint64_t;
using Flags = uint32_t;
using Flags64 = uint64_t;
using RemoteAddressNV = void*;
using SampleMask = uint32_t;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
	struct AHardwareBuffer;
	struct ANativeWindow;
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_METAL_EXT
	#ifdef __OBJC__
	@class CAMetalLayer;
	#else
	typedef void CAMetalLayer;
	#endif
	using IOSurfaceRef = struct __IOSurface*;
	#ifdef __OBJC__
	@protocol MTLBuffer;
	typedef __unsafe_unretained id<MTLBuffer> MTLBuffer_id;
	#else
	typedef void* MTLBuffer_id;
	#endif
	#ifdef __OBJC__
	@protocol MTLCommandQueue;
	typedef __unsafe_unretained id<MTLCommandQueue> MTLCommandQueue_id;
	#else
	typedef void* MTLCommandQueue_id;
	#endif
	#ifdef __OBJC__
	@protocol MTLDevice;
	typedef __unsafe_unretained id<MTLDevice> MTLDevice_id;
	#else
	typedef void* MTLDevice_id;
	#endif
	#ifdef __OBJC__
	@protocol MTLSharedEvent;
	typedef __unsafe_unretained id<MTLSharedEvent> MTLSharedEvent_id;
	#else
	typedef void* MTLSharedEvent_id;
	#endif
	#ifdef __OBJC__
	@protocol MTLTexture;
	typedef __unsafe_unretained id<MTLTexture> MTLTexture_id;
	#else
	typedef void* MTLTexture_id;
	#endif
#endif // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_OHOS
	using OHNativeWindow = struct NativeWindow;
	struct OH_NativeBuffer;
#endif // VK_USE_PLATFORM_OHOS
} // namespace VkBindings
