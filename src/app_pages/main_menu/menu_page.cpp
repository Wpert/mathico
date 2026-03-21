#include "menu_page.hpp"

using namespace vie;

// emplace or push back
// std::unique_ptr
// thats cringe btw
MenuPage::MenuPage(const sf::Font &font, Logic *p_logic) : PageManager(), m_ptr_logic(p_logic)
{
    sf::Vector2f buttonSize(200, 30);
    buttons_.addUnit(std::make_shared<SelectPageButton>(sf::Vector2f{10, 10}, buttonSize, "Sierpinski triangle", font,
                                                        p_logic, page_type::sierpinski));
    buttons_.addUnit(std::make_shared<SelectPageButton>(sf::Vector2f{10, 45}, buttonSize, "Barnsley fern", font,
                                                        p_logic, page_type::barn_fern));
    buttons_.addUnit(std::make_shared<SelectPageButton>(sf::Vector2f{10, 80}, buttonSize, "Polygons", font, p_logic,
                                                        page_type::polygons));
    buttons_.addUnit(std::make_shared<SelectPageButton>(sf::Vector2f{10, 115}, buttonSize, "Save img", font, p_logic,
                                                        page_type::save));
}

// this thing is very similar from page to page
// why do i need to write it ?
void MenuPage::renderUnits(sf::RenderWindow &window)
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
