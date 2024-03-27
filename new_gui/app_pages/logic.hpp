#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "../page/page.hpp"

// there's the end of library i think

namespace vie {

enum class page_type {
    main,
    sierpinski,
    barn_fern,
    polygons,
    save
};

class Logic {
protected:
    page_type pageEnum_;
    std::unique_ptr<PageManager> currentPage_;
    sf::RenderWindow* window_;

public:
    sf::Image editableImage_;
    sf::Texture loadingTexture_;
    sf::Sprite renderingSprite_;
    sf::RenderTexture polygonTexture_;

    const sf::Font& font_;
    Logic(const sf::Font& font, sf::RenderWindow &window, PageManager* page)
            : font_(font), window_(&window), currentPage_(page) {
        std::cout << "Logic has constructed" << std::endl;
    }
    virtual ~Logic() {}

    virtual void Process(sf::RenderWindow& window) = 0;
    virtual void selectPage(page_type page) = 0;
};

class SelectPageButton : public Button {
    Logic* p_obj_;
    page_type type_;
public:
    SelectPageButton(sf::Vector2f position, sf::Vector2f size, std::string text,
        const sf::Font &buttonFont, Logic* objPtr, page_type type)
        : Button(position, size, text, buttonFont), p_obj_(objPtr), type_(type)
    {
        std::cout << "SelectPageButton " << text << " has constructed" << std::endl;
    }

    ~SelectPageButton() {
        std::cout << "SelectPageButton " << std::string( text_.getString() ) << " has destructed" << std::endl;
    }

    bool CallFunc() const override {
        p_obj_->selectPage(type_);
        return true;
    }
};

// class ExitButton : public Button {}


}

#endif
