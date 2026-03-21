.PHONY: all run clean help

BUILD_DIR = build
BUILD_DIR_RELEASE = $(BUILD_DIR)/Release
BUILD_DIR_DEBUG = $(BUILD_DIR)/Debug
TARGET_RELEASE = $(BUILD_DIR_RELEASE)/src/App
TARGET_DEBUG = $(BUILD_DIR_DEBUG)/src/App
CMAKE_TOOLCHAIN_RELEASE = $(BUILD_DIR_RELEASE)/generators/conan_toolchain.cmake
CMAKE_TOOLCHAIN_DEBUG = $(BUILD_DIR_DEBUG)/generators/conan_toolchain.cmake

## Configure and build release version
release-build: $(CMAKE_TOOLCHAIN_RELEASE)
	@echo "Building release..."
	@cmake --build $(BUILD_DIR_RELEASE) --parallel

## Configure and build debug version
debug-build: $(CMAKE_TOOLCHAIN_DEBUG)
	@echo "Building debug..."
	@cmake --build $(BUILD_DIR_DEBUG) --parallel

## Configure release
$(CMAKE_TOOLCHAIN_RELEASE): conanfile.txt
	@echo "Configuring release..."
	conan install . --output-folder=$(BUILD_DIR_RELEASE) --build=missing -s build_type=Release && \
	cmake -S . -B $(BUILD_DIR_RELEASE) \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_TOOLCHAIN_FILE=$(CMAKE_TOOLCHAIN_RELEASE) \
		-DCMAKE_BUILD_TYPE=Release

## Configure debug
$(CMAKE_TOOLCHAIN_DEBUG): conanfile.txt
	@echo "Configuring debug..."
	conan install . --output-folder=$(BUILD_DIR_DEBUG) --build=missing -s build_type=Debug && \
	cmake -S . -B $(BUILD_DIR_DEBUG) \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_TOOLCHAIN_FILE=$(CMAKE_TOOLCHAIN_DEBUG) \
		-DCMAKE_BUILD_TYPE=Debug

## Run release version
run: release-build
	@SPDLOG_LEVEL=info && ./$(TARGET_RELEASE)

## Run debug version
run-debug: debug-build
	@export SPDLOG_LEVEL=debug && \
	./$(TARGET_DEBUG)

## Debug application
debug: debug-build
	@SPDLOG_LEVEL=debug && gdb $(TARGET_DEBUG)

## Clear build_dir
clean:
	@rm -rf $(BUILD_DIR)

help:
	@echo "Available targets:"
	@echo ""
	@grep -E '^##[a-zA-Z\.\-_]+:.*$$|^[a-zA-Z\.\-_]+:.*##.*$$' $(MAKEFILE_LIST) | \
		awk -F ':.*## ' 'NF==2 {printf "  %-20s %s\n", $$1, $$2}' | \
		sort
