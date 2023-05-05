#include "polygon.h"

Polygon::Polygon(size_t size) : vertexes_(size)
{
//    std::cout << "Polygon has constructed" << std::endl;
}

size_t Polygon::Size() const {
    return this->vertexes_.size();
}

Polygon::Point& Polygon::operator[](size_t i) {
    return this->vertexes_[i];
}

void Polygon::Print() {
    for (auto &point : this->vertexes_) {
        point.Print();

        if (this->vertexes_[this->Size() - 1] != point)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
}

void Polygon::Draw(sf::RenderWindow &mainWindow) {
    auto n_int = this->Size();
    for (size_t i = 0; i < n_int; ++i) {
        auto [x1, y1] = this->vertexes_[i].GetXY();
        auto [x2, y2] = this->vertexes_[(i + 1) % n_int].GetXY();
        sf::Vertex line[] =
                {
                sf::Vertex(sf::Vector2f(x1, y1)),
                sf::Vertex(sf::Vector2f(x2, y2))
                };
        mainWindow.draw(line, 2, sf::Lines);
    }
}
