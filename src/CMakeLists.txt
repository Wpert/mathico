
find_package(SFML REQUIRED)
# find_package(UILib REQUIRED)

add_executable(${PROJECT_NAME}
main.cpp
app_pages/main_menu/menu_page.cpp
# pages/fern_page.cpp
# pages/sierpinski_page.cpp
# pages/polygon_page.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE SFML::System SFML::Window SFML::Graphics
    PRIVATE ui_lib
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/app_pages
        ${CMAKE_CURRENT_SOURCE_DIR}/app_pages/main_menu
        ${CMAKE_SOURCE_DIR}/libs/ui/include
        ${CMAKE_SOURCE_DIR}/libs/ui
        ${CMAKE_SOURCE_DIR}/libs/math
)
