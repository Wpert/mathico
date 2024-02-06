#ifndef SFML_TRY_TMATH_H
#define SFML_TRY_TMATH_H

#pragma once

#include "polygon.h"
#include <cmath>
#include <iomanip>

namespace vmath {
    using Point = Polygon::Point;

    void calculate(Polygon &printable, Point core_point);

    double euclide_distance(const Point &a, const Point &b);

    Polygon::Point zerothFourierCoeff(Polygon &poly);
    Polygon::Point firstFourierCoeff(Polygon &poly);

    Polygon makeRegularPolygon(Point &point, size_t size);
    Polygon makeIntPolygon(Point &point, size_t size);

    double calculateEpsilon(Polygon &poly);

    sf::Vector2f func_1(sf::Vector2f v);
    sf::Vector2f func_2(sf::Vector2f v);
    sf::Vector2f func_3(sf::Vector2f v);
    sf::Vector2f func_4(sf::Vector2f v);

    double rand0_1();
}


#endif //SFML_TRY_TMATH_H
