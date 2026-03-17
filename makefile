.PHONY: all run clean configure

BUILD_DIR = build
TARGET = $(BUILD_DIR)/src/App

all: configure
	@cmake --build $(BUILD_DIR) --parallel

run: all
	@./$(TARGET)

debug: all
	@gdb $(TARGET)

configure:
	@if [ ! -d $(BUILD_DIR) ]; then \
		conan install . --output-folder=$(BUILD_DIR) --build=missing; \
		cmake -S . -B $(BUILD_DIR) \
			-DCMAKE_TOOLCHAIN_FILE=$(BUILD_DIR)/build/Release/generators/conan_toolchain.cmake \
			-DCMAKE_BUILD_TYPE=Release; \
	elif [ CMakeLists.txt -nt $(BUILD_DIR)/CMakeCache.txt ]; then \
		cmake -S . -B $(BUILD_DIR); \
	fi

clean:
	@rm -rf $(BUILD_DIR)

