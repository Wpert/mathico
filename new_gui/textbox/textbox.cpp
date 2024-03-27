#include "textbox.hpp"
using namespace vie;

TextBox::TextBox(sf::Vector2f position, sf::Vector2f size,
                 const sf::Font &buttonFont, const std::string& descrText) {
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
    this->textInBox_.setFont(buttonFont);

    this->descriptionText_.setCharacterSize(18);
    this->descriptionText_.setFont(buttonFont);
    this->descriptionText_.setString(descrText);

    this->inputText_ = "";

    this->focus_ = false;
    std::cout << "Textbox has constructed" << std::endl;
}

TextBox::~TextBox() {
    std::cout << "Textbox has destructed" << std::endl;
}

bool TextBox::Contains(sf::Vector2i &mousePosition) {
    auto tempPosition = static_cast<sf::Vector2f>(mousePosition);
    return this->box_.getGlobalBounds().contains(tempPosition);
}

void TextBox::update(sf::Event& e, sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    bool isMouseOnTextbox = this->Contains(mousePosition);

    if (e.type == sf::Event::MouseButtonPressed &&
        e.mouseButton.button == sf::Mouse::Left) {
        if (isMouseOnTextbox) {
            this->focus_ = true;
            this->box_.setFillColor(activeButtonColor);
        }
        else {
            this->focus_ = false;
            this->box_.setFillColor(defaultButtonColor);
        }
    }

    if (e.type == sf::Event::KeyPressed && this->focus_) {
        if (!this->inputText_.empty() && e.key.code == sf::Keyboard::BackSpace) {
            this->inputText_.pop_back();
        }
        if (e.key.code == sf::Keyboard::Return) {
            this->focus_ = false;
            this->box_.setFillColor(defaultButtonColor);
        }
    }

    if (e.type == sf::Event::TextEntered && this->inputText_.size() < 20) {
        if (std::isprint(e.text.unicode) && this->focus_) {
                this->inputText_ += (char)(e.text.unicode);
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