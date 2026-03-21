#pragma once

#include <spdlog/spdlog.h>

#include "fern/fern_page.hpp"
#include "main_menu/menu_page.hpp"
#include "regular_polygon/polygon_page.hpp"
#include "save_menu/save_page.hpp"
#include "sierpinski/sierpinski_page.hpp"

namespace vie
{

const sf::Color backgroundColor(22, 19, 18, 255);

class ApplicationLogic : public Logic
{
  public:
    ApplicationLogic(const sf::Font &font, sf::RenderWindow &window) : Logic(font, window, new MenuPage(font, this))
    {
        sf::Color vertexesAreaColor(15, 12, 11, 255);
        uint width = 500;
        uint height = 500;
        this->editableImage_ = sf::Image({width, height}, vertexesAreaColor);

        spdlog::debug("ApplicationLogic has constructed");
    }
    ~ApplicationLogic() override
    {
        spdlog::debug("ApplicationLogic has destructed");
    }

    void process(sf::RenderWindow &window) override
    {
        while (window.isOpen())
        {
            window.clear(backgroundColor);
            currentPage_->renderUnits(window);
            window.display();

            currentPage_->takeInputs(window);
        }
        window.close();
    }

    void selectPage(page_type page) override
    {
        switch (page)
        {
        case page_type::main: {
            spdlog::info("Selected MenuPage");
            currentPage_ = std::make_unique<MenuPage>(font_, this);
            break;
        }
        case page_type::sierpinski: {
            spdlog::info("Selected SierpinskiPage");
            currentPage_ = std::make_unique<SierpinskiPage>(font_, this);
            break;
        }
        case page_type::barn_fern: {
            spdlog::info("Selected FernPage");
            currentPage_ = std::make_unique<FernPage>(font_, this);
            break;
        }
        case page_type::polygons: {
            spdlog::info("Selected PolygonPage");
            currentPage_ = std::make_unique<PolygonPage>(font_, this);
            break;
        }
        case page_type::save: {
            spdlog::info("Selected SavePage");
            currentPage_ = std::make_unique<SavePage>(font_, this);
            break;
        }
        default:
            break;
        }
    }
};

} // namespace vie
