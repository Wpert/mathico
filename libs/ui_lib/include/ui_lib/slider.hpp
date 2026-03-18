#ifndef SLIDER_HPP
#define SLIDER_HPP

#include <SFML/Graphics.hpp>

#include "../clickable.hpp"

namespace vie {

namespace SliderState {
    enum {
        OFFLINE,
        ACTIVE
    };
}

class Slider : public Clickable {
    sf::Vertex line_[2];
    sf::CircleShape circle_;
    sf::Text text_;

    short state_ = SliderState::OFFLINE;
    double from_;
    double diff_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

    Slider() = default;
    Slider(sf::Vector2f startPos, sf::Vector2f endPos,
           double from, double to, int count,
           const sf::Font &buttonFont);
    ~Slider();
    bool Contains(sf::Vector2i& mousePosition);
    void update(const Event& e, sf::RenderWindow& window) override;
    double GetNumber();
};

}

#endif
