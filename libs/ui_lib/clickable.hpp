#pragma once

#include <SFML/Graphics.hpp>

namespace vie
{

using Event = std::optional<sf::Event>;

class Clickable : public sf::Drawable
{
  public:
    virtual ~Clickable() = default;
    virtual void update(const Event &e, sf::RenderWindow &window) = 0;
};

} // namespace vie
