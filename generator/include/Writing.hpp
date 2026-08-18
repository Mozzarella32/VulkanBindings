#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"
#include "Registry.hpp"

#include <concepts>
#include <filesystem>
#include <functional>
#include <ranges>
#include <set>
#include <vector>

struct WriteCtx {
    bool firstWrite;
    std::vector<std::filesystem::path> generatedFiles;
    Registry registry;
    std::filesystem::path genDir;
};

extern auto closePlatformIfOpen(CppGenerator &gen, Depends &currendDepends) -> void;
extern auto closeDependsIfOpen(CppGenerator &gen, Depends &currendDepends) -> void;
extern auto closeNamespaceIfOpen(CppGenerator &gen, Depends &currendDepends) -> void;

template <typename T, typename MemFn>
    requires requires(const T &elem, CppGenerator &gen, MemFn print) {
        { elem.getDepends() } -> std::same_as<const Depends &>;
        { std::invoke(print, elem, gen) };
    }
auto processElement(CppGenerator &gen, Depends &currendDepends, const T &elem, MemFn print)
    -> auto {
    const Depends &depends = elem.getDepends();
    if (depends._namespace != currendDepends._namespace) {
        closeDependsIfOpen(gen, currendDepends);
        closePlatformIfOpen(gen, currendDepends);
        closeNamespaceIfOpen(gen, currendDepends);
        if (!depends._namespace.empty()) {
            gen.doBeginNamespace(depends._namespace);
            currendDepends._namespace = depends._namespace;
        }
    }

    if (depends.platform != currendDepends.platform) {
        closeDependsIfOpen(gen, currendDepends);
        closePlatformIfOpen(gen, currendDepends);
        if (!depends.platform.empty()) {
            gen.doMakroIfdef(depends.platform);
            currendDepends.platform = depends.platform;
        }
    }

    if (depends.guard != currendDepends.guard) {
        closeDependsIfOpen(gen, currendDepends);

        if (!depends.guard.empty()) {
            gen.doMakroIf(depends.guard);
            currendDepends.guard = depends.guard;
        }
    }

    std::invoke(print, elem, gen);
};

template <typename T, typename MemFn>
    requires requires(const T &elem, CppGenerator &gen, MemFn print) {
        { elem.getDepends() } -> std::same_as<const Depends &>;
        { std::invoke(print, elem, gen) };
    }
void writeDepends(CppGenerator &gen, const std::set<T> &set, MemFn print, bool reversed = false) {
    Depends currendDepends;

    if (!reversed) {
        for (const T &elem : set) {
            processElement(gen, currendDepends, elem, print);
        }
    } else {
        for (const T &elem : set | std::views::reverse) {
            processElement(gen, currendDepends, elem, print);
        }
    }

    closeDependsIfOpen(gen, currendDepends);
    closePlatformIfOpen(gen, currendDepends);
    closeNamespaceIfOpen(gen, currendDepends);
}

extern void writeObjects(WriteCtx &ctx);

extern void writeHandles(WriteCtx &ctx);

extern void writeObjectReflections(WriteCtx &ctx);

extern void writeConstants(WriteCtx &ctx);

extern void writeEnums(WriteCtx &ctx);

extern void writeStructs(WriteCtx &ctx);

extern void writeDefines(WriteCtx &ctx);

extern void writeFunctionPtrs(WriteCtx &ctx);

extern void writeBaseTypes(WriteCtx &ctx);

extern void writeFunctionTables(WriteCtx &ctx);

extern void initStatics(Registry registry);

extern void writeFiles(const std::filesystem::path &genDir, Registry registry,
                       const std::vector<std::function<void(WriteCtx &ctx)>> &functions);
