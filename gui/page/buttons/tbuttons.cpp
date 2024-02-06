#include "tbuttons.h"

using namespace vie;

Button::Button(sf::Vector2f position,
               sf::Vector2f size,
               std::string text,
               sf::Font &buttonFont,
               size_t number) {
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

    this->enumNumber_ = number;
}

bool Button::Contains(sf::Vector2i &mousePosition) const {
    auto tempPosition = static_cast<sf::Vector2f>(mousePosition);
    return this->box_.getGlobalBounds().contains(tempPosition);
}

void Button::update(sf::Event& e, sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    bool isMouseOnButton = this->Contains(mousePosition);

    if (state_ != ButtonState::CLICKED) {
        if (isMouseOnButton) {
            state_ = ButtonState::ACTIVE;
        }
        else {
            state_ = ButtonState::OFFLINE;
        }
    }

    if (e.type == sf::Event::MouseButtonPressed && 
        e.mouseButton.button == sf::Mouse::Left) {
        if (isMouseOnButton) {
            state_ = ButtonState::CLICKED;
        }
        else {
            state_ = ButtonState::OFFLINE;
        }
    }

    if (e.type == sf::Event::MouseButtonReleased && 
        e.mouseButton.button == sf::Mouse::Left) {
        if (isMouseOnButton) {
            state_ = ButtonState::ACTIVE;
        }
        else {
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

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->box_, states);
    target.draw(this->text_, states);
}


size_t ButtonContainer::GetSize() {
    return this->buttons_.size();
}

void ButtonContainer::TakeInput(sf::Event &event, sf::RenderWindow& window) {
    for (auto &button : this->buttons_) {
        button.update(event, window);
    }
}

void ButtonContainer::Render(sf::RenderWindow &window) {
    for (auto & button : this->buttons_) {
        window.draw(button);
    }
}

void ButtonContainer::AddButton(sf::Vector2f position, const std::string &text, size_t number, sf::Font &buttonFont) {
    sf::Vector2f buttonSize(200, 30);
    this->buttons_.emplace_back(position, buttonSize, text, buttonFont, number);
}

void ButtonContainer::ClearButtons() {
    this->buttons_.clear();
}
