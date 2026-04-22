BUILD_DIR := build
PLATFORM := bindings/include/VkBindings/private/vk_platform.h

.PHONY: all debug release clean build clang-format clang-tidy

NUM_THREADS := $(shell nproc)

GENERATOR ?=

ifeq ($(GENERATOR),)
GENERATOR_FLAG := -G "Ninja"
else
GENERATOR_FLAG := -G "$(GENERATOR)"
endif

all: release build

debug: clean
	@mkdir -p $(BUILD_DIR)
	cmake -S . -B $(BUILD_DIR) $(GENERATOR_FLAG) -DCMAKE_BUILD_TYPE=Debug

release: clean
	@mkdir -p $(BUILD_DIR)
	cmake -S . -B $(BUILD_DIR) $(GENERATOR_FLAG) -DCMAKE_BUILD_TYPE=Release

build:
	cmake --build $(BUILD_DIR) -j$(NUM_THREADS)

clean:
	rm -rf $(BUILD_DIR) $(TARGET_PATH) $(LOG_PATH) $(RESOURCE_PATH) $(PLATFORM)

clang-format:
	@CLANG_FORMAT=$$(command -v clang-format 2>/dev/null || true); \
	if [ -z "$$CLANG_FORMAT" ]; then \
		echo "clang-format not found; please install clang-format."; \
		exit 1; \
	fi; \
	FILES=$$(find generator/ bindings/ -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.cc" -o -name "*.cxx" -o -name "*.h" -o -name "*.hpp" \) 2>/dev/null || true); \
	if [ -z "$$FILES" ]; then \
		echo "No source/header files found in bindings/ or generator/ to format."; \
		exit 0; \
	fi; \
	printf "%s\n" $$FILES | xargs -r $$CLANG_FORMAT -style=file -i; \
	echo "clang-format: formatted files under generator/ and bindings/."

clang-tidy:
	@CLANG_TIDY=$$(command -v clang-tidy 2>/dev/null || true); \
	if [ -z "$$CLANG_TIDY" ]; then \
		echo "clang-tidy not found; please install clang-tidy."; \
		exit 1; \
	fi; \
	if [ ! -f $(BUILD_DIR)/compile_commands.json ]; then \
		echo "compile_commands.json missing in $(BUILD_DIR). Run 'make configure' (or run cmake) to generate it."; \
		exit 1; \
	fi; \
	FILES=$$(find generator/ bindings/ -type f \( -name "*.cpp" -o -name "*.cc" -o -name "*.cxx" -o -name "*.c" -o -name "*.h" -o -name "*.hpp" -o -name "*.hh" \) -print); \
	if [ -z "$$FILES" ]; then \
		echo "No C/C++ files found to analyze."; \
		exit 0; \
	fi; \
	echo "Running clang-tidy on all discovered files..."; \
	$$CLANG_TIDY -p "$(BUILD_DIR)" $$FILES
