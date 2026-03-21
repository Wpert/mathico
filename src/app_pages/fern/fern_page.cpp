#include "fern_page.hpp"

#include <ui_lib/button.hpp>
#include <ui_lib/slider.hpp>

using namespace vie;

namespace
{

void drawFern(sf::Image &img, sf::Sprite &renderingSprite, sf::Texture &texture, uint pointsNumber)
{
    spdlog::info("fern page is generating");
    sf::Color vertexesAreaColor(15, 12, 11, 255);
    uint width = 500;
    uint height = 500;

    img = sf::Image({width, height}, vertexesAreaColor);

    sf::Vector2f v = {0, 0};
    sf::Vector2f vn = {0, 0};

    for (int i = 0; i < pointsNumber; ++i)
    {
        double decideDraw = vmath::rand0_1();

        if (decideDraw <= 0.01)
        {
            vn = vmath::func_1(v);
        }
        else if (decideDraw <= 0.86)
        {
            vn = vmath::func_2(v);
        }
        else if (decideDraw <= 0.93)
        {
            vn = vmath::func_3(v);
        }
        else
        {
            vn = vmath::func_4(v);
        }

        auto pos = sf::Vector2u({static_cast<uint>((int)(vn.x * 80) + 250), static_cast<uint>(490 - (int)(vn.y * 32))});
        img.setPixel(pos, sf::Color::White);
        v = vn;
    }

    auto [len, wid] = texture.getSize();

    spdlog::info("fern texture len: {}, width: {}", len, wid);

    bool isLoadedImage = texture.loadFromImage(img);
    if (!isLoadedImage)
    {
        spdlog::error("Couldn't load texture from image");
    }
    renderingSprite = sf::Sprite(texture);
    renderingSprite.setPosition({220, 10});
    spdlog::info("Fern fractal had been drow with N = {}  points", pointsNumber);
}

class ShowFernButton : public Button
{
    sf::Image &img_;
    sf::Sprite &sprite_;
    sf::Texture &texture_;
    vie::Slider &slider_;

  public:
    ShowFernButton(sf::Vector2f position, sf::Vector2f size, std::string text, const sf::Font &buttonFont,
                   sf::Image &img, sf::Sprite &sprite, sf::Texture &texture, vie::Slider &slider)
        : Button(position, size, text, buttonFont), img_(img), sprite_(sprite), texture_(texture), slider_(slider)
    {
        spdlog::debug("ShowFernButton has constructed");
    }

    ~ShowFernButton()
    {
        spdlog::debug("~ShowFernButton has destructed");
    }

    bool callFunc() const override
    {
        drawFern(img_, sprite_, texture_, slider_.GetNumber());
        return false;
    }
};

} // namespace

FernPage::FernPage(const sf::Font &font, Logic *p_logic) : PageManager(), p_logic_(p_logic)
{
    sf::Vector2f position({10, 10});
    sf::Vector2f buttonSize(200, 30);

    auto &img = p_logic_->editableImage_;
    auto &sprite = p_logic_->renderingSprite_;
    auto &texture = p_logic_->loadingTexture_;

    sliders_.addUnit(std::make_shared<vie::Slider>(sf::Vector2f{10, 45}, sf::Vector2f{210, 45}, 0, 10000, 25, font));

    buttons_.addUnit(
        std::make_shared<ShowFernButton>(position, buttonSize, "Draw fern", font, img, sprite, texture, sliders_[0]));
    buttons_.addUnit(std::make_shared<SelectPageButton>(sf::Vector2f{10, 200}, buttonSize, "Back to menu", font,
                                                        p_logic_, page_type::main));

    spdlog::info("FernPage has constructed");
}

void FernPage::renderUnits(sf::RenderWindow &window)
{
    if (!isMainWindowActive_)
    {
        return;
    }

    buttons_.render(window);
    textboxes_.render(window);
    sliders_.render(window);
    window.draw(area_);
    window.draw(p_logic_->renderingSprite_);
}
