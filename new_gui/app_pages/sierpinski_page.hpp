#ifndef SIERPINSKI_PAGE_HPP
#define SIERPINSKI_PAGE_HPP

#include "menu_page.hpp"

namespace vie {

class SierpinskiPage : public PageManager {
private:
    Logic* p_logic_;

    void drawTriangle() {
        sf::Color vertexesAreaColor(15, 12, 11, 255);
        size_t width = 500;
        size_t height = 500;
        
        p_logic_->editableImage_.create(width, height, vertexesAreaColor);

        size_t N = sliders_[0].GetNumber();
        std::vector<sf::Vector2i> attr_points = {sf::Vector2i(0, 0),
                                                 sf::Vector2i(width - 1, 0),
                                                 sf::Vector2i(width - 1, height - 1)};
        
        sf::Vector2i _prev = attr_points[2];
        sf::Vector2i _attr(0, 0);
        for (int i = 0; i < N; ++i) {
            int rnd_ind = std::rand() % 3;
            
            _attr = attr_points[rnd_ind];

            sf::Vector2i _point = {(_prev.x + _attr.x) / 2, (_prev.y + _attr.y) / 2};
            p_logic_->editableImage_.setPixel(_point.x, _point.y, activeOutlineColor);

            _prev = std::move(_point);
        }
        // std::vector<sf::Uint8> imageBuffer;
        // editableImage_.saveToMemory(imageBuffer, "bmp");
        // loadingTexture_.loadFromMemory(imageBuffer.data(), imageBuffer.size(), sf::IntRect());
        p_logic_->loadingTexture_.loadFromImage(p_logic_->editableImage_);
        p_logic_->renderingSprite_.setTexture(p_logic_->loadingTexture_);
        p_logic_->renderingSprite_.setPosition({220, 10});
        std::cout << "I've drow a fractal" << std::endl;
    }

    class ShowTriangleButton : public Button {
        SierpinskiPage* p_obj_;
    public:
        ShowTriangleButton(sf::Vector2f position, sf::Vector2f size, std::string text,
            const sf::Font &buttonFont, SierpinskiPage* objPtr)
            : Button(position, size, text, buttonFont), p_obj_(objPtr)
        {
            std::cout << "ShowTriangleButton has constructed" << std::endl;
        }

        ~ShowTriangleButton() {
            std::cout << "ShowTriangleButton has destructed" << std::endl;
        }
        bool CallFunc() const override {
            p_obj_->drawTriangle();
            return false;
        }
    };

public:
    SierpinskiPage(const sf::Font& font, Logic* p_logic) : PageManager(), p_logic_(p_logic) {
        sf::Vector2f position({10, 10});
        sf::Vector2f buttonSize(200, 30);
        buttons_.AddUnit(new ShowTriangleButton(position, buttonSize, "Draw triangle", font, this));
        buttons_.AddUnit(new SelectPageButton({10, 200}, buttonSize, "Back to menu", font, p_logic_, page_type::main));

        sliders_.AddUnit(new vie::Slider({10, 45}, {210, 45}, 0, 10000, 25, font));
    }

    void RenderUnits(sf::RenderWindow& window) {
        if (!isMainWindowActive_)
            return; 
        buttons_.Render(window);
        textboxes_.Render(window);
        sliders_.Render(window);
        window.draw(area_);
        window.draw(p_logic_->renderingSprite_);
    }
};

}

#endif