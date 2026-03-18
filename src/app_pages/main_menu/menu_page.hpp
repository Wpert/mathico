#ifndef MENU_PAGE_HPP
#define MENU_PAGE_HPP

#include "../logic.hpp"

namespace vie {

class MenuPage : public PageManager {
private:
    Logic* p_logic_;

public:
    MenuPage(const sf::Font& font, Logic* p_logic);
    ~MenuPage() = default;

    void RenderUnits(sf::RenderWindow& window) override;
};

}

#endif
