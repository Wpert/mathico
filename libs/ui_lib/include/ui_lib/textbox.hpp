#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <SFML/Graphics.hpp>

#include "../clickable.hpp"

namespace vie
{

class TextBox : public Clickable
{
    sf::RectangleShape box_;
    sf::Text textInBox_;
    std::string inputText_;
    sf::Text descriptionText_;
    bool focus_;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  public:
    size_t enumNumber_;

    TextBox(sf::Vector2f position, sf::Vector2f size, const sf::Font &textboxFont, const std::string &descrText);
    ~TextBox();

    bool Contains(sf::Vector2i &mousePosition);
    void update(const Event &e, sf::RenderWindow &window) override;
    std::string GetString();
};

} // namespace vie

#endif
