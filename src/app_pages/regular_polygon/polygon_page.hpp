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

        auto& polyTexture = p_logic_->polygonTexture_;
        polyTexture = sf::RenderTexture({
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

        intPoly.ChangePosition({2.0f * width / 3.0f, height / 2.0f});
        tttPoly.ChangePosition({2.0f * width / 3.0f, height / 2.0f});

        polyTexture.draw(intPoly);
        polyTexture.draw(tttPoly);
        
        p_logic_->renderingSprite_ = sf::Sprite(polyTexture.getTexture());
        p_logic_->renderingSprite_.setPosition({220, 10});

        p_logic_->editableImage_ = polyTexture.getTexture().copyToImage();
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
