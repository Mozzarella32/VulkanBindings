#pragma once

#include <cstdint>
#include <functional>
#include <tinyxml2.h>

struct Registry {
  public:
    struct ConstructorArgs {
        std::reference_wrapper<tinyxml2::XMLElement> vkRef;
        std::reference_wrapper<tinyxml2::XMLElement> videoRef;
    };

  private:
    std::reference_wrapper<tinyxml2::XMLElement> vkRef;
    std::reference_wrapper<tinyxml2::XMLElement> videoRef;

    enum class Active : std::uint8_t {
        unset,
        vk,
        video,
    } active;

    Registry(ConstructorArgs args, Active active);

  public:
    Registry(ConstructorArgs args);

    auto getVk() -> tinyxml2::XMLElement &;
    auto getVideo() -> tinyxml2::XMLElement &;

    auto getActive() -> tinyxml2::XMLElement &;

    auto setVkActive() -> Registry;

    auto setVideoActive() -> Registry;
};
