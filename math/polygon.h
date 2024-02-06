#ifndef SFML_TRY_POLYGON_H
#define SFML_TRY_POLYGON_H

#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <concepts>

namespace vmath {

template<typename T>
concept Number = std::is_arithmetic<T>::value;

class Polygon : public sf::Drawable {
public:
    class Point {
        // собственный велосипед комплексных чисел с прилегающей им логикой
    private:
        double x_;
        double y_;
    public:
        Point();
        Point(double x, double y);
        template<Number T>
        Point(sf::Vector2<T> v);
        Point(sf::Vector2f v);
        Point(Point &other) = default;
        Point(const Point &other) = default;
        ~Point() = default;

        [[nodiscard]] double GetX() const;
        [[nodiscard]] double GetY() const;
        [[nodiscard]] std::pair<double, double> GetPosition() const;

        Point operator !() const;

        Point operator + (const Point &other) const;
        Point operator - (const Point &other) const;
        Point operator * (const Point &other) const;
        Point operator / (const Point &other) const;
        Point operator / (double number) const;
        Point operator * (double number) const;

        Point operator += (const Point &other);
        Point operator -= (const Point &other);
        Point operator *= (const Point &other);
        Point operator /= (const Point &other);
        Point operator /= (double number);
        Point operator *= (double number);

        bool operator == (const Point &other) const;
        bool operator != (const Point &other) const;

        // phi in radians
        void Rotate(double phi);
        void Print() const;
    };

    explicit Polygon(size_t size);
    ~Polygon() = default;

    [[nodiscard]] const size_t Size() const;

    Point& operator [] (size_t i);
    void ChangePosition(sf::Vector2f v);
    void ConsolePrint();
    // void Render(sf::RenderWindow &mainWindow);
    // void update(sf::Event& e, sf::RenderWindow& window);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    std::vector<Point> vertexes_;
};

}

#endif //SFML_TRY_POLYGON_H
