#include "new_gui/gui.hpp"

std::string getDirPath() {
    std::string path(__FILE__);
    std::cout << __FILE__ << std::endl;
    path = path.substr(0, path.rfind('/') + 1);
    return path;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 600),
                                "Mathico",
                                sf::Style::Close);
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.setFramerateLimit(60);

    std::string dirPath = getDirPath();
    sf::Font basicFont;
    std::cout << "Dir path: " <<  dirPath << std::endl;
    basicFont.loadFromFile(dirPath + "resources/calibri.ttf");

    vie::ApplicationLogic lgck(basicFont, window);
    lgck.Process(window);

    return 0;
}