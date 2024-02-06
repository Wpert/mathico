#ifndef GRAPHICO_TEXTBOX_H
#define GRAPHICO_TEXTBOX_H

#pragma once
#include <SFML/Graphics.hpp>
#include "../../../resources/tcolors.h"
#include <string>
#include <iostream>

namespace vie {

class TextBox : public sf::Drawable {
    sf::RectangleShape box_;
    sf::Text text_;
    std::string inputText_;
    bool focus_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    size_t enumNumber_;

    TextBox(sf::Vector2f position, sf::Vector2f size,
            sf::Font &buttonFont, size_t number);
    ~TextBox() = default;

    bool Contains(sf::Vector2i& mousePosition);
    void update(sf::Event& e, sf::RenderWindow& window);
    std::string GetString();
};

class TextBoxContainer {
    size_t textCharSize_ = 18;

public:
    std::vector<TextBox> textboxes_;
    std::vector<sf::Text> names_;

    TextBoxContainer() = default;
    ~TextBoxContainer() = default;

    size_t GetSize() {
        return this->textboxes_.size();
    }

    std::string GetString(size_t num);
    void AddTextbox(sf::Vector2f position, size_t number, sf::Font &textboxFont);
    void AddName(sf::Vector2f position, const std::string &text, sf::Font &textboxFont);
    void ClearTextboxes();
    void TakeInput(sf::Event &event, sf::RenderWindow& window);
    void Render(sf::RenderWindow &window);
};

}

#endif //GRAPHICO_TEXTBOX_H
