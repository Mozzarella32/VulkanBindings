#include "Writing.hpp"
#include "CppGenerator.hpp"
#include "ObjectInfo.hpp"
#include "ParseXml.hpp"
#include "TypeInfo.hpp"

#include <fstream>
#include <iostream>
#include <ranges>
#include <chrono>
#include <utility>

void writeStructures(tinyxml2::XMLElement &registry,
                     [[maybe_unused]] const std::filesystem::path &genSrc,
                     [[maybe_unused]] const std::filesystem::path &genInclude) {

    std::set<TypeInfo> typeInfos = parseTypeInfos(registry);

    std::filesystem::path structureTypes = genSrc / "Structures.cpp";

    CppGenerator gen;

    gen.doIncludeLocal("Structures.hpp");
    gen.doIncludeLocal("Vulkan.hpp");
    gen.doIncludeLocal("Objects.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doEmptyLine();

    gen.doCode(R"--(
template <typename T> struct StructureType;

template <typename T>
T Init() {
  T t = {};
  t.sType = StructureType<T>::t;
  return t;
}
)--");

    writeDepends(gen, typeInfos, TypeInfo::header);

    gen.doEndNamespace();
    gen.doEmptyLine();

    std::ofstream o(structureTypes);
    o << gen.buff.rdbuf();
}

void writeObjects(tinyxml2::XMLElement &registry,
                  [[maybe_unused]] const std::filesystem::path &genSrc,
                  [[maybe_unused]] const std::filesystem::path &genInclude) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(registry);

    std::filesystem::path objectsHpp = genInclude / "Objects.hpp";
    std::filesystem::path objectsCpp = genSrc / "Objects.cpp";

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeGlobal("cassert");
    gen.doIncludeGlobal("cstdint");
    gen.doIncludeGlobal("expected");
    gen.doIncludeGlobal("tuple");
    gen.doIncludeGlobal("utility");
    gen.doIncludeGlobal("vector");
    gen.doEmptyLine();
    gen.doIncludeLocal("Vulkan.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("impl_Objects");

    gen.doCode(R"--(
template<typename Handle_T, VkObjectType Obj_T, auto Destroy_Fun, typename Creator_T>
struct Unique {
    using handle_type = Handle_T;
    static constexpr const VkObjectType objectType = Obj_T;

  protected:
    Handle_T handle = VK_NULL_HANDLE;
    Unique(Handle_T&& h) : handle(h) {}

    friend Creator_T;

  public:
    Unique() {}
    Unique(Unique&& other) : handle(std::exchange(other.handle, VK_NULL_HANDLE)) {}
    Unique& operator=(Unique&& other) noexcept {
        cleanup();
        handle = std::exchange(other.handle, VK_NULL_HANDLE);
    }
    void cleanup() noexcept {
        if (handle != VK_NULL_HANDLE) {
            (*Destroy_Fun)(handle, nullptr);
            handle = VK_NULL_HANDLE;
        }
    }
    ~Unique() noexcept { cleanup(); }

    Handle_T get() const noexcept { return handle; }
    explicit operator bool() const noexcept { return handle != VK_NULL_HANDLE; }
    operator Handle_T() const noexcept { return handle; }
};

template<typename Handle_T, VkObjectType Obj_T, typename Owner_T, typename Owner_Handle_T, auto Destroy_Fun>
struct OwnedUnique {
    using handle_type = Handle_T;
    static constexpr const VkObjectType objectType = Obj_T;

  protected:
    Handle_T handle = VK_NULL_HANDLE;
    Owner_Handle_T owner = VK_NULL_HANDLE;
    OwnedUnique(Handle_T&& h, Owner_Handle_T o) : handle(h), owner(o) {}

    friend Owner_T;

  public:
    OwnedUnique() {}
    OwnedUnique(OwnedUnique&& other) : handle(std::exchange(other.handle, VK_NULL_HANDLE)), owner(std::exchange(other.owner, VK_NULL_HANDLE)) {}
    OwnedUnique& operator=(OwnedUnique&& other) noexcept {
        cleanup();
        handle = std::exchange(other.handle, VK_NULL_HANDLE);
        owner = std::exchange(other.owner, VK_NULL_HANDLE);
    }
    void cleanup() noexcept {
        if (handle != VK_NULL_HANDLE) {
            (*Destroy_Fun)(owner, handle, nullptr);
            handle = VK_NULL_HANDLE;
            owner = VK_NULL_HANDLE;
        }
    }
    ~OwnedUnique() noexcept { cleanup(); }

    Handle_T get() const noexcept { return handle; }
    explicit operator bool() const noexcept { return handle != VK_NULL_HANDLE; }
    operator Handle_T() const noexcept { return handle; }
};

template <typename Handle_T, VkObjectType Obj_T> struct NonOwned {
    using handle_type = Handle_T;
    static constexpr const VkObjectType objectType = Obj_T;

  protected:
    Handle_T handle{VK_NULL_HANDLE};
    NonOwned(Handle_T &&handle) : handle(std::move(handle)) {}

  public:
    NonOwned() {}
    operator Handle_T() const { return handle; }
};

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T,
          auto Free_fun>
struct PoolAllocated {
    using handle_type = typename Handle_T::handle_type;
    static constexpr const VkObjectType objectType = Handle_T::Obj_T;
    bool is_pool_allocated = true;

  private:
    std::vector<Handle_T> handles{};
    Pool_Handle_T pool = VK_NULL_HANDLE;
    Owner_Handle_T owner = VK_NULL_HANDLE;

    PoolAllocated(std::vector<Handle_T> &&handles, Pool_Handle_T pool, Owner_Handle_T owner)
        : handles(std::move(handles)), pool(pool), owner(owner) {}

    friend Owner_T;

  public:
    PoolAllocated() {}
    PoolAllocated(PoolAllocated &&other)
        : handles(std::exchange(other.handles, {})),
          pool(std::exchange(other.pool, VK_NULL_HANDLE)),
          owner(std::exchange(other.owner), VK_NULL_HANDLE) {}
    PoolAllocated &operator=(PoolAllocated &&other) noexcept {
        cleanup();
        handles = std::exchange(other.handles, {});
        pool = std::exchange(other.pool, VK_NULL_HANDLE);
        owner = std::exchange(other.owner, VK_NULL_HANDLE);
    }
    void cleanup() {
        if (!handles.empty()) {
            (*Free_fun)(owner, pool, handles.size(), handles.data());
            handles.clear();
            pool = VK_NULL_HANDLE;
            owner = VK_NULL_HANDLE;
        }
    }
    ~PoolAllocated() noexcept { cleanup(); }
    explicit operator bool() const { return !handles.empty(); }
   Handle_T &operator[](size_t n) {
        assert(n < handles.size());
        return handles[n];
    }
    const Handle_T &operator[](size_t n) const {
        assert(n < handles.size());
        return handles[n];
    }
    decltype(handles)::iterator begin() { return handles.begin(); }
    decltype(handles)::iterator end() { return handles.end(); }
    decltype(handles)::const_iterator cbegin() const { return handles.cbegin(); }
    decltype(handles)::const_iterator cend() const { return handles.cend(); }
    decltype(handles)::reverse_iterator rbegin() { return handles.rbegin(); }
    decltype(handles)::reverse_iterator rend() { return handles.rend(); }
    decltype(handles)::const_reverse_iterator crbegin() const { return handles.crbegin(); }
    decltype(handles)::const_reverse_iterator crend() const { return handles.crend(); }
};

)--");

    gen.doEndNamespace();

    std::set<ObjectInfo> objectsWithFuns =
        objectInfos |
        std::views::filter([](const ObjectInfo &info) { return !info.functions.empty(); }) |
        std::ranges::to<std::set<ObjectInfo>>();

    writeDepends(gen, objectInfos, ObjectInfo::writeForwardDecl, true);
    writeDepends(gen, objectsWithFuns, ObjectInfo::writeHeader);

    gen.doEndNamespace();

    std::ofstream o(objectsHpp);
    o << gen.buff.rdbuf();
    o.close();

    gen.doIncludeLocal("Objects.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doEmptyLine();

    writeDepends(gen, objectsWithFuns, ObjectInfo::writeImpl);

    gen.doEndNamespace();

    o.open(objectsCpp);
    o << gen.buff.rdbuf();
}

void writeFiles(
    const std::filesystem::path &genSrc, std::filesystem::path &genInclude,
    tinyxml2::XMLElement &registry,
    const std::vector<
        std::tuple<std::vector<std::string>,
                   std::function<void(tinyxml2::XMLElement &, const std::filesystem::path &,
                                      const std::filesystem::path &)>>> &functions) {
    for (const auto &[filenames, function] : functions) {
        std::cout << "Writing : [";
        for (size_t i = 0; i < filenames.size(); i++) {
            std::cout << filenames[i];
            if (i != filenames.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "] ";
        auto start = std::chrono::high_resolution_clock::now();
        function(registry, genSrc, genInclude);
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         std::chrono::high_resolution_clock::now() - start)
                  << "\n";
    }
}
