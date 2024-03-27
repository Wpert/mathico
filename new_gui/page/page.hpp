#ifndef PAGE_HPP
#define PAGE_HPP

#include "../utility.hpp"
#include "../button/button.hpp"
#include "../slider/slider.hpp"
#include "../textbox/textbox.hpp"

namespace vie {

template<typename ClickableClass>
class ClickableContainer {
    std::vector<ClickableClass*> units_;
public:
    ClickableContainer() {
        std::cout << "Clickable container " << this << " has constructed" << std::endl;
    }
    ~ClickableContainer() {
        for (size_t i = 0; i < this->units_.size(); ++i)
            delete units_[i];
        
        units_.clear();
        std::cout << "Clickable container " << this << " has deleted" << std::endl;
    }

    void AddUnit(ClickableClass* element) {
        units_.push_back(element);
    }

    void TakeInput(sf::Event &event, sf::RenderWindow& window) {
        for (auto& element : units_)
            element->update(event, window);
    }

    void Render(sf::RenderWindow &window) {
        for (auto& element : units_) {
            window.draw(*element);
        }
    }

    void Clear() { units_.clear(); }
    size_t size() { return units_.size(); }
    std::vector<ClickableClass*>::const_iterator begin() { return units_.begin(); }
    std::vector<ClickableClass*>::const_iterator end() { return units_.end(); }

    ClickableClass& operator[](size_t idx) { return *(units_[idx]); }
};

class WorkArea : public sf::Drawable {
    sf::RectangleShape area_;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    WorkArea();
    WorkArea(sf::Vector2f pos, sf::Vector2f size);
    void SetSize(sf::Vector2f size);
    void SetColor(sf::Color clr);
};

class PageManager {
protected:
    bool isMainWindowActive_ = true;
    WorkArea area_;
    ClickableContainer<Button> buttons_;
    ClickableContainer<TextBox> textboxes_;
    ClickableContainer<Slider> sliders_;
public:
    PageManager();
    virtual ~PageManager();
    virtual void RenderUnits(sf::RenderWindow& window) = 0;
    void TakeInputs(sf::RenderWindow& window);
    void ClearPage();
};

}

#endif
