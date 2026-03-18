cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SFML REQUIRED)

add_library(math_lib STATIC
    src/polygon.cpp
    src/vmath.cpp
)


target_include_directories(math_lib 
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(math_lib
    PRIVATE cxx_std_20
)

target_link_libraries(math_lib
    PRIVATE SFML::Graphics
)
