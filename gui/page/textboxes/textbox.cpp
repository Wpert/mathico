#include "textbox.h"

using namespace vie;

TextBox::TextBox(sf::Vector2f position, sf::Vector2f size, sf::Font &buttonFont, size_t number) {
    enumNumber_ = number;

    this->box_.setSize(size);
    {
        this->box_.setPosition(position);
        sf::Vector2f tempPosition = sf::Vector2f(position.x + 5, position.y + 5);
        this->text_.setPosition(tempPosition);
    }
    this->box_.setFillColor(defaultButtonColor);

    this->text_.setCharacterSize(18);
    this->text_.setFont(buttonFont);

    this->inputText_ = "";

    this->focus_ = false;
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

        this->text_.setString(this->inputText_);
    }
}

void TextBox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->box_, states);
    target.draw(this->text_, states);
}


std::string TextBox::GetString() {
    return this->inputText_;
}

std::string TextBoxContainer::GetString(size_t num) {
    for (auto &textbox : this->textboxes_)
        if (textbox.enumNumber_ == num) {
            return textbox.GetString();
        }
    return "";
}

void TextBoxContainer::TakeInput(sf::Event &event, sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    for (auto &textBox : this->textboxes_) {
        textBox.update(event, window);
    }
}

void TextBoxContainer::Render(sf::RenderWindow &window) {
    for (auto &name : this->names_) {
        window.draw(name);
    }
    for (auto &textbox : this->textboxes_) {
        window.draw(textbox);
    }
}

void TextBoxContainer::AddName(sf::Vector2f position, const std::string &text, sf::Font &textboxFont) {
    sf::Text setFilename(text, textboxFont, textCharSize_);
    position += {5, 5};
    setFilename.setPosition(position);

    this->names_.push_back(setFilename);
}

void TextBoxContainer::AddTextbox(sf::Vector2f position, size_t number, sf::Font &textboxFont) {
    sf::Vector2f textboxSize(200, 30);
    this->textboxes_.emplace_back(position, textboxSize, textboxFont, number);
}

void TextBoxContainer::ClearTextboxes() {
    this->textboxes_.clear();
    this->names_.clear();
}