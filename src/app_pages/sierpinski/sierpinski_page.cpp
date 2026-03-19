#include "sierpinski_page.hpp"

using namespace vie;

SierpinskiPage::SierpinskiPage(const sf::Font &font, Logic *p_logic) : PageManager(), m_ptr_logic(p_logic)
{
    spdlog::debug("Sierpinski page is constructing");

    sf::Vector2f position({10, 10});
    sf::Vector2f buttonSize(200, 30);
    buttons_.addUnit(new ShowTriangleButton(position, buttonSize, "Draw triangle", font, this));
    buttons_.addUnit(new SelectPageButton({10, 200}, buttonSize, "Back to menu", font, m_ptr_logic, page_type::main));
    sliders_.addUnit(new vie::Slider({10, 45}, {210, 45}, 0, 10000, 25, font));
}

void SierpinskiPage::renderUnits(sf::RenderWindow &window)
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
