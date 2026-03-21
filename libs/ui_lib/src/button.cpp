#include "../include/ui_lib/button.hpp"
#include "../tcolors.hpp"

#include <cassert>
#include <iostream>

using namespace vie;

Button::Button(sf::Vector2f position, sf::Vector2f size, std::string text, const sf::Font &buttonFont)
    : text_(buttonFont, text)
{
    box_.setSize(size);

    {
        box_.setPosition(position);
        sf::Vector2f tempPosition = sf::Vector2f(position.x + 5, position.y + 5);
        text_.setPosition(tempPosition);
    }

    box_.setFillColor(defaultButtonColor);
    text_.setFillColor(defaultTextColor);

    text_.setCharacterSize(18);
    // text_.setFont(buttonFont);

    // text_.setString(text);
}

bool Button::contains(const sf::Vector2i &mousePosition) const
{
    auto tempPosition = static_cast<sf::Vector2f>(mousePosition);
    return box_.getGlobalBounds().contains(tempPosition);
}

void Button::update(const Event &e, sf::RenderWindow &window)
{
    assert(e.has_value() && "I recieved nullopt event");

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    bool isMouseOnButton = contains(mousePosition);

    if (state_ != ButtonState::CLICKED)
    {
        if (isMouseOnButton)
        {
            state_ = ButtonState::ACTIVE;
        }
        else
        {
            state_ = ButtonState::OFFLINE;
        }
    }
    // i can rewrite it to a func isLeftMouseButtonPressed()
    auto *mouseBtnPressed = e->getIf<sf::Event::MouseButtonPressed>();
    if (e->is<sf::Event::MouseButtonPressed>() && mouseBtnPressed != nullptr &&
        mouseBtnPressed->button == sf::Mouse::Button::Left)
    {
        if (isMouseOnButton)
        {
            state_ = ButtonState::CLICKED;
        }
        else
        {
            state_ = ButtonState::OFFLINE;
        }
    }

    auto *mouseBtnReleased = e->getIf<sf::Event::MouseButtonReleased>();
    if (e->is<sf::Event::MouseButtonReleased>() && mouseBtnReleased != nullptr &&
        mouseBtnReleased->button == sf::Mouse::Button::Left)
    {
        if (isMouseOnButton)
        {
            state_ = ButtonState::ACTIVE;
        }
        else
        {
            state_ = ButtonState::OFFLINE;
        }
    }

    switch (state_)
    {
    case ButtonState::ACTIVE:
        box_.setFillColor(activeButtonColor);
        break;
    case ButtonState::CLICKED:
        box_.setFillColor(activeButtonColor);
        break;
    default:
        box_.setFillColor(defaultButtonColor);
        break;
    }
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(box_, states);
    target.draw(text_, states);
}