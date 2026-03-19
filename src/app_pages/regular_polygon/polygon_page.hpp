#pragma once

#include <spdlog/spdlog.h>

#include "../logic.hpp"
#include <math/vmath.hpp>

namespace
{
constexpr sf::Color vertexesAreaColor(15, 12, 11, 255);

constexpr float POLYGON_AREA_WIDTH = 500.0F;
constexpr float POLYGON_AREA_HEIGHT = 500.0F;
} // namespace

namespace vie
{

class PolygonPage : public PageManager
{
  private:
    Logic *m_ptr_logic;

    void drawPolygon()
    {
        using namespace vmath;
        using Point = Polygon::Point;

        float width = POLYGON_AREA_WIDTH;
        float height = POLYGON_AREA_HEIGHT;

        auto &polyTexture = m_ptr_logic->polygonTexture_;
        polyTexture = sf::RenderTexture({static_cast<uint>(width), static_cast<uint>(height)});

        int posX = std::stoi(textboxes_[0].GetString());
        int posY = std::stoi(textboxes_[1].GetString());
        int pointsN = std::stoi(textboxes_[2].GetString());

        if (pointsN < 2)
        {
            return;
        }

        Point startPoint(posX, posY);
        Polygon intPoly = makeIntPolygon(startPoint, pointsN);
        Polygon tttPoly = makeRegularPolygon(startPoint, pointsN);

        intPoly.changePosition({2.0F * width / 3.0F, height / 2.0F});
        tttPoly.changePosition({2.0F * width / 3.0F, height / 2.0F});

        polyTexture.draw(intPoly);
        polyTexture.draw(tttPoly);

        auto &sprite = m_ptr_logic->renderingSprite_;
        sprite = sf::Sprite(polyTexture.getTexture());
        sprite.setPosition({220, 10});

        m_ptr_logic->editableImage_ = polyTexture.getTexture().copyToImage();
    }

    class ShowPolygonButton : public Button
    {
        PolygonPage *m_ptr_obj;

      public:
        ShowPolygonButton(sf::Vector2f position, sf::Vector2f size, const std::string &text, const sf::Font &buttonFont,
                          PolygonPage *objPtr)
            : Button(position, size, text, buttonFont), m_ptr_obj(objPtr)
        {
            spdlog::debug("ShowPolygonButton has constructed");
        }

        ~ShowPolygonButton() override
        {
            spdlog::debug("ShowPolygonButton has destructed");
        }

        bool callFunc() const override
        {
            m_ptr_obj->drawPolygon();
            return false;
        }
    };

  public:
    PolygonPage() = delete;
    PolygonPage(const sf::Font &font, Logic *p_logic);
    PolygonPage(const PolygonPage &) = default;
    PolygonPage(PolygonPage &&) = default;
    ~PolygonPage() override = default;

    PolygonPage &operator=(const PolygonPage &) = default;
    PolygonPage &operator=(PolygonPage &&) = default;

    void renderUnits(sf::RenderWindow &window) override;
};

} // namespace vie
