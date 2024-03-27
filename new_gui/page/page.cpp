#include "page.hpp"

using namespace vie;

void WorkArea::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(area_, states);
}

WorkArea::WorkArea() {}

WorkArea::WorkArea(sf::Vector2f pos, sf::Vector2f size) {
    this->area_.setSize(size);
    this->area_.setPosition(pos);
    this->area_.setFillColor(vertexesAreaColor);
}

void WorkArea::SetSize(sf::Vector2f size) {
    this->area_.setSize(size);
}
    
void WorkArea::SetColor(sf::Color clr) {
    this->area_.setFillColor(clr);
}


PageManager::PageManager() : area_({220, 10}, {794, 580}) {
    std::cout << "PageManager has constructed" << std::endl;
};
PageManager::~PageManager() {
    std::cout << "PageManager has destructed" << std::endl;
}

void PageManager::TakeInputs(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Event e;
    while (window.pollEvent(e)) {
        buttons_.TakeInput(e, window);
        sliders_.TakeInput(e, window);
        textboxes_.TakeInput(e, window);
        
        if (e.type == sf::Event::Closed) {
            window.close();
            break;
        }

        if (e.type == sf::Event::MouseButtonPressed &&
            e.mouseButton.button == sf::Mouse::Left)
        {
            // define which button has clicked
            for (auto& button : buttons_)
                if (button->Contains(mousePosition)) {
                    bool exitFlag = button->CallFunc();
                    if (exitFlag)
                        break;
                }
        }

        if (e.type == sf::Event::LostFocus) {
            isMainWindowActive_ = false;
        }
        else if (e.type == sf::Event::GainedFocus) {
            isMainWindowActive_ = true;
        }
    }
}

void PageManager::ClearPage() {
    buttons_.Clear();
    textboxes_.Clear();
    sliders_.Clear();
}
