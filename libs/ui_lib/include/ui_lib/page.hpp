#ifndef PAGE_HPP
#define PAGE_HPP

#include "./button.hpp"
#include "./slider.hpp"
#include "./textbox.hpp"

#include <iostream>
#include <memory>

namespace vie
{

template <typename ClickableClass> class ClickableContainer
{
    using clickClassPtr = std::shared_ptr<ClickableClass>;
    std::vector<clickClassPtr> units_;

  public:
    ClickableContainer()
    {
        // spdlog::debug("Clickable container {} has constructed", this);
    }

    ClickableContainer(const ClickableContainer &) = default;
    ClickableContainer(ClickableContainer &&) = default;

    ~ClickableContainer()
    {
        // spdlog::debug("Clickable container {} has deleted", this);
    }

    ClickableContainer &operator=(const ClickableContainer &) = default;
    ClickableContainer &operator=(ClickableContainer &&) = default;

    void addUnit(clickClassPtr &&element)
    {
        units_.push_back(element);
    }

    void takeInput(const Event &event, sf::RenderWindow &window)
    {
        for (const auto &element : units_)
        {
            assert(element.get() && "abcd");
            element->update(event, window);
        }
    }

    void render(sf::RenderWindow &window)
    {
        for (auto &element : units_)
        {
            window.draw(*element);
        }
    }

    void clear()
    {
        units_.clear();
    }
    size_t size()
    {
        return units_.size();
    }
    std::vector<clickClassPtr>::const_iterator begin()
    {
        return units_.begin();
    }
    std::vector<clickClassPtr>::const_iterator end()
    {
        return units_.end();
    }

    ClickableClass &operator[](size_t idx)
    {
        return *(units_[idx]);
    }
};

class WorkArea : public sf::Drawable
{
    sf::RectangleShape area_;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  public:
    WorkArea() = default;
    WorkArea(sf::Vector2f pos, sf::Vector2f size);
    void setSize(sf::Vector2f size);
    void setColor(sf::Color clr);
};

class PageManager
{
  protected:
    bool isMainWindowActive_ = true;
    WorkArea area_;
    ClickableContainer<Button> buttons_;
    ClickableContainer<TextBox> textboxes_;
    ClickableContainer<Slider> sliders_;

  public:
    PageManager();
    virtual ~PageManager();
    virtual void renderUnits(sf::RenderWindow &window) = 0;
    void takeInputs(sf::RenderWindow &window);
    void clearPage();
};

} // namespace vie

#endif
