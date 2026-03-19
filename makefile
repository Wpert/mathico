.PHONY: all run clean configure

BUILD_DIR = build
TARGET = $(BUILD_DIR)/src/App

all: configure-release
	@cmake --build $(BUILD_DIR) --parallel

run: all
	@SPDLOG_LEVEL=info && ./$(TARGET)

debug: all
	@gdb $(TARGET)

configure-release:
	@if [ ! -d $(BUILD_DIR) ]; then \
		conan install . --output-folder=$(BUILD_DIR) --build=missing; \
		cmake -S . -B $(BUILD_DIR) \
			-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
			-DCMAKE_TOOLCHAIN_FILE=$(BUILD_DIR)/build/Release/generators/conan_toolchain.cmake \
			-DCMAKE_BUILD_TYPE=Release; \
	elif [ CMakeLists.txt -nt $(BUILD_DIR)/CMakeCache.txt ]; then \
		cmake -S . -B $(BUILD_DIR); \
	fi
	@

clean:
	@rm -rf $(BUILD_DIR)

