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

auto FirstChildElement(XMLElement &element, const std::string &elementValue) -> XMLElement & {
    XMLElement *elem = element.FirstChildElement(elementValue.c_str());
    if (elem == nullptr) {
        std::cerr << "failed to find: " << elementValue << "\n";
        Print(element);
        throw std::runtime_error{"failed to find: " + elementValue};
    }
    return *elem;
}

void ForEachBreak(XMLElement &elem, const std::string &elementValue,
                  const std::function<bool(XMLElement &)> &fun) {
    for (XMLElement *elems = elem.FirstChildElement(elementValue.c_str()); elems != nullptr;
         elems = elems->NextSiblingElement(elementValue.c_str())) {
        if (fun(*elems)) {
            break;
        }
    }
}

void ForEach(XMLElement &elem, const std::string &elementValue,
             const std::function<void(XMLElement &)> &fun) {
    for (XMLElement *elems = elem.FirstChildElement(elementValue.c_str()); elems != nullptr;
         elems = elems->NextSiblingElement(elementValue.c_str())) {
        fun(*elems);
    }
}

void Print [[maybe_unused]] (XMLElement &elem) {
    XMLPrinter printer;
    elem.Accept(&printer);
    std::cout << printer.CStr() << "\n" << std::flush;
}

auto HasAttributeValue(XMLElement &elem, AttributeName name, AttributeValue value) -> bool {
    const char *attrib = elem.Attribute(name.value);
    if (attrib == nullptr) {
        return false;
    }
    return std::string_view(attrib) == value.value;
}

auto HasAttribute(XMLElement &elem, const std::string &name) -> bool {
    const char *attrib = elem.Attribute(name.c_str());
    return attrib != nullptr;
}

auto Attribute(XMLElement &elem, const std::string &name) -> std::string {
    return elem.Attribute(name.c_str());
}

auto HasText(XMLElement &elem, std::string_view value) -> bool {
    const char *text = elem.GetText();
    if (text == nullptr) {
        return false;
    }
    return std::string_view(text) == value;
}

auto trim_copy(std::string string) -> std::string {
    auto not_space = [](unsigned char character) -> bool { return !std::isspace(character); };
    string.erase(string.begin(), std::ranges::find_if(string, not_space));
    string.erase(std::ranges::find_if(std::views::reverse(string), not_space).base(), string.end());
    return string;
}

auto checkApi(XMLElement &elem) -> bool {
    return !HasAttribute(elem, "api") || splitCSL(Attribute(elem, "api")).contains("vulkan");
}
