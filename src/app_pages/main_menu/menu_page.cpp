#include "menu_page.hpp"

using namespace vie;

MenuPage::MenuPage(const sf::Font& font, Logic* p_logic) : PageManager(), p_logic_(p_logic) {
    sf::Vector2f buttonSize(200, 30);
    buttons_.AddUnit(new SelectPageButton({10, 10}, buttonSize, "Sierpinski triangle", font, p_logic_, page_type::sierpinski));
    buttons_.AddUnit(new SelectPageButton({10, 45}, buttonSize, "Barnsley fern", font, p_logic_, page_type::barn_fern));
    buttons_.AddUnit(new SelectPageButton({10, 80}, buttonSize, "Polygons", font, p_logic_, page_type::polygons));
    buttons_.AddUnit(new SelectPageButton({10, 115}, buttonSize, "Save img", font, p_logic_, page_type::save));
    
    // do we need to have this btn ?
    // buttons_.AddUnit(new ExitButton());
}

void MenuPage::RenderUnits(sf::RenderWindow& window) {
    if (!isMainWindowActive_)
        return;
    buttons_.Render(window);
    textboxes_.Render(window);
    sliders_.Render(window);
    window.draw(area_);
    // be careful about sprite thing, we dont have it
    window.draw(p_logic_->renderingSprite_);
}
