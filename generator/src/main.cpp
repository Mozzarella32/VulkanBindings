#include "Registry.hpp"
#include "Writing.hpp"

#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <functional>
#include <iostream>
#include <span>
#include <vector>

#include <tinyxml2.h>

auto main(int argc, char **argv) -> int {
    if (argc != 3) {
        return EXIT_FAILURE;
    }

    const std::span<char *> args{argv, static_cast<std::size_t>(argc)};

    const std::filesystem::path xmlDir = args[1];
    const std::filesystem::path genDir = args[2];
    const std::filesystem::path vkXmlPath = xmlDir / "vk.xml";
    const std::filesystem::path videoXmlPath = xmlDir / "video.xml";
    std::cout << "vk.xml: " << vkXmlPath.string() << "\n";
    std::cout << "video.xml: " << videoXmlPath.string() << "\n";
    std::cout << "genDir: " << genDir.string() << "\n";

    if (!std::filesystem::exists(vkXmlPath)) {
        std::cerr << "xml does not exitst!\n";
        return EXIT_FAILURE;
    }

    if (!std::filesystem::exists(videoXmlPath)) {
        std::cerr << "xml does not exitst!\n";
        return EXIT_FAILURE;
    }

    tinyxml2::XMLDocument vkDoc;
    vkDoc.LoadFile(vkXmlPath.string().c_str());
    tinyxml2::XMLElement &vkRegistry = *vkDoc.RootElement();
    tinyxml2::XMLDocument videoDoc;
    videoDoc.LoadFile(videoXmlPath.string().c_str());
    tinyxml2::XMLElement &videoRegistry = *videoDoc.RootElement();

    initStatics(Registry::ConstructorArgs{.vkRef = vkRegistry, .videoRef = videoRegistry});

    const std::vector<std::function<void(WriteCtx &)>> functions = {
        writeHandles, writeObjects, writeObjectReflections, writeConstants, writeEnums,
        writeStructs, writeDefines, writeFunctionPtrs,      writeBaseTypes, writeFunctionTables,
    };

    auto registry = Registry::ConstructorArgs{.vkRef = vkRegistry, .videoRef = videoRegistry};

    writeFiles(genDir, registry, functions);
}
