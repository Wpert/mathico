#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include "../button/button.hpp"
#include <cstdlib>

namespace vie {

class TextBox : public Clickable {
    sf::RectangleShape box_;
    sf::Text textInBox_;
    std::string inputText_;
    sf::Text descriptionText_;
    bool focus_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    size_t enumNumber_;

    TextBox(sf::Vector2f position, sf::Vector2f size,
            const sf::Font &buttonFont, const std::string& descrText);
    ~TextBox();

    bool Contains(sf::Vector2i& mousePosition);
    void update(sf::Event& e, sf::RenderWindow& window) override;
    std::string GetString();
};

}

#endif
