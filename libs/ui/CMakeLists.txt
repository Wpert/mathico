cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SFML REQUIRED)

add_library(ui_lib STATIC
    src/button.cpp
    src/textbox.cpp
    src/slider.cpp
    src/page.cpp
)


target_include_directories(ui_lib 
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}  # tcolors.hpp clickable.hpp
)

target_compile_features(ui_lib
    PRIVATE cxx_std_17
)

target_link_libraries(ui_lib
    PRIVATE SFML::System SFML::Window SFML::Graphics
)
