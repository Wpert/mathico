#include "../include/slider.hpp"
#include "../tcolors.hpp"

#include <cmath>
#include <iostream>

using namespace vie;

void Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(line_, 2, sf::PrimitiveType::Lines);
    target.draw(circle_, states);
    target.draw(text_, states);
}

Slider::Slider(
    sf::Vector2f startPos, sf::Vector2f endPos,
    double from, double to,
    int count,
    const sf::Font &buttonFont
    ) : from_(from), diff_(to - from),
        text_(buttonFont, "") {

    circle_.setRadius(8);
    circle_.setOutlineThickness(2);
    circle_.setFillColor(defaultSliderColor);
    circle_.setOutlineColor(defaultOutlineColor);
    circle_.setPosition(startPos);


    auto bebe = sf::Vertex();
    line_[0].position = {startPos.x, startPos.y + circle_.getRadius()};
    line_[1].position = {endPos.x, startPos.y + circle_.getRadius()};

    text_.setCharacterSize(18);
    text_.setFont(buttonFont);
    // maybe try to set it in constructor
    text_.setString(std::to_string((int)from));
    text_.setPosition({startPos.x, startPos.y + 15});

    std::cout << "Slider has constructed" << std::endl;
}

Slider::~Slider() {
    std::cout << "Slider has destructed" << std::endl;
}

bool Slider::Contains(sf::Vector2i& mousePosition) {
    sf::Vector2f circlePos = circle_.getPosition();
    sf::Vector2f circleCenter = {circlePos.x + 10, circlePos.y + 10};
    double dx = mousePosition.x - circleCenter.x;
    double dy = mousePosition.y - circleCenter.y;
    return circle_.getRadius() >= std::sqrt(dx * dx + dy * dy);
}

void Slider::update(const Event& e, sf::RenderWindow& window) {
    assert(e.has_value());

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    bool isMouseOnButton = this->Contains(mousePosition);

    if (e->is<sf::Event::MouseButtonPressed>() && 
        e->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
        if (isMouseOnButton) {
            state_ = SliderState::ACTIVE;
        }
        else {
            state_ = SliderState::OFFLINE;
        }
    }

    if (e->is<sf::Event::MouseButtonReleased>() && 
        e->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
        state_ = SliderState::OFFLINE;
    }

    sf::Vector2f circlePos = circle_.getPosition();
    sf::Vector2f finalPosition({std::min(std::max((float) mousePosition.x - circle_.getRadius(),
                                                  line_[0].position.x), line_[1].position.x - 2 * circle_.getRadius()),
                                        circlePos.y});
    switch (this->state_)
    {
    case SliderState::ACTIVE:
        this->circle_.setPosition(finalPosition);
        this->circle_.setFillColor(activeSliderColor);
        this->text_.setString(std::to_string((int) (this->GetNumber())));
        break;
    default:
        this->circle_.setFillColor(defaultSliderColor);
        break;
    }
}

double Slider::GetNumber() {
    double mx = line_[0].position.x + 2 * circle_.getRadius() - line_[1].position.x;
    double my = line_[0].position.y - line_[1].position.y;
    
    sf::Vector2f circlePos = circle_.getPosition();
    double cx = circlePos.x - line_[0].position.x;
    double cy = circlePos.y - line_[0].position.y + circle_.getRadius();

    double proportion = std::sqrt(cx * cx + cy * cy) / std::sqrt(mx * mx + my * my);

    return from_ + diff_ * proportion;
}