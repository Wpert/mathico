#pragma once

#include <spdlog/spdlog.h>

#include "../logic.hpp"

namespace vie
{

constexpr sf::Color defaultOutlineColor(239, 62, 52, 255);
constexpr sf::Color activeOutlineColor(4, 143, 161, 255);

class SierpinskiPage : public PageManager
{
  private:
    Logic *m_ptr_logic;

    void drawTriangle()
    {
        sf::Color vertexesAreaColor(15, 12, 11, 255);
        uint width = 500;
        uint height = 500;

        m_ptr_logic->editableImage_ = sf::Image({width, height}, vertexesAreaColor);

        uint N = static_cast<uint>(sliders_[0].GetNumber());
        std::vector<sf::Vector2u> attr_points = {sf::Vector2u(0, 0), sf::Vector2u(width - 1, 0),
                                                 sf::Vector2u(width - 1, height - 1)};

        sf::Vector2u _prev = attr_points[2];
        sf::Vector2u _attr(0, 0);
        auto &img = m_ptr_logic->editableImage_;
        for (int i = 0; i < N; ++i)
        {
            int rnd_ind = std::rand() % 3;

            _attr = attr_points[rnd_ind];

            sf::Vector2u _point = {(_prev.x + _attr.x) / 2, (_prev.y + _attr.y) / 2};
            img.setPixel(_point, activeOutlineColor);

            _prev = _point;
        }

        bool isLoadedImage = m_ptr_logic->loadingTexture_.loadFromImage(img);
        if (!isLoadedImage)
        {
            spdlog::error("Couldn't load image from texture");
        }
        auto &sprite = m_ptr_logic->renderingSprite_;
        sprite = sf::Sprite(m_ptr_logic->loadingTexture_);
        sprite.setPosition({220, 10});
        spdlog::info("sierpinski fractal had been drow");
    }

    class ShowTriangleButton : public Button
    {
        SierpinskiPage *m_ptr_obj;

      public:
        ShowTriangleButton() = delete;
        ShowTriangleButton(const ShowTriangleButton &) = default;
        ShowTriangleButton(ShowTriangleButton &&) = default;
        ShowTriangleButton(sf::Vector2f position, sf::Vector2f size, const std::string &text,
                           const sf::Font &buttonFont, SierpinskiPage *objPtr)
            : Button(position, size, text, buttonFont), m_ptr_obj(objPtr)
        {
            spdlog::debug("ShowTriangleButton has constructed");
        }

        ~ShowTriangleButton() override
        {
            spdlog::debug("ShowTriangleButton has destructed");
        }

        ShowTriangleButton &operator=(const ShowTriangleButton &) = default;
        ShowTriangleButton &operator=(ShowTriangleButton &&) = default;

        bool callFunc() const override
        {
            m_ptr_obj->drawTriangle();
            return false;
        }
    };

  public:
    SierpinskiPage() = delete;
    SierpinskiPage(const sf::Font &font, Logic *p_logic);
    SierpinskiPage(const SierpinskiPage &) = default;
    SierpinskiPage(SierpinskiPage &&) = default;
    ~SierpinskiPage() override = default;

    SierpinskiPage &operator=(const SierpinskiPage &) = default;
    SierpinskiPage &operator=(SierpinskiPage &&) = default;

    void renderUnits(sf::RenderWindow &window) override;
};

} // namespace vie
