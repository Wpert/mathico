#include "polygon_page.hpp"

using namespace vie;

PolygonPage::PolygonPage(const sf::Font &font, Logic *p_logic) : PageManager(), m_ptr_logic(p_logic)
{
    sf::Vector2f position({10, 220});
    sf::Vector2f buttonSize(200, 30);

    textboxes_.addUnit(std::make_shared<TextBox>(sf::Vector2f{10, 10}, buttonSize, font, "Enter X position"));
    textboxes_.addUnit(std::make_shared<TextBox>(sf::Vector2f{10, 80}, buttonSize, font, "Enter Y position"));
    textboxes_.addUnit(std::make_shared<TextBox>(sf::Vector2f{10, 150}, buttonSize, font, "Enter N"));

    buttons_.addUnit(std::make_shared<ShowPolygonButton>(position, buttonSize, "Draw Polygon", font, this));
    buttons_.addUnit(std::make_shared<SelectPageButton>(sf::Vector2f{10, 255}, buttonSize, "Back to menu", font,
                                                        m_ptr_logic, page_type::main));
}

void PolygonPage::renderUnits(sf::RenderWindow &window)
{
    if (!isMainWindowActive_)
    {
        return;
    }

    buttons_.render(window);
    textboxes_.render(window);
    sliders_.render(window);
    window.draw(area_);
    window.draw(m_ptr_logic->renderingSprite_);
}
