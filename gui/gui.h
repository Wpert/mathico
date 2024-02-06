#ifndef FAV_GUI_H
#define FAV_GUI_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "page/tpage.h"
#include "../math/vmath.h"
#include <cstdlib>
#include <utility>
#include <memory>
#include <cstring>
#include <random>

namespace vie {

class TWorkArea {
private:
    sf::RectangleShape area_;
public:
    TWorkArea(sf::Vector2f pos, sf::Vector2f size);

    void SetSize(sf::Vector2f size);
    void Render(sf::RenderWindow &window);
};

class TLogic {
public:
    TLogic(sf::Font font);
    void Render(sf::RenderWindow &mainWindow);
    void ReadInputs(sf::RenderWindow &mainWindow);

private:
    void guiInteraction(sf::RenderWindow &window, Button &button);
    void InteractMenu(sf::RenderWindow &window, Button &button);
    void InteractSierpinski(sf::RenderWindow &window, Button &button);
    void InteractFern(sf::RenderWindow &window, Button &button);
    void InteractPolygon(sf::RenderWindow &window, Button &button);
    void InteractFiles(sf::RenderWindow &window, Button &button);

    bool isMainWindowActive_ = true;

    sf::Image editableImage_;
    sf::Texture loadingTexture_;
    sf::RenderTexture PolygonTexture_;
    sf::Sprite renderingSprite_;

    sf::Font mainFont_;

    TWorkArea graphWorkspace_;
    TPageManager mainGui_;
};

}

#endif //FAV_GUI_H
