#include <spdlog/spdlog.h>
#include <spdlog/cfg/env.h>   // support for loading levels from the environment variable

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "gui.hpp"

std::string getDirPath() {
    std::string path(__FILE__);
    spdlog::debug("path to main.cpp: {}", path);
    path = path.substr(0, path.rfind('/') + 1);
    return path;
}

int main() {
    // Set the log level to "info" and mylogger to "trace":
    // SPDLOG_LEVEL=info,mylogger=trace && ./example
    spdlog::cfg::load_env_levels();

    spdlog::info("Welcome to spdlog version {}.{}.{}  !",
        SPDLOG_VER_MAJOR,
        SPDLOG_VER_MINOR,
        SPDLOG_VER_PATCH
    );

    // spdlog::warn("Easy padding in numbers like {:08d}", 12);

    sf::RenderWindow window(sf::VideoMode({1024, 600}),
                                "Mathico",
                                sf::Style::Close);
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    window.setFramerateLimit(60);

    std::string dirPath = getDirPath();

    sf::Font basicFont;
    spdlog::info("dirPath: {}", dirPath);
    bool hasOpened = basicFont.openFromFile(dirPath + "../resources/calibri.ttf");

    vie::ApplicationLogic lgck(basicFont, window);
    lgck.Process(window);

    return 0;
}
