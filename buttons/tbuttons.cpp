#include "tbuttons.h"

Button::Button(sf::Vector2f position,
               sf::Vector2f size,
               std::string text,
               sf::Font &buttonFont) {
    this->box_.setSize(size);

    {
        this->box_.setPosition(position);
        sf::Vector2f tempPosition = sf::Vector2f(position.x + 5, position.y + 5);
        this->text_.setPosition(tempPosition);
    }

    this->box_.setFillColor(defaultButtonColor);
    this->text_.setFillColor(defaultTextColor);

    this->text_.setCharacterSize(18);
    this->text_.setFont(buttonFont);

    this->text_.setString(text);
}

bool Button::Contains(sf::Vector2i &mousePosition) const {
    auto tempPosition = static_cast<sf::Vector2f>(mousePosition);
    return this->box_.getGlobalBounds().contains(tempPosition);
}

void Button::Render(sf::Vector2i &mousePosition, sf::RenderWindow &window) {
    if (this->Contains(mousePosition)) {
        this->box_.setFillColor(activeButtonColor);
    }
    else {
        this->box_.setFillColor(defaultButtonColor);
    }

    window.draw(this->box_);
    window.draw(this->text_);
}

size_t ButtonContainer::GetSize() {
    return this->buttons_.size();
}

void ButtonContainer::Render(sf::Vector2i &mousePosition, sf::RenderWindow &window) {
    for (auto & button : this->buttons_) {
        button.Render(mousePosition, window);
    }
}

Button &ButtonContainer::operator[](size_t index) {
    return this->buttons_[index];
}