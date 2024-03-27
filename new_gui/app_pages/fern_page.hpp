#ifndef FERN_PAGE_HPP
#define FERN_PAGE_HPP

#include "save_page.hpp"
#include "../../math/vmath.hpp"

namespace vie {

class FernPage : public PageManager {
private:
    Logic* p_logic_;

    void drawFern() {
        sf::Color vertexesAreaColor(15, 12, 11, 255);
        size_t width = 500;
        size_t height = 500;
        p_logic_->editableImage_.create(width, height, vertexesAreaColor);
        
        sf::Vector2f v = {0, 0};
        sf::Vector2f vn = {0, 0};
        size_t N = sliders_[0].GetNumber();


        for (int i = 0; i < N; ++i) {
            double decideDraw = vmath::rand0_1();
            
            if (decideDraw <= 0.01) {
                vn = vmath::func_1(v);
            }
            else if (decideDraw <= 0.86) {
                vn = vmath::func_2(v);
            }
            else if (decideDraw <= 0.93) {
                vn = vmath::func_3(v);
            }
            else {
                vn = vmath::func_4(v);
            }

            p_logic_->editableImage_.setPixel((int)(vn.x * 80) + 250, 490 - (int)(vn.y * 32), sf::Color::White);
            v = vn;
        }

        // this->loadingTexture_.loadFromImage(editableImage_);
        // this->renderingSprite_.setTexture(loadingTexture_);
        
        p_logic_->loadingTexture_.loadFromImage(p_logic_->editableImage_);
        p_logic_->renderingSprite_.setTexture(p_logic_->loadingTexture_);
        p_logic_->renderingSprite_.setPosition({220, 10});
        std::cout << "I've drow a fractal" << std::endl;
    }

    class ShowFernButton : public Button {
        FernPage* p_obj_;
    public:
        ShowFernButton(sf::Vector2f position, sf::Vector2f size, std::string text,
            const sf::Font &buttonFont, FernPage* objPtr)
            : Button(position, size, text, buttonFont), p_obj_(objPtr)
        {
            std::cout << "ShowFernButton has constructed" << std::endl;
        }

        ~ShowFernButton() {
            std::cout << "~ShowFernButton has destructed" << std::endl;
        }
        bool CallFunc() const override {
            p_obj_->drawFern();
            return false;
        }
    };

public:
    FernPage(const sf::Font& font, Logic* p_logic) : PageManager(), p_logic_(p_logic) {
        sf::Vector2f position({10, 10});
        sf::Vector2f buttonSize(200, 30);
        buttons_.AddUnit(new ShowFernButton(position, buttonSize, "Draw fern", font, this));
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