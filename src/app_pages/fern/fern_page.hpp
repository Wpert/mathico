#pragma once

#include <spdlog/spdlog.h>

#include "../logic.hpp"
#include <math/vmath.hpp>

namespace vie
{

class FernPage : public PageManager
{
  private:
    Logic *p_logic_;

  public:
    FernPage() = delete;
    FernPage(const sf::Font &font, Logic *p_logic);
    FernPage(const FernPage &) = default;
    FernPage(FernPage &&) = default;
    ~FernPage() override = default;

    FernPage &operator=(const FernPage &) = default;
    FernPage &operator=(FernPage &&) = default;

    void renderUnits(sf::RenderWindow &window) override;
};

} // namespace vie
