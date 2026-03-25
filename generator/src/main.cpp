#include <cstdlib>
#include <filesystem>

#include <iostream>
#include <tinyxml2.h>

#include "Writing.hpp"

int main(int argc, char **argv) {
    if (argc != 3) {
        return EXIT_FAILURE;
    }
    std::filesystem::path xml = argv[1];
    std::filesystem::path genDir = argv[2];
    std::cout << "xml: " << xml.string() << "\n";
    std::cout << "genDir: " << genDir.string() << "\n";
    std::filesystem::path genInclude = genDir / "include" / "VkBindings";
    std::filesystem::path genSrc = genDir / "src";
    std::filesystem::create_directories(genInclude);
    std::filesystem::create_directories(genSrc);

    if (!std::filesystem::exists(xml)) {
        std::cerr << "xml does not exitst!\n";
        return EXIT_FAILURE;
    }

    tinyxml2::XMLDocument doc;
    doc.LoadFile(xml.string().c_str());

    tinyxml2::XMLElement &registry = *doc.RootElement();

    writeFiles(
        genSrc, genInclude, registry,
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
        });
}
