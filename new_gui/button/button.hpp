#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../utility.hpp"
#include <cstdlib>

namespace vie
{

class Clickable : public sf::Drawable {
public:
    virtual ~Clickable() {}
    virtual void update(sf::Event& e, sf::RenderWindow& window) = 0;
};

namespace ButtonState {
    enum {
        OFFLINE,
        CLICKED,
        ACTIVE
    };
}

class Button : public Clickable {
protected:
    sf::RectangleShape box_;
    sf::Text text_;
    short state_ = ButtonState::OFFLINE;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:

    Button(sf::Vector2f position,
           sf::Vector2f size,
           std::string text,
           const sf::Font &buttonFont);
    virtual ~Button() {}
    virtual bool CallFunc() const = 0;

    bool Contains(sf::Vector2i& mousePosition) const;
    void update(sf::Event& e, sf::RenderWindow& window) override;
};

}

#endif
