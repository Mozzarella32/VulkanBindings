#include <cstdlib>
#include <filesystem>

#include <iostream>
#include <tinyxml2.h>

#include "ParseXml.hpp"
#include "Writing.hpp"

int main(int argc, char **argv) {
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
    std::filesystem::path genInclude = genDir / "include" / "VkBindings";
    std::filesystem::path genSrc = genDir / "src";
    std::filesystem::create_directories(genInclude);
    std::filesystem::create_directories(genSrc);

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

    writeFiles(
        genSrc, genInclude, vkRegistry, videoRegistry,
        {
            {{"Objects_Forward.hpp", "Objects.hpp", "Objects.cpp", "Instance.cpp",
              "PhysicalDevice.cpp", "Device.cpp", "CommandBuffer.cpp"},
             writeObjects},
            {{"ObjectRelfections.hpp", "ObjectRelfections.cpp"}, writeObjectReflections},
            {{"Constants.hpp"}, writeConstants},
            {{"Enums.hpp", "EnumsCorrectAsserts.cpp", "EnumToString.cpp", "BitmaskToString.cpp"},
             writeEnums},
            {{"Structs.hpp", "Structs.cpp", "StructsCorrectAsserts.cpp"}, writeStructs},
            {{"Defines.hpp"}, writeDefines},
            {{"FunctionPtrs.hpp"}, writeFunctionPtrs},
            {{"BaseTypes.hpp"}, writeBaseTypes},
        });
}
