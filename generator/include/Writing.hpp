#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <concepts>
#include <filesystem>
#include <functional>
#include <ranges>
#include <set>

#include <tinyxml2.h>

template <typename T, typename MemFn>
    requires requires(const T &t, CppGenerator &gen, MemFn m) {
        { t.depends } -> std::same_as<const Depends &>;
        { std::invoke(m, t, gen) };
    }
void writeDepends(CppGenerator &gen, const std::set<T> &set, MemFn print, bool reversed = false) {
    Depends currendDepends;

    auto close_platform_if_open = [&]() -> auto {
        if (!currendDepends.platform.empty()) {
            gen.doMakroEndif();
            currendDepends.platform.clear();
        }
    };
    auto close_depends_if_open = [&]() -> auto {
        if (!currendDepends.guard.empty()) {
            gen.doMakroEndif();
            currendDepends.guard = "";
        }
    };
    auto close_namespace_if_open = [&]() -> auto {
        if (!currendDepends.m_namespace.empty()) {
            gen.doEndNamespace();
            currendDepends.m_namespace.clear();
        }
    };

    auto processElement = [&](const T &t) -> auto {
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

            if (!t.depends.guard.empty()) {
                gen.doMakroIf(t.depends.guard);
                currendDepends.guard = t.depends.guard;
            }
        }

        std::invoke(print, t, gen);
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

extern void writeObjects(tinyxml2::XMLElement &vkRegistry, tinyxml2::XMLElement &videoRegistry,
                         const std::filesystem::path &genDir);

extern void writeHandles(tinyxml2::XMLElement &vkRegistry, tinyxml2::XMLElement &videoRegistry,
                         const std::filesystem::path &genDir);

extern void writeObjectReflections(tinyxml2::XMLElement &vkRegistry,
                                   tinyxml2::XMLElement &videoRegistry,
                                   const std::filesystem::path &genDir);

extern void writeConstants(tinyxml2::XMLElement &vkRegistry, tinyxml2::XMLElement &videoRegistry,
                           const std::filesystem::path &genDir);

extern void writeEnums(tinyxml2::XMLElement &vkRegistry, tinyxml2::XMLElement &videoRegistry,
                       const std::filesystem::path &genDir);

extern void writeStructs(tinyxml2::XMLElement &vkRegistry, tinyxml2::XMLElement &videoRegistry,
                         const std::filesystem::path &genDir);

extern void writeDefines(tinyxml2::XMLElement &vkRegistry, tinyxml2::XMLElement &videoRegistry,
                         const std::filesystem::path &genDir);

extern void writeFunctionPtrs(tinyxml2::XMLElement &vkRegistry, tinyxml2::XMLElement &videoRegistry,
                              const std::filesystem::path &genDir);

extern void writeBaseTypes(tinyxml2::XMLElement &vkRegistry, tinyxml2::XMLElement &videoRegistry,
                           const std::filesystem::path &genDir);

extern void writeFunctionTables(tinyxml2::XMLElement &vkRegistry,
                                tinyxml2::XMLElement &videoRegistry,
                                const std::filesystem::path &genDir);

extern void initStatics(tinyxml2::XMLElement &vkRegistry);

extern void
writeFiles(const std::filesystem::path &genDir, tinyxml2::XMLElement &vkRegistry,
           tinyxml2::XMLElement &videoRegistry,
           const std::vector<std::function<void(tinyxml2::XMLElement &, tinyxml2::XMLElement &,
                                                const std::filesystem::path &)>> &functions);
