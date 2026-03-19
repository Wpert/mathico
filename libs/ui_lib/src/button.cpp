#include "../include/ui_lib/button.hpp"
#include "../tcolors.hpp"

#include <cassert>
#include <iostream>

using namespace vie;

Button::Button(sf::Vector2f position, sf::Vector2f size, std::string text, const sf::Font &buttonFont)
    : text_(buttonFont, text)
{
    this->box_.setSize(size);

    {
        this->box_.setPosition(position);
        sf::Vector2f tempPosition = sf::Vector2f(position.x + 5, position.y + 5);
        this->text_.setPosition(tempPosition);
    }

    this->box_.setFillColor(defaultButtonColor);
    this->text_.setFillColor(defaultTextColor);

    this->text_.setCharacterSize(18);
    // this->text_.setFont(buttonFont);

    // this->text_.setString(text);
}

bool Button::contains(sf::Vector2i &mousePosition) const
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

    switch (this->state_)
    {
    case ButtonState::ACTIVE:
        this->box_.setFillColor(activeButtonColor);
        break;
    case ButtonState::CLICKED:
        this->box_.setFillColor(activeButtonColor);
        break;
    default:
        this->box_.setFillColor(defaultButtonColor);
        break;
    }
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->box_, states);
    target.draw(this->text_, states);
}