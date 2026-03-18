#include "../include/page.hpp"
#include "../tcolors.hpp"

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


PageManager::PageManager() : area_({220, 10}, {794, 580}) { };

PageManager::~PageManager() { }

void PageManager::TakeInputs(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    
    while (const std::optional<sf::Event> e = window.pollEvent()) {
        if (!e.has_value()) {
            continue;
        }

        assert(e.has_value());

        buttons_.TakeInput(e, window);
        sliders_.TakeInput(e, window);
        textboxes_.TakeInput(e, window);
        
        if (e->is<sf::Event::Closed>()) {
            window.close();
            break;
        }

        // do i really need to check it iside buttons and etc ?
        // i mean i do check here, so no need to double check
        if (
            e->is<sf::Event::MouseButtonPressed>() && 
            e->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left
        ) {
            // define which button has clicked
            for (auto& button : buttons_)
                if (button->Contains(mousePosition)) {
                    bool exitFlag = button->CallFunc();
                    if (exitFlag)
                        break;
                }
        }

        if (e->is<sf::Event::FocusLost>()) {
            isMainWindowActive_ = false;
        }
        else if (e->is<sf::Event::FocusGained>()) {
            isMainWindowActive_ = true;
        }
    }
}

void PageManager::ClearPage() {
    buttons_.Clear();
    textboxes_.Clear();
    sliders_.Clear();
}
