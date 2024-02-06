cmake_minimum_required(VERSION 3.25)
project(Mathico VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Mathico main.cpp
                gui/gui.h gui/gui.cpp
                gui/page/tpage.h gui/page/tpage.cpp
                gui/page/buttons/tbuttons.h gui/page/buttons/tbuttons.cpp
                gui/page/textboxes/textbox.h gui/page/textboxes/textbox.cpp
                gui/page/slider/slider.h gui/page/slider/slider.cpp
                resources/tcolors.h
                math/polygon.h math/polygon.cpp
                math/vmath.h math/vmath.cpp)

set(CMAKE_CXX_STANDARD 20)
target_compile_features(Mathico PUBLIC cxx_std_20)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/cpp/sfml/SFML-2.5.1/lib/cmake/SFML)

include_directories(C:/cpp/sfml/SFML-2.5.1/include)
target_link_libraries(Mathico sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
