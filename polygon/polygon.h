#ifndef SFML_TRY_POLYGON_H
#define SFML_TRY_POLYGON_H

#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

class Polygon {
public:
    class Point {
    private:
        double x_;
        double y_;
    public:
        Point();
        Point(double x, double y);
        Point(Point &other) = default;
        Point(const Point &other) = default;
        ~Point() = default;

        [[nodiscard]] double GetX() const;
        [[nodiscard]] double GetY() const;
        [[nodiscard]] std::pair<double, double> GetXY() const;

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

    [[nodiscard]] size_t Size() const;

    Point& operator [] (size_t i);

    void Print();
    void Draw(sf::RenderWindow &mainWindow);

private:
    std::vector<Point> vertexes_;
};


#endif //SFML_TRY_POLYGON_H
