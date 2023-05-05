#ifndef FAV_TBUTTONS_H
#define FAV_TBUTTONS_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../resources/tcolors.h"
#include <functional>
#include "textbox.h"
#include "../polygon/polygon.h"
#include "../math/TMath.h"

class Button {
private:
    sf::RectangleShape box_;
    sf::Text text_;

public:
    Button(sf::Vector2f position,
           sf::Vector2f size,
           std::string text,
           sf::Font &buttonFont);
    ~Button() = default;

    bool Contains(sf::Vector2i& mousePosition) const;
    void Render(sf::Vector2i &mousePosition, sf::RenderWindow &window);
};

class ButtonContainer {
public:
    std::vector<Button> buttons_;
    std::vector<std::function<void(TextBoxContainer&, Polygon&, Polygon&, Polygon::Point&)>> buttonFunctions_;

    explicit ButtonContainer(sf::Font &buttonFont) {
        this->buttons_.emplace_back(sf::Vector2f(10, 10), sf::Vector2f(200, 30), "Set size", buttonFont);
        this->buttons_.emplace_back(sf::Vector2f(10, 80), sf::Vector2f(200, 30), "Set edge", buttonFont);
        this->buttons_.emplace_back(sf::Vector2f(10, 150), sf::Vector2f(200, 30), "Render", buttonFont);
        this->buttons_.emplace_back(sf::Vector2f(10, 185), sf::Vector2f(200, 30), "Clear", buttonFont);

        // когда-нибудь я выберу стиль в котором будет реализовано нажатие кнопок
        auto setSize = [](TextBoxContainer &textboxes, Polygon &tempPoly, Polygon &poly, Polygon::Point &point) {
            if (!textboxes[TextBoxes::SET_SIZE_T].GetString().empty()) {
                size_t newSize = std::stoi(textboxes.textboxes_[TextBoxes::SET_SIZE_T].GetString());
                tempPoly = Polygon(newSize);
            }
        };
        auto setEdge = [](TextBoxContainer &textboxes, Polygon &tempPoly, Polygon &poly, Polygon::Point &point) {
            if (!textboxes[TextBoxes::SET_EDGE_X].GetString().empty() &&
                !textboxes[TextBoxes::SET_EDGE_Y].GetString().empty()) {
                point = Polygon::Point(std::stoi(textboxes[TextBoxes::SET_EDGE_X].GetString()),
                                       std::stoi(textboxes[TextBoxes::SET_EDGE_Y].GetString()));
                math::calculate(tempPoly, point);
            }
        };
        auto renderPoly = [](TextBoxContainer &textboxes, Polygon &tempPoly, Polygon &poly, Polygon::Point &point) {
            poly = tempPoly;
        };
        auto clear = [](TextBoxContainer &textboxes, Polygon &tempPoly, Polygon &poly, Polygon::Point &point) {
            poly = Polygon(1);
        };
        this->buttonFunctions_ = {setSize, setEdge, renderPoly, clear};
    }

    size_t GetSize();
    void Render(sf::Vector2i &mousePosition, sf::RenderWindow &window);
    Button& operator [] (size_t index);
};

#endif //FAV_TBUTTONS_H
