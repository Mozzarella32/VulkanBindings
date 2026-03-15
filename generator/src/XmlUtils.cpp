#include "XmlUtils.hpp"

#include <iostream>
#include <ranges>

using namespace tinyxml2;

XMLElement &FirstChildElement(XMLElement &element, const std::string &elementValue) {
    XMLElement *elem = element.FirstChildElement(elementValue.c_str());
    if (!elem) {
        std::cerr << "failed to find: " << elementValue << "\n";
        exit(EXIT_FAILURE);
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
    std::cout << p.CStr() << "\n";
}

bool HasAttributeValue(XMLElement &elem, const std::string &name, const std::string &value) {
    const char *attrib = elem.Attribute(name.c_str());
    if (attrib == nullptr)
        return false;
    return std::string_view(attrib) == value;
}
bool HasAttribute(XMLElement &elem, const std::string &name) {
    const char *attrib = elem.Attribute(name.c_str());
    return attrib != nullptr;
}

std::string Attribute(XMLElement &elem, const std::string &name) {
    return std::string(elem.Attribute(name.c_str()));
}

bool HasText(XMLElement &elem, const std::string &value) {
    const char *text = elem.GetText();
    if (text == nullptr)
        return false;
    return std::string_view(text) == value;
}

std::string trim_copy(std::string s) {
    auto not_space = [](unsigned char c) { return !std::isspace(c); };
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), not_space));
    s.erase(std::find_if(s.rbegin(), s.rend(), not_space).base(), s.end());
    return s;
}

std::unordered_set<std::string> splitCSL(const std::string &s) {
    return s | std::views::split(',') | std::ranges::to<std::unordered_set<std::string>>();
}

