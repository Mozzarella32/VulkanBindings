#include <cstdlib>
#include <filesystem>

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
    std::filesystem::path genInclude = genDir / "include";
    std::filesystem::path genSrc = genDir / "src";
    std::filesystem::create_directories(genInclude);
    std::filesystem::create_directories(genSrc);

    tinyxml2::XMLDocument doc;
    doc.LoadFile(xml.string().c_str());

    tinyxml2::XMLElement &registry = *doc.RootElement();

    writeFiles(
        genSrc, genInclude, registry,
        {{{"Structures.cpp"}, writeStructures}, {{"Objects.hpp", "Objects.cpp"}, writeObjects}});

    writeStructures(registry, genSrc, genInclude);
}
