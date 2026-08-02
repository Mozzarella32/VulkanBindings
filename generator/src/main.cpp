#include "ParseXml.hpp"
#include "Writing.hpp"

#include <cstdlib>
#include <filesystem>

#include <iostream>
#include <tinyxml2.h>

auto main(int argc, char **argv) -> int {
    if (argc != 3) {
        return EXIT_FAILURE;
    }
    std::filesystem::path xmlDir = argv[1];
    std::filesystem::path genDir = argv[2];
    std::filesystem::path vkXmlPath = xmlDir / "vk.xml";
    std::filesystem::path videoXmlPath = xmlDir / "video.xml";
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
    vkXml = &vkRegistry;
    videoXml = &videoRegistry;

    initStatics(vkRegistry);

    writeFiles(genDir, vkRegistry, videoRegistry,
               {
                   writeHandles,
                   writeObjects,
                   writeObjectReflections,
                   writeConstants,
                   writeEnums,
                   writeStructs,
                   writeDefines,
                   writeFunctionPtrs,
                   writeBaseTypes,
                   writeFunctionTables,
               });
}
