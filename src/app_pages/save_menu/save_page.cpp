#include "save_page.hpp"

using namespace vie;

SavePage::SavePage(
    const sf::Font& font,
    Logic* p_logic
) : PageManager(),
    p_logic_(p_logic)
{
    sf::Vector2f position({10, 10});
    sf::Vector2f buttonSize(200, 30);

    textboxes_.AddUnit(new TextBox({10, 10}, buttonSize, font, "Enter filename"));

    buttons_.AddUnit(new SaveImageButton({10, 80}, buttonSize, "Save image", font, this, p_logic_));
    buttons_.AddUnit(new SelectPageButton({10, 200}, buttonSize, "Back to menu", font, p_logic_, page_type::main));
}

void SavePage::RenderUnits(sf::RenderWindow& window) {
    if (!isMainWindowActive_)
        return;

    buttons_.Render(window);
    textboxes_.Render(window);
    sliders_.Render(window);
    window.draw(area_);
    window.draw(p_logic_->renderingSprite_);
}
