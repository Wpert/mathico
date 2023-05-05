#include <SFML/Graphics.hpp>

#include "polygon/polygon.h"
#include "buttons/tbuttons.h"
#include "buttons/textbox.h"
#include "resources/tcolors.h"
#include <iostream>

Polygon tempPoly(1);
Polygon::Point core_point;

Polygon mainPoly(1);

std::string getDirPath() {
    std::string path(__FILE__);
    path = path.substr(0, path.rfind('/') + 1);
    return path;
}

int main() {
    sf::RenderWindow mainWindow(sf::VideoMode(1024, 600),
                                "Polygo",
                                sf::Style::Close);
    // other settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    mainWindow.setFramerateLimit(60);

    std::string dirPath = getDirPath();
    sf::Font basicFont;
    std::cout << "Dir path: " <<  dirPath << std::endl;
    basicFont.loadFromFile(dirPath + "resources/calibri.ttf");

    sf::Vector2i mousePosition;
    TextBoxContainer textboxes(basicFont);
    ButtonContainer buttons(basicFont);

    bool isWindowActive = true;

    while (mainWindow.isOpen()) {
        mousePosition = sf::Mouse::getPosition(mainWindow);
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            textboxes.TakeInput(mousePosition, event);

            if (event.type == sf::Event::Closed)
                mainWindow.close();
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                for (size_t buttonIndex = 0; buttonIndex < buttons.GetSize(); ++buttonIndex) {
                    if (buttons[buttonIndex].Contains(mousePosition)) {
                        buttons.buttonFunctions_[buttonIndex](textboxes, tempPoly, mainPoly, core_point);
                    }
                }
            }
            if (event.type == sf::Event::LostFocus) {
                isWindowActive = false;
            }
            else if (event.type == sf::Event::GainedFocus) {
                isWindowActive = true;
            }
        }

        if (isWindowActive) {
            mainWindow.clear(backgroundColor);
            mainPoly.Draw(mainWindow);
            textboxes.Render(mainWindow);
            buttons.Render(mousePosition, mainWindow);
            mainWindow.display();
        }
    }
    return 0;
}