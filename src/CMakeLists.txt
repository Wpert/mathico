
find_package(SFML REQUIRED)
find_package(spdlog REQUIRED)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

add_executable(${PROJECT_NAME}
    main.cpp
    app_pages/main_menu/menu_page.cpp
    app_pages/sierpinski/sierpinski_page.cpp
    app_pages/fern/fern_page.cpp
    app_pages/regular_polygon/polygon_page.cpp
    app_pages/save_menu/save_page.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE SFML::System SFML::Window SFML::Graphics
    PRIVATE spdlog::spdlog
    PRIVATE ui_lib math_lib
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
