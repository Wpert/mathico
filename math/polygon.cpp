#include "polygon.h"

using namespace vmath;

Polygon::Polygon(size_t size) : vertexes_(size) {}

const size_t Polygon::Size() const {
    return this->vertexes_.size();
}

Polygon::Point& Polygon::operator[](size_t i) {
    return this->vertexes_[i];
}

void Polygon::ChangePosition(sf::Vector2f v) {
    Point delta = Point(v);
    for(size_t i = 0; i < this->Size(); ++i) {
        vertexes_[i] += delta;
    }
}

void Polygon::ConsolePrint() {
    for (auto &point : this->vertexes_) {
        point.Print();

        if (*this->vertexes_.end() != point)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
}

void Polygon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    auto n_int = this->Size();
    for (size_t i = 0; i < n_int; ++i) {
        auto [x1, y1] = this->vertexes_[i].GetPosition();
        auto [x2, y2] = this->vertexes_[(i + 1) % n_int].GetPosition();
        
        
        sf::Vertex line[] =
                {
                sf::Vertex(sf::Vector2f(x1, y1)),
                sf::Vertex(sf::Vector2f(x2, y2))
                };
        target.draw(line, 2, sf::Lines);
    }
}

// void Polygon::Render(sf::RenderWindow &mainWindow) {
//     auto n_int = this->Size();
//     for (size_t i = 0; i < n_int; ++i) {
//         auto [x1, y1] = this->vertexes_[i].GetPosition();
//         auto [x2, y2] = this->vertexes_[(i + 1) % n_int].GetPosition();
//         sf::Vertex line[] =
//                 {
//                 sf::Vertex(sf::Vector2f(x1, y1)),
//                 sf::Vertex(sf::Vector2f(x2, y2))
//                 };
//         mainWindow.draw(line, 2, sf::Lines);
//     }
// }

using Point = Polygon::Point;

Point::Point() : x_(0.0), y_(0.0) {}
Point::Point(double x, double y) : x_(x), y_(y) {}
template<Number T>
Point::Point(sf::Vector2<T> v) : x_(v.x), y_(v.y) {}
Point::Point(sf::Vector2f v) : x_(v.x), y_(v.y) {}

double Point::GetX() const {
    return this->x_;
}

double Point::GetY() const {
    return this->y_;
}

std::pair<double, double> Point::GetPosition() const {
    return {this->x_, this->y_};
}

void Point::Print() const{
    std::cout << '(' << this->x_ << ", " << this->y_ << ')';
}

bool Point::operator == (const Point &other) const {
    return (abs(this->x_ - other.x_) < 1e-6) && (abs(this->y_ - other.y_) < 1e-6);
}

bool Point::operator != (const Point &other) const {
    return !(*this == other);
}

Point Point::operator * (double number) const {
    return {this->x_ * number, this->y_ * number};
}

Point Point::operator / (double number) const {
    return {this->x_ / number, this->y_ / number};
}

Point Point::operator *= (double number) {
    this->x_ *= number;
    this->y_ *= number;
    return *this;
}

Point Point::operator /= (double number) {
    this->x_ /= number;
    this->y_ /= number;
    return *this;
}

Point Point::operator + (const Point &other) const {
    return {this->x_ + other.x_, this->y_ + other.y_};
}

Point Point::operator - (const Point &other) const {
    return {this->x_ - other.x_, this->y_ - other.y_};
}

Point Point::operator += (const Point &other) {
    this->x_ += other.x_;
    this->y_ += other.y_;
    return *this;
}

Point Point::operator -= (const Point &other) {
    this->x_ -= other.x_;
    this->y_ -= other.y_;
    return *this;
}

Point Point::operator ! () const {
    return {this->x_, (-1.0) *this->y_};
}

// h = a + bi; g = c + di;
// h * g = (a * c - b * d) + (a * d + b * c) i;
Point Point::operator * (const Point &other) const {
    double x = this->x_ * other.x_ - this->y_ * other.y_;
    double y = this->x_ * other.y_ + this->y_ * other.x_;
    return {x, y};
}

// h / g = (h * !g) / (g * !g) = (h * !g) / (c * c + d * d)
Point Point::operator / (const Point &other) const {
    return (*this * (!other)) / (other.x_ * other.x_ + other.y_ * other.y_);
}

Point Point::operator *= (const Point &other) {
    *this = *this * other;
    return *this;
}

Point Point::operator /= (const Point &other) {
    *this = *this / other;
    return *this;
}

void Point::Rotate(double phi) {
    *this *= Point(cos(phi), sin(phi));
}
