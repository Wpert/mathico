#ifndef FAV_TBUTTONS_H
#define FAV_TBUTTONS_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../../resources/tcolors.h"
#include <mutex>
#include <shared_mutex>

namespace vie {

namespace ButtonState {
    enum {
        OFFLINE,
        CLICKED,
        ACTIVE
    };
}

class Button : public sf::Drawable {
private:
    sf::RectangleShape box_;
    sf::Text text_;
    short state_ = ButtonState::OFFLINE;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    size_t enumNumber_;

    Button(sf::Vector2f position,
           sf::Vector2f size,
           std::string text,
           sf::Font &buttonFont,
           size_t number);
    ~Button() = default;

    bool Contains(sf::Vector2i& mousePosition) const;
    void update(sf::Event& e, sf::RenderWindow& window);
};

class ButtonContainer {
public:
    std::vector<Button> buttons_;

    ButtonContainer() = default;

    size_t GetSize();
    void AddButton(sf::Vector2f position, const std::string &text, size_t number, sf::Font &buttonFont);
    void ClearButtons();
    void TakeInput(sf::Event &event, sf::RenderWindow& window);
    void Render(sf::RenderWindow &window);
};

}

#endif 
