cmake_minimum_required(VERSION 3.28)
project(App VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs/math)
add_subdirectory(libs/ui_lib)
add_subdirectory(src)
# add_subdirectory(tests)

# Копирование ресурсов при сборке (опционально)
# file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})