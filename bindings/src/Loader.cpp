#include "VkBindings/Loader.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/private/FunctionTables.hpp"
#include "VkBindings/private/Loader.hpp"

namespace VkBindings::Loader {

// This is inspired by volk(https://github.com/zeux/volk) ========

// Copyright (c) 2018-2026 Arseny Kapoulkine

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifdef _WIN32
typedef const char *LPCSTR;
typedef struct HINSTANCE__ *HINSTANCE;
typedef HINSTANCE HMODULE;
#if defined(_MINWINDEF_)
#elif defined(_WIN64)
typedef __int64(__stdcall *FARPROC)(void);
#else
typedef int(__stdcall *FARPROC)(void);
#endif
#else
#include <dlfcn.h>
#endif

#ifdef __APPLE__
#include <stdlib.h>
#endif

#ifdef _WIN32
#ifdef __cplusplus
extern "C" {
#endif
__declspec(dllimport) HMODULE __stdcall LoadLibraryA(LPCSTR);
__declspec(dllimport) FARPROC __stdcall GetProcAddress(HMODULE, LPCSTR);
__declspec(dllimport) int __stdcall FreeLibrary(HMODULE);
#ifdef __cplusplus
}
#endif
#endif

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
auto Init() -> Result {
#ifdef _WIN32
    HMODULE module = LoadLibraryA("vulkan-1.dll");
    if (module == nullptr) {
        return Result::ErrorInitializationFailed;
    }

    impl_Loader::getInstanceProcAddr =
        reinterpret_cast<PFN::GetInstanceProcAddr>(GetProcAddress(module, "vkGetInstanceProcAddr"));
#elifdef __APPLE__
    void *module = dlopen("libvulkan.dylib", RTLD_NOW | RTLD_LOCAL);
    if (module == nullptr) {
        module = dlopen("libvulkan.1.dylib", RTLD_NOW | RTLD_LOCAL);
    }
    if (module == nullptr && getenv("DYLD_FALLBACK_LIBRARY_PATH") == NULL) {
        module = dlopen("/usr/local/lib/libvulkan.dylib", RTLD_NOW | RTLD_LOCAL);
    }
    if (module == nullptr) {
        module = dlopen("libMoltenVK.dylib", RTLD_NOW | RTLD_LOCAL);
    }
    if (module == nullptr) {
        module = dlopen("vulkan.framework/vulkan", RTLD_NOW | RTLD_LOCAL);
    }
    if (module == nullptr) {
        module = dlopen("MoltenVK.framework/MoltenVK", RTLD_NOW | RTLD_LOCAL);
    }
    if (module == nullptr) {
        return Result::ErrorInitializationFailed;
    }

    impl_Loader::getInstanceProcAddr =
        reinterpret_cast<PFN::GetInstanceProcAddr>(dlsym(module, "vkGetInstanceProcAddr"));
#elifdef __ANDROID__
    void *module = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
    if (module == nullptr) {
        module =
            dlopen("libvulkan.so", RTLDac_add_options-- disable - unified - build_NOW | RTLD_LOCAL);
    }
    if (module == nullptr) {
        return Result::eErrorInitializationFailed;
    }
    impl_Loader::getInstanceProcAddr =
        reinterpret_cast<PFN::GetInstanceProcAddr>(dlsym(module, "vkGetInstanceProcAddr"));
#else
    void *module = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL | RTLD_DEEPBIND);
    if (module == nullptr) {
        module = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL | RTLD_DEEPBIND);
    }
    if (module == nullptr) {
        return Result::ErrorInitializationFailed;
    }
    impl_Loader::getInstanceProcAddr =
        reinterpret_cast<PFN::GetInstanceProcAddr>(dlsym(module, "vkGetInstanceProcAddr"));
#endif
    impl_Loader::LoadGlobals();
    return Result::Success;
}
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)

// ===============================================================

auto GetGetInstanceProcAddr() -> PFN::GetInstanceProcAddr {
    return impl_Loader::getInstanceProcAddr;
}

} // namespace VkBindings::Loader
