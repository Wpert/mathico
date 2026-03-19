#pragma once

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

#include <memory>

#include <ui_lib/page.hpp>

namespace vie
{

enum class page_type : std::uint8_t
{
    main,
    sierpinski,
    barn_fern,
    polygons,
    save
};

// i have to get rid of raw pointers (!!!)

class Logic
{
  public:
    const sf::Font &font_;
    page_type pageEnum_;
    std::unique_ptr<PageManager> currentPage_;
    sf::RenderWindow *window_;
    sf::Image editableImage_;
    sf::Texture loadingTexture_;
    sf::Sprite renderingSprite_;
    sf::RenderTexture polygonTexture_;

    Logic(const sf::Font &font, sf::RenderWindow &window, PageManager *page)
        : font_(font), window_(&window), currentPage_(page), editableImage_({1, 1}), loadingTexture_(editableImage_),
          renderingSprite_(loadingTexture_)
    {
        spdlog::debug("class Logic has counstructed");
    }
    virtual ~Logic() = default;

    virtual void process(sf::RenderWindow &window) = 0;
    virtual void selectPage(page_type page) = 0;
};

class SelectPageButton : public Button
{
    Logic *m_ptr_obj_;
    page_type m_type_;

  public:
    SelectPageButton(sf::Vector2f position, sf::Vector2f size, std::string text, const sf::Font &buttonFont,
                     Logic *objPtr, page_type type)
        : Button(position, size, text, buttonFont), m_ptr_obj_(objPtr), m_type_(type)
    {
        spdlog::debug("SelectPageButton {} has constructed", std::string(text_.getString()));
    }

    ~SelectPageButton()
    {
        spdlog::debug("SelectPageButton {} has destructed", std::string(text_.getString()));
    }

    bool callFunc() const override
    {
        m_ptr_obj_->selectPage(m_type_);
        return true;
    }
};

// class ExitButton : public Button {}

} // namespace vie
