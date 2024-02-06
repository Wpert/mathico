// #ifndef GRAPHICO_TEXTBOX_H
// #define GRAPHICO_TEXTBOX_H

#pragma once
#include <SFML/Graphics.hpp>
#include "../../../resources/tcolors.h"
#include <string>
#include <iostream>
#include <cmath>

namespace vie {

namespace SliderState {
    enum {
        OFFLINE,
        ACTIVE
    };
}
namespace Sliders {
    enum {
        SIERPINSKI_DOTS,
        FERN_DOTS
    };
}

class Slider : public sf::Drawable {
    sf::Vertex line_[2];
    sf::CircleShape circle_;
    sf::Text text_;

    short state_ = SliderState::OFFLINE;
    double from_;
    double diff_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    size_t enumNumber_;

    Slider() = default;
    Slider(sf::Vector2f startPos, sf::Vector2f endPos,
           double from, double to, int count,
           sf::Font &buttonFont, size_t number);
    ~Slider() = default;
    bool Contains(sf::Vector2i& mousePosition);
    void update(sf::Event& e, sf::RenderWindow& window);
    double GetNumber();
};

class SliderContainer {
public:
    std::vector<Slider> sliders_;

    SliderContainer() = default;
    ~SliderContainer() = default;

    size_t GetSize() {
        return this->sliders_.size();
    }

    double GetNumber(size_t num) {
        for (auto &slider : this->sliders_)
            if (slider.enumNumber_ == num) {
                return slider.GetNumber();
            }
        return 0;
    }

    void AddSlider(sf::Vector2f startPos, sf::Vector2f endPos,
           double from, double to, int count,
           sf::Font &buttonFont, size_t number) {
        this->sliders_.emplace_back(startPos, endPos, from, to, count, buttonFont, number);
    }

    void ClearSliders() {
        this->sliders_.clear();
    }

    void TakeInput(sf::Event &event, sf::RenderWindow& window) {
        for (Slider &slider : sliders_) {
            slider.update(event, window);
        }
    }

    void Render(sf::RenderWindow &window) {
        for (Slider &slider : sliders_) {
            window.draw(slider);
        }
    }
};

}

// #endif //GRAPHICO_TEXTBOX_H
