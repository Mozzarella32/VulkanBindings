#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <concepts>
#include <filesystem>
#include <functional>
#include <ranges>
#include <set>

#include <tinyxml2.h>

template <typename T, typename F>
    requires requires(const T &t, std::ostream &o, CppGenerator &gen, F print) {
        { t.depends } -> std::same_as<const Depends &>;
        print(gen, std::declval<T>());
    }
void writeDepends(CppGenerator &gen, const std::set<T> &set, F print, bool reversed = false) {
    Depends currendDepends;

    auto close_platform_if_open = [&]() {
        if (!currendDepends.platform.empty()) {
            gen.doMakroEndif();
            currendDepends.platform.clear();
        }
    };
    auto close_depends_if_open = [&]() {
        if (!currendDepends.guard.empty()) {
            gen.doMakroEndif();
            currendDepends.guard = "";
        }
    };
    auto close_namespace_if_open = [&]() {
        if (!currendDepends.m_namespace.empty()) {
            gen.doEndNamespace();
            currendDepends.m_namespace.clear();
        }
    };

    auto processElement = [&](const T &t) {
        if (t.depends.m_namespace != currendDepends.m_namespace) {
            close_depends_if_open();
            close_platform_if_open();
            close_namespace_if_open();
            if (!t.depends.m_namespace.empty()) {
                gen.doBeginNamespace(t.depends.m_namespace);
                currendDepends.m_namespace = t.depends.m_namespace;
            }
        }

        if (t.depends.platform != currendDepends.platform) {
            close_depends_if_open();
            close_platform_if_open();
            if (!t.depends.platform.empty()) {
                gen.doMakroIfdef(t.depends.platform);
                currendDepends.platform = t.depends.platform;
            }
        }

        if (t.depends.guard != currendDepends.guard) {
            close_depends_if_open();

            if (t.depends.guard != "") {
                gen.doMakroIf(t.depends.guard);
                currendDepends.guard = t.depends.guard;
            }
        }

        print(gen, t);
    };

    if (!reversed) {
        for (const T &t : set) {
            processElement(t);
        }
    } else {
        for (const T &t : set | std::views::reverse) {
            processElement(t);
        }
    }

    close_depends_if_open();
    close_platform_if_open();
    close_namespace_if_open();
}

extern void writeTypeInfos(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                           const std::filesystem::path &genInclude);

extern void writeObjects(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                         const std::filesystem::path &genInclude);

extern void writeObjectTypes(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                             const std::filesystem::path &genInclude);

extern void writeConstants(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                           const std::filesystem::path &genInclude);

extern void writeEnums(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                       const std::filesystem::path &genInclude);

extern void writeStructs(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                         const std::filesystem::path &genInclude);

extern void
writeFiles(const std::filesystem::path &genSrc, std::filesystem::path &genInclude,
           tinyxml2::XMLElement &registry,
           const std::vector<
               std::tuple<std::vector<std::string>,
                          std::function<void(tinyxml2::XMLElement &, const std::filesystem::path &,
                                             const std::filesystem::path &)>>> &functions);
