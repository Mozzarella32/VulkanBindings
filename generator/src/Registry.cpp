#include "Registry.hpp"

#include <cassert>
#include <tinyxml2.h>

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
        assert(false);
    }
    assert(false);
}

auto Registry::setVkActive() -> Registry {
    return {ConstructorArgs{.vkRef = vkRef, .videoRef = videoRef}, Active::vk};
}

auto Registry::setVideoActive() -> Registry {
    return {ConstructorArgs{.vkRef = vkRef, .videoRef = videoRef}, Active::video};
}
