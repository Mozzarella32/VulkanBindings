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
        if (currendDepends.feature != "" || !currendDepends.extensions.empty()) {
            gen.doMakroEndif();
            currendDepends.feature = "";
            currendDepends.extensions.clear();
        }
    };
    auto close_namespace_if_open = [&]() {
        if (!currendDepends.m_namespace.empty()) {
            gen.doEndNamespace();
            currendDepends.m_namespace.clear();
        }
    };

    auto make_extension_condition = [](const Depends &depends) -> std::string {
        std::string extCond;
        bool firstExt = true;
        for (auto &e : depends.extensions) {
            if (!firstExt)
                extCond += " || ";
            extCond += "defined(" + e + ")";
            firstExt = false;
        }
        if (!extCond.empty()) {
            extCond = "(" + extCond + ")";
        }

        std::string featCond;
        if (!depends.feature.empty()) {
            featCond = "defined(" + depends.feature + ")";
        }

        if (!featCond.empty() && !extCond.empty()) {
            return featCond + " && " + extCond;
        } else if (!featCond.empty()) {
            return featCond;
        } else {
            return extCond;
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

        if (t.depends.feature != currendDepends.feature ||
            t.depends.extensions != currendDepends.extensions) {
            close_depends_if_open();

            if (t.depends.feature != "" || !t.depends.extensions.empty()) {
                gen.doMakroIf(make_extension_condition(t.depends));
                currendDepends.feature = t.depends.feature;
                currendDepends.extensions = t.depends.extensions;
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

extern void writeStructures(tinyxml2::XMLElement &registry,
                            [[maybe_unused]] const std::filesystem::path &genSrc,
                            [[maybe_unused]] const std::filesystem::path &genInclude);

extern void writeObjects(tinyxml2::XMLElement &registry,
                         [[maybe_unused]] const std::filesystem::path &genSrc,
                         [[maybe_unused]] const std::filesystem::path &genInclude);

extern void
writeFiles(const std::filesystem::path &genSrc, std::filesystem::path &genInclude,
           tinyxml2::XMLElement &registry,
           const std::vector<
               std::tuple<std::vector<std::string>,
                          std::function<void(tinyxml2::XMLElement &, const std::filesystem::path &,
                                             const std::filesystem::path &)>>> &functions);
