cmake_minimum_required(VERSION 3.25)
project(Polygo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Polygo main.cpp polygon/polygon.cpp polygon/polygon.h polygon/point.cpp math/TMath.cpp math/TMath.h buttons/tbuttons.cpp buttons/tbuttons.h resources/tcolors.h buttons/textbox.cpp buttons/textbox.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/cpp/sfml/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network)

include_directories(C:/cpp/sfml/SFML-2.5.1/include)
target_link_libraries(Polygo sfml-system sfml-window sfml-graphics sfml-audio sfml-network)