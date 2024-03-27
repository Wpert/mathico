cmake_minimum_required(VERSION 3.25)
project(mathico VERSION 0.2.0 LANGUAGES C CXX)

include(CTest)

# ??? alright i have to learn how to cmake !
add_library(button new_gui/button/button.hpp new_gui/button/button.cpp)
add_library(textbox new_gui/textbox/textbox.hpp new_gui/textbox/textbox.cpp)
add_library(slider new_gui/slider/slider.hpp new_gui/slider/slider.cpp)

add_executable(
  mathico main.cpp
  
  new_gui/textbox/textbox.hpp new_gui/textbox/textbox.cpp
  new_gui/button/button.hpp new_gui/button/button.cpp
  new_gui/slider/slider.hpp new_gui/slider/slider.cpp
  new_gui/page/page.hpp new_gui/page/page.cpp
  
  new_gui/app_pages/logic.hpp
  new_gui/app_pages/menu_page.hpp
  new_gui/app_pages/sierpinski_page.hpp
  new_gui/app_pages/save_page.hpp
  new_gui/app_pages/fern_page.hpp

  new_gui/gui.hpp

  math/vmath.hpp math/vmath.cpp
  math/polygon.hpp math/polygon.cpp
  # new_gui/utility.hpp
  # resources/tcolors.hpp
)

set(CMAKE_CXX_STANDARD 20)

target_compile_features(mathico PUBLIC cxx_std_20)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/cpp/sfml/SFML-2.5.1/lib/cmake/SFML)
include_directories(C:/cpp/sfml/SFML-2.5.1/include)
target_link_libraries(mathico sfml-system sfml-window sfml-graphics)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

# testing binary
add_executable(test_button test/test_button.cpp)
add_executable(test_textbox test/test_textbox.cpp)
target_link_libraries(test_button sfml-system sfml-window sfml-graphics button)
target_link_libraries(test_textbox sfml-system sfml-window sfml-graphics textbox)

# enable testing functionality
enable_testing()

# define tests
add_test(
  NAME button_t
  COMMAND $<TARGET_FILE:test_button>
  )
add_test(
  NAME textbox_t
  COMMAND $<TARGET_FILE:test_textbox>
  )


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
