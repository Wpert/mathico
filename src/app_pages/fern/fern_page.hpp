#pragma once

#include <spdlog/spdlog.h>

#include <math/vmath.hpp>
#include "../logic.hpp"

namespace vie {

class FernPage : public PageManager {
private:
    Logic* p_logic_;

public:
    FernPage(const sf::Font& font, Logic* p_logic);
    ~FernPage() = default;

    void RenderUnits(sf::RenderWindow& window) override;
};

}
