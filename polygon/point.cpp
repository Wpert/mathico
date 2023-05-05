#include "polygon.h"

Polygon::Point::Point() : x_(0.0), y_(0.0)
{
//    std::cout << "Zero-Point has constructed" << std::endl;
}

Polygon::Point::Point(double x, double y) : x_(x), y_(y)
{
//    std::cout << "Point has constructed" << std::endl;
}

double Polygon::Point::GetX() const {
    return this->x_;
}

double Polygon::Point::GetY() const {
    return this->y_;
}

std::pair<double, double> Polygon::Point::GetXY() const {
    return {this->x_, this->y_};
}

void Polygon::Point::Print() const{
    std::cout << '(' << this->x_ << ", " << this->y_ << ')';
}

bool Polygon::Point::operator == (const Point &other) const {
    return (abs(this->x_ - other.x_) < 1e-6) && (abs(this->y_ - other.y_) < 1e-6);
}

bool Polygon::Point::operator != (const Point &other) const {
    return !(*this == other);
}

Polygon::Point Polygon::Point::operator * (double number) const {
    return {this->x_ * number, this->y_ * number};
}

Polygon::Point Polygon::Point::operator / (double number) const {
    return {this->x_ / number, this->y_ / number};
}

Polygon::Point Polygon::Point::operator *= (double number) {
    this->x_ *= number;
    this->y_ *= number;
    return *this;
}

Polygon::Point Polygon::Point::operator /= (double number) {
    this->x_ /= number;
    this->y_ /= number;
    return *this;
}

Polygon::Point Polygon::Point::operator + (const Polygon::Point &other) const {
    return {this->x_ + other.x_, this->y_ + other.y_};
}

Polygon::Point Polygon::Point::operator - (const Polygon::Point &other) const {
    return {this->x_ - other.x_, this->y_ - other.y_};
}

Polygon::Point Polygon::Point::operator += (const Polygon::Point &other) {
    this->x_ += other.x_;
    this->y_ += other.y_;
    return *this;
}

Polygon::Point Polygon::Point::operator -= (const Polygon::Point &other) {
    this->x_ -= other.x_;
    this->y_ -= other.y_;
    return *this;
}

Polygon::Point Polygon::Point::operator ! () const {
    return {this->x_, (-1.0) *this->y_};
}

// h = a + bi; g = c + di;
// h * g = (a * c - b * d) + (a * d + b * c) i;
Polygon::Point Polygon::Point::operator * (const Polygon::Point &other) const {
    double x = this->x_ * other.x_ - this->y_ * other.y_;
    double y = this->x_ * other.y_ + this->y_ * other.x_;
    return {x, y};
}

// h / g = (h * !g) / (g * !g) = (h * !g) / (c * c + d * d)
Polygon::Point Polygon::Point::operator / (const Polygon::Point &other) const {
    return (*this * (!other)) / (other.x_ * other.x_ + other.y_ * other.y_);
}

Polygon::Point Polygon::Point::operator *= (const Polygon::Point &other) {
    *this = *this * other;
    return *this;
}

Polygon::Point Polygon::Point::operator /= (const Polygon::Point &other) {
    *this = *this / other;
    return *this;
}

void Polygon::Point::Rotate(double phi) {
    *this *= Point(cos(phi), sin(phi));
}
