#ifndef GUI_HPP
#define GUI_HPP

#include "app_pages/main_menu/menu_page.hpp"
#include "app_pages/sierpinski/sierpinski_page.hpp"

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
        std::cout << "ApplicationLogic constructor" << std::endl;
    }
    ~ApplicationLogic() {
        std::cout << "~ApplicationLogic" << std::endl;
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
        std::cout << "---selectedPage---" << std::endl;
        switch (page)
        {
        case page_type::main:
            currentPage_.reset(new MenuPage(this->font_, this));
            break;
        case page_type::sierpinski: {
            std::cout << "fell into switch page -> sierp" << std::endl;
            currentPage_.reset(new SierpinskiPage(this->font_, this));
            break;
        }
        // case page_type::barn_fern:
        //     currentPage_.reset(new FernPage(this->font_, this));
        //     break;
        // case page_type::polygons:
        //     currentPage_.reset(new PolygonPage(this->font_, this));
        //     break;
        // case page_type::save:
        //     currentPage_.reset(new SavePage(this->font_, this));
        //     break;
        default:
            break;
        }
    }

};

}

#endif
