#include "XmlUtils.hpp"

#include <algorithm>
#include <cctype>
#include <functional>
#include <iostream>
#include <ranges>
#include <stdexcept>
#include <string>
#include <string_view>
#include <tinyxml2.h>

using namespace tinyxml2;

void print [[maybe_unused]](const XMLElement &elem) {
    XMLPrinter printer;
    elem.Accept(&printer);
    std::cout << printer.CStr() << "\n" << std::flush;
}

auto firstChildElement(XMLElement &element, const std::string &elementValue) -> XMLElement & {
    XMLElement *elem = element.FirstChildElement(elementValue.c_str());
    if (elem == nullptr) {
        std::cerr << "failed to find: " << elementValue << "\n";
        print(element);
        throw std::runtime_error{"failed to find: " + elementValue};
    }
    return *elem;
}

void forEachBreak(XMLElement &elem, const std::string &elementValue,
                  const std::function<bool(XMLElement &)> &fun) {
    for (XMLElement *elems = elem.FirstChildElement(elementValue.c_str()); elems != nullptr;
         elems = elems->NextSiblingElement(elementValue.c_str())) {
        if (fun(*elems)) {
            break;
        }
    }
}

void forEach(XMLElement &elem, const std::string &elementValue,
             const std::function<void(XMLElement &)> &fun) {
    for (XMLElement *elems = elem.FirstChildElement(elementValue.c_str()); elems != nullptr;
         elems = elems->NextSiblingElement(elementValue.c_str())) {
        fun(*elems);
    }
}

auto hasAttributeValue(const XMLElement &elem, AttributeName name, AttributeValue value) -> bool {
    const char *attrib = elem.Attribute(name.value);
    if (attrib == nullptr) {
        return false;
    }
    return std::string_view(attrib) == value.value;
}

auto hasAttribute(const XMLElement &elem, const std::string &name) -> bool {
    const char *attrib = elem.Attribute(name.c_str());
    return attrib != nullptr;
}

auto attribute(const XMLElement &elem, const std::string &name) -> std::string {
    return elem.Attribute(name.c_str());
}

auto hasText(const XMLElement &elem, std::string_view value) -> bool {
    const char *text = elem.GetText();
    if (text == nullptr) {
        return false;
    }
    return std::string_view(text) == value;
}

auto trimCopy(std::string string) -> std::string {
    const auto notSpace = [](unsigned char character) -> bool { return !std::isspace(character); };
    string.erase(string.begin(), std::ranges::find_if(string, notSpace));
    string.erase(std::ranges::find_if(std::views::reverse(string), notSpace).base(), string.end());
    return string;
}

auto checkApi(const XMLElement &elem) -> bool {
    return !hasAttribute(elem, "api") || splitCSL(attribute(elem, "api")).contains("vulkan");
}
