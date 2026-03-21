#include "save_page.hpp"

using namespace vie;

SavePage::SavePage(const sf::Font &font, Logic *p_logic) : PageManager(), m_ptr_logic(p_logic)
{
    sf::Vector2f position({10, 10});
    sf::Vector2f buttonSize(200, 30);

    textboxes_.addUnit(std::make_shared<TextBox>(sf::Vector2f{10, 10}, buttonSize, font, "Enter filename"));

    buttons_.addUnit(
        std::make_shared<SaveImageButton>(sf::Vector2f{10, 80}, buttonSize, "Save image", font, this, m_ptr_logic));
    buttons_.addUnit(std::make_shared<SelectPageButton>(sf::Vector2f{10, 200}, buttonSize, "Back to menu", font,
                                                        m_ptr_logic, page_type::main));
}

void SavePage::renderUnits(sf::RenderWindow &window)
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
