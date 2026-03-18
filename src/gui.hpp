#pragma once

#include <spdlog/spdlog.h>

#include "app_pages/main_menu/menu_page.hpp"
#include "app_pages/sierpinski/sierpinski_page.hpp"
#include "app_pages/fern/fern_page.hpp"
#include "app_pages/regular_polygon/polygon_page.hpp"
#include "app_pages/save_menu/save_page.hpp"

namespace vie {

const sf::Color backgroundColor(22, 19, 18, 255);

class ApplicationLogic : public Logic {
    public:
    ApplicationLogic(
        const sf::Font& font,
        sf::RenderWindow &window
    ) : Logic(font, window, new MenuPage(font, this)) {
        sf::Color vertexesAreaColor(15, 12, 11, 255);
        uint width = 500;
        uint height = 500;
        this->editableImage_ = sf::Image({width, height}, vertexesAreaColor);

        spdlog::debug("ApplicationLogic has constructed");
    }
    ~ApplicationLogic() {
        spdlog::debug("ApplicationLogic has destructed");
    }

    void Process(sf::RenderWindow& window) override {
        while (window.isOpen()) {
            currentPage_->TakeInputs(window); 

            window.clear(backgroundColor);
            currentPage_->RenderUnits(window);\
            window.display();
        }
        window.close();
    }

    void selectPage(page_type page) override {
        switch (page)
        {
        case page_type::main: {
            spdlog::info("Selected MenuPage");
            currentPage_.reset(new MenuPage(this->font_, this));
            break;
        }
        case page_type::sierpinski: {
            spdlog::info("Selected SierpinskiPage");
            currentPage_.reset(new SierpinskiPage(this->font_, this));
            break;
        }
        case page_type::barn_fern: {
            spdlog::info("Selected FernPage");
            currentPage_.reset(new FernPage(this->font_, this));
            break;
        }
        case page_type::polygons: {
            spdlog::info("Selected PolygonPage");
            currentPage_.reset(new PolygonPage(this->font_, this));
            break;
        }
        case page_type::save: {
            spdlog::info("Selected SavePage");
            currentPage_.reset(new SavePage(this->font_, this));
            break;
        }
        default:
            break;
        }
    }

};

}
