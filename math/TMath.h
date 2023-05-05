#ifndef SFML_TRY_TMATH_H
#define SFML_TRY_TMATH_H

#pragma once

#include "../polygon/polygon.h"

#include <cmath>
#include <iomanip>

namespace math {
    using Point = Polygon::Point;

    void calculate(Polygon &printable, Point core_point);

    double euclide_distance(const Point &a, const Point &b);

    Polygon::Point zerothFourierCoeff(Polygon &poly);
    Polygon::Point firstFourierCoeff(Polygon &poly);

    Polygon makeRegularPolygon(Point &point, size_t size);
    Polygon makeIntPolygon(Point &point, size_t size);

    double calculateEpsilon(Polygon &poly);
}


#endif //SFML_TRY_TMATH_H
