#include "textbox.h"

TextBox::TextBox(sf::Vector2f position, sf::Vector2f size, sf::Font &buttonFont) {
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

void TextBox::TakeInput(sf::Vector2i &mousePosition, sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (this->Contains(mousePosition)) {
            this->focus_ = true;
            this->box_.setFillColor(activeButtonColor);
        }
        else {
            this->focus_ = false;
            this->box_.setFillColor(defaultButtonColor);
        }

    }
    if (event.type == sf::Event::KeyPressed && this->focus_) {
        if (!this->inputText_.empty() && event.key.code == sf::Keyboard::BackSpace) {
            this->inputText_.pop_back();
        }
        if (event.key.code == sf::Keyboard::Return){
            this->focus_ = false;
            this->box_.setFillColor(defaultButtonColor);
        }
    }

    if (event.type == sf::Event::TextEntered && this->inputText_.size() < 4) {
        if (std::isprint(event.text.unicode) && this->focus_) {
            if ('0' <= (char)(event.text.unicode) && (char)(event.text.unicode) <= '9')
                this->inputText_ += (char)(event.text.unicode);
        }

        this->text_.setString(this->inputText_);
    }
}

void TextBox::Render(sf::RenderWindow &window) {
    window.draw(this->box_);
    window.draw(this->text_);
}

std::string TextBox::GetString() {
    return this->inputText_;
}

size_t TextBoxContainer::GetSize() const {
    return this->textboxes_.size();
}

std::string TextBoxContainer::GetString(size_t num) {
    return this->textboxes_[num].GetString();
}

void TextBoxContainer::TakeInput(sf::Vector2i &mousePosition, sf::Event &event) {
    for (auto &textBox : this->textboxes_) {
        textBox.TakeInput(mousePosition, event);
    }
}

void TextBoxContainer::Render(sf::RenderWindow &window) {
    for (auto &name : this->names_) {
        window.draw(name);
    }
    for (auto &textbox : this->textboxes_) {
        textbox.Render(window);
    }
}

TextBox &TextBoxContainer::operator [] (size_t index) {
    return this->textboxes_[index];
}