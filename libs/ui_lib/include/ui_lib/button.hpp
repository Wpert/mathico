#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

#include "../clickable.hpp"

namespace vie
{

namespace ButtonState
{
enum
{
    OFFLINE,
    CLICKED,
    ACTIVE
};
} // namespace ButtonState

class Button : public Clickable
{
  protected:
    sf::RectangleShape box_;
    sf::Text text_;
    short state_ = ButtonState::OFFLINE;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  public:
    Button(sf::Vector2f position, sf::Vector2f size, std::string text, const sf::Font &buttonFont);
    virtual ~Button()
    {
    }

    virtual bool callFunc() const = 0;

    bool contains(sf::Vector2i &mousePosition) const;
    void update(const Event &e, sf::RenderWindow &window) override;
};

} // namespace vie

#endif
