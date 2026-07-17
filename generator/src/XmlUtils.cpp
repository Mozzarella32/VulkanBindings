#include "XmlUtils.hpp"

#include <algorithm>
#include <iostream>
#include <ranges>
#include <stdexcept>

using std::string;

using namespace tinyxml2;

auto FirstChildElement(XMLElement &element, const std::string &elementValue) -> XMLElement & {
    XMLElement *elem = element.FirstChildElement(elementValue.c_str());
    if (!elem) {
        std::cerr << "failed to find: " << elementValue << "\n";
        Print(element);
        throw std::runtime_error{"failed to find: " + elementValue};
    }
    return *elem;
}

void ForEachBreak(XMLElement &elem, const std::string &elementValue,
                  std::function<bool(XMLElement &)> fun) {
    for (XMLElement *elems = elem.FirstChildElement(elementValue.c_str()); elems;
         elems = elems->NextSiblingElement(elementValue.c_str())) {
        if (fun(*elems))
            break;
    }
}

void ForEach(XMLElement &elem, const std::string &elementValue,
             std::function<void(XMLElement &)> fun) {
    for (XMLElement *elems = elem.FirstChildElement(elementValue.c_str()); elems;
         elems = elems->NextSiblingElement(elementValue.c_str())) {
        fun(*elems);
    }
}

void Print [[maybe_unused]] (XMLElement &elem) {
    XMLPrinter p;
    elem.Accept(&p);
    std::cout << p.CStr() << "\n" << std::flush;
}

auto HasAttributeValue(XMLElement &elem, const std::string &name, const std::string &value)
    -> bool {
    const char *attrib = elem.Attribute(name.c_str());
    if (attrib == nullptr)
        return false;
    return std::string_view(attrib) == value;
}
auto HasAttribute(XMLElement &elem, const std::string &name) -> bool {
    const char *attrib = elem.Attribute(name.c_str());
    return attrib != nullptr;
}

auto Attribute(XMLElement &elem, const std::string &name) -> std::string {
    return elem.Attribute(name.c_str());
}

auto HasText(XMLElement &elem, const std::string &value) -> bool {
    const char *text = elem.GetText();
    if (text == nullptr)
        return false;
    return std::string_view(text) == value;
}

auto trim_copy(std::string s) -> std::string {
    auto not_space = [](unsigned char c) -> bool { return !std::isspace(c); };
    s.erase(s.begin(), std::ranges::find_if(s, not_space));
    s.erase(std::ranges::find_if(std::views::reverse(s), not_space).base(), s.end());
    return s;
}

auto splitCSL(const std::string &s) -> std::unordered_set<std::string> {
    return s | std::views::split(',') | std::ranges::to<std::unordered_set<std::string>>();
}

auto checkApi(XMLElement &elem) -> bool {
    return !HasAttribute(elem, "api") || splitCSL(Attribute(elem, "api")).contains("vulkan");
}
