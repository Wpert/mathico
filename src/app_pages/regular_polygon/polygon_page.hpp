#pragma once

#include <spdlog/spdlog.h>

#include <vmath.hpp>
#include "../logic.hpp"

namespace {
    constexpr sf::Color vertexesAreaColor(15, 12, 11, 255);
}

namespace vie {

class PolygonPage : public PageManager {
private:
    Logic* p_logic_;

    void drawPolygon() {
        using namespace vmath;
        using Point = Polygon::Point;

        float width = 500;
        float height = 500;
        // this->editableImage_.create(width, height, sf::Color(0, 0, 0));
        // auto& img = p_logic_->editableImage_ = sf::Image({width, height}, vertexesAreaColor);
        p_logic_->polygonTexture_ = sf::RenderTexture({
            static_cast<uint>(width),
            static_cast<uint>(height)
        });

        int X = std::stoi(textboxes_[0].GetString());
        int Y = std::stoi(textboxes_[1].GetString());
        int N = std::stoi(textboxes_[2].GetString());
        
        if (N < 2)
            return;

        Point startPoint(X, Y);
        Polygon intPoly = makeIntPolygon(startPoint, N);
        Polygon tttPoly = makeRegularPolygon(startPoint, N);
        // calculate(intPoly, startPoint);

        intPoly.ChangePosition({2.0f * width / 3.0f, height / 2.0f});
        tttPoly.ChangePosition({2.0f * width / 3.0f, height / 2.0f});

        p_logic_->polygonTexture_.draw(intPoly);
        p_logic_->polygonTexture_.draw(tttPoly);
        
        p_logic_->renderingSprite_ = sf::Sprite(p_logic_->polygonTexture_.getTexture());
        p_logic_->renderingSprite_.setPosition({220, 10});

        p_logic_->editableImage_ = p_logic_->polygonTexture_.getTexture().copyToImage();
    }

    class ShowPolygonButton : public Button {
        PolygonPage* p_obj_;
    public:
        ShowPolygonButton(
            sf::Vector2f position,
            sf::Vector2f size,
            std::string text,
            const sf::Font &buttonFont,
            PolygonPage* objPtr
        ) : Button(position, size, text, buttonFont),
            p_obj_(objPtr)
        {
            spdlog::debug("ShowPolygonButton has constructed");
        }

        ~ShowPolygonButton() {
            spdlog::debug("ShowPolygonButton has destructed");
        }

        bool CallFunc() const override {
            p_obj_->drawPolygon();
            return false;
        }
    };

public:
    PolygonPage(const sf::Font& font, Logic* p_logic) : PageManager(), p_logic_(p_logic) {
        sf::Vector2f position({10, 220});
        sf::Vector2f buttonSize(200, 30);

        textboxes_.AddUnit(new TextBox({10, 10}, buttonSize, font, "Enter X position"));
        textboxes_.AddUnit(new TextBox({10, 80}, buttonSize, font, "Enter Y position"));
        textboxes_.AddUnit(new TextBox({10, 150}, buttonSize, font, "Enter N"));

        buttons_.AddUnit(new ShowPolygonButton(position, buttonSize, "Draw Polygon", font, this));
        buttons_.AddUnit(new SelectPageButton({10, 255}, buttonSize, "Back to menu", font, p_logic_, page_type::main));
        // sliders_.AddUnit(new vie::Slider({10, 45}, {210, 45}, 0, 10000, 25, font));

        // pageTextBoxes_.AddName(sf::Vector2f(10, 10), "Enter X position:", mainFont_);
        // pageTextBoxes_.AddName(sf::Vector2f(10, 80), "Enter Y position:", mainFont_);
        // pageTextBoxes_.AddName(sf::Vector2f(10, 150), "Enter N:", mainFont_);

        // pageTextBoxes_.AddTextbox(sf::Vector2f(10, 45), TextBoxes::SET_X, mainFont_);
        // pageTextBoxes_.AddTextbox(sf::Vector2f(10, 115), TextBoxes::SET_Y, mainFont_);
        // pageTextBoxes_.AddTextbox(sf::Vector2f(10, 185), TextBoxes::SET_N, mainFont_);

        // pageButtons_.AddButton(sf::Vector2f(10, 220), "Draw Polygon", ButtonAction::DRAW_POLYGON, mainFont_);

        // pageButtons_.AddButton(sf::Vector2f(10, 325), "Back to menu", ButtonAction::TO_MENU_PAGE, mainFont_);
        // pageButtons_.AddButton(sf::Vector2f(10, 360), "Exit", ButtonAction::EXIT, mainFont_);
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
