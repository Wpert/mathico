#include "../include/textbox.hpp"
#include "../tcolors.hpp"

#include <iostream>

using namespace vie;

TextBox::TextBox(
    sf::Vector2f position,
    sf::Vector2f size,
    const sf::Font &textboxFont,
    const std::string& descrText
) : descriptionText_(textboxFont, descrText),
    textInBox_(textboxFont, "")
{
    {
        this->descriptionText_.setPosition(position);
        this->box_.setSize(size);
        position.y += 35;
        this->box_.setPosition(position);
        sf::Vector2f tempPosition = sf::Vector2f(position.x + 5, position.y + 5);
        this->textInBox_.setPosition(tempPosition);
    }
    this->box_.setFillColor(defaultButtonColor);

    this->textInBox_.setCharacterSize(18);
    this->descriptionText_.setCharacterSize(18);

    this->inputText_ = "";

    this->focus_ = false;
}

TextBox::~TextBox() { }

bool TextBox::Contains(sf::Vector2i &mousePosition) {
    auto tempPosition = static_cast<sf::Vector2f>(mousePosition);
    return this->box_.getGlobalBounds().contains(tempPosition);
}

void TextBox::update(const Event& e, sf::RenderWindow& window) {
    assert(e.has_value());

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    bool isMouseOnTextbox = this->Contains(mousePosition);

    if (e->is<sf::Event::MouseButtonPressed>() &&
        e->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
        if (isMouseOnTextbox) {
            this->focus_ = true;
            this->box_.setFillColor(activeButtonColor);
        }
        else {
            this->focus_ = false;
            this->box_.setFillColor(defaultButtonColor);
        }
    }

    if (e->is<sf::Event::KeyPressed>() && this->focus_) {
        auto keyCode = e->getIf<sf::Event::KeyPressed>()->code;
        if (
            !this->inputText_.empty() &&
            keyCode == sf::Keyboard::Key::Backspace
        ) {
            this->inputText_.pop_back();
        }
        if (keyCode == sf::Keyboard::Key::Enter) {
            this->focus_ = false;
            this->box_.setFillColor(defaultButtonColor);
        }
    }

    if (
        e->is<sf::Event::TextEntered>() &&
        this->inputText_.size() < 20
    ) {
        auto rawInput = e->getIf<sf::Event::TextEntered>()->unicode;
        if (std::isprint(rawInput) && this->focus_) {
                this->inputText_ += (char)(rawInput);
        }

        this->textInBox_.setString(this->inputText_);
    }
}

void TextBox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->descriptionText_, states);
    target.draw(this->box_, states);
    target.draw(this->textInBox_, states);
}


std::string TextBox::GetString() {
    return this->inputText_;
}