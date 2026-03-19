#ifndef MENU_PAGE_HPP
#define MENU_PAGE_HPP

#include "../logic.hpp"

namespace vie
{

class MenuPage : public PageManager
{
  private:
    Logic *m_ptr_logic;

  public:
    MenuPage() = delete;
    MenuPage(const sf::Font &font, Logic *p_logic);
    MenuPage(const MenuPage &) = default;
    MenuPage(MenuPage &&) = default;
    ~MenuPage() override = default;

    MenuPage &operator=(const MenuPage &) = default;
    MenuPage &operator=(MenuPage &&) = default;

    void renderUnits(sf::RenderWindow &window) override;
};

} // namespace vie

#endif
