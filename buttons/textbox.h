#ifndef GRAPHICO_TEXTBOX_H
#define GRAPHICO_TEXTBOX_H

#pragma once
#include <SFML/Graphics.hpp>
#include "../resources/tcolors.h"
#include <string>

class TextBox {
    sf::RectangleShape box_;
    sf::Text text_;
    std::string inputText_;
    bool focus_;
public:
    TextBox(sf::Vector2f position,
            sf::Vector2f size,
            sf::Font &buttonFont);
    ~TextBox() = default;

    bool Contains(sf::Vector2i& mousePosition);
    void TakeInput(sf::Vector2i& mousePosition, sf::Event &event);
    void Render(sf::RenderWindow &window);
    std::string GetString();
};

class TextBoxContainer {
public:
    std::vector<TextBox> textboxes_;
    std::vector<sf::Text> names_;

    explicit TextBoxContainer(sf::Font &buttonFont) {
        this->textboxes_.emplace_back(sf::Vector2f(165, 45), sf::Vector2f(45, 30), buttonFont);
        this->textboxes_.emplace_back(sf::Vector2f(65, 115), sf::Vector2f(45, 30), buttonFont);
        this->textboxes_.emplace_back(sf::Vector2f(165, 115), sf::Vector2f(45, 30), buttonFont);

        sf::Text textSetSize("Size:", buttonFont, 18);
        textSetSize.setPosition({10 + 5, 45 + 5});
        sf::Text textSetX("X:", buttonFont, 18);
        textSetX.setPosition({10 + 5, 115 + 5});
        sf::Text textSetY("Y:", buttonFont, 18);
        textSetY.setPosition({115 + 5, 115 + 5});

        this->names_.push_back(textSetSize);
        this->names_.push_back(textSetX);
        this->names_.push_back(textSetY);
    }

    [[nodiscard]] size_t GetSize() const;
    std::string GetString(size_t num);
    void TakeInput(sf::Vector2i& mousePosition, sf::Event &event);
    void Render(sf::RenderWindow &window);

    TextBox& operator [] (size_t index);
};

enum TextBoxes {
    SET_SIZE_T = 0,
    SET_EDGE_X = 1,
    SET_EDGE_Y = 2
};

#endif //GRAPHICO_TEXTBOX_H