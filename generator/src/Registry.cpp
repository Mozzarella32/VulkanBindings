#include "Registry.hpp"

#include <cassert>
#include <stdexcept>
#include <tinyxml2.h>
#include <utility>

Registry::Registry(ConstructorArgs args, Active active)
    : vkRef(args.vkRef), videoRef(args.videoRef), active(active) {}
Registry::Registry(ConstructorArgs args) : Registry(args, Active::unset) {}
auto Registry::getVk() -> tinyxml2::XMLElement & { return vkRef.get(); }
auto Registry::getVideo() -> tinyxml2::XMLElement & { return videoRef.get(); }

auto Registry::getActive() -> tinyxml2::XMLElement & {
    switch (active) {
    case Active::vk:
        return getVk();
    case Active::video:
        return getVideo();
    case Active::unset:
        throw std::runtime_error("getActive: active == Active::unset");
    }
    std::unreachable();
}

auto Registry::setVkActive() -> Registry {
    return {ConstructorArgs{.vkRef = vkRef, .videoRef = videoRef}, Active::vk};
}

auto Registry::setVideoActive() -> Registry {
    return {ConstructorArgs{.vkRef = vkRef, .videoRef = videoRef}, Active::video};
}
