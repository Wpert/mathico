#include "vmath.h"

using namespace vmath;

double vmath::euclide_distance(const Point &a, const Point &b) {
    return sqrt((a.GetX() - b.GetX()) * (a.GetX() - b.GetX()) +
                (a.GetY() - b.GetY()) * (a.GetY() - b.GetY()));
}

Polygon vmath::makeRegularPolygon(Point &point, size_t size) {
    auto n = (double) size;

    Polygon reg_poly(size); // правльный n-угольник, построенный по данному отрезку
    // первая вершина правильного n-угольника -- начало координат
    reg_poly[1] = point;          // вторая вершина правильного n-угольника

    for(int i = 2; i < size; ++i) { // вроде плохо конструирует
        reg_poly[i] = point;     // поворачиваем заданный вектор на угол n-угольника
        // и откладываем его от предыдущей вершины
        reg_poly[i].Rotate((i - 1) * (2 * M_PI / n)); // вращение начального вектора
        reg_poly[i] += reg_poly[i - 1]; // достраивание до i+1 вершины
    }

    return reg_poly;
}

Polygon vmath::makeIntPolygon(Point &point, size_t size) {
    Polygon int_poly(size); // целочисленный n-угольник

    // построение правильного n-угольника:
    Polygon reg_poly = makeRegularPolygon(point, size);

    for(int i = 1; i < size; ++i){
        // округление точек правильного n-угольника до ближайших
        int_poly[i] = {round(reg_poly[i].GetX()),
                       round(reg_poly[i].GetY())};
    }
    return int_poly;
}

Polygon::Point vmath::zerothFourierCoeff(Polygon &poly) {
    auto n = (double) poly.Size();

    Point Coeff0;
    for (size_t i = 0; i < poly.Size(); ++i) {     // "центр масс"
        Coeff0 += poly[i];                 // сумма вершин
    }                                   // по всем координатам
    Coeff0 /= n;                 // вычисление среднего арифметического

    return Coeff0;
}

Polygon::Point vmath::firstFourierCoeff(Polygon &poly) {
    auto n_int = poly.Size();
    auto n = (double) n_int;

    Point Coeff1;      // среднее арифметическое отклонений
    for(int i = 0; i < n_int; ++i){     // каждой вершины от "центра масс"
        Point temp = poly[i];
        temp.Rotate(-1 * i * 2 * M_PI / n);
        // соответственно посчитали отклонение и прибавили его
        Coeff1 += temp;
    }
    // осталось вычислить среднее арифметическое этого отклонения
    Coeff1 /= n;
    return Coeff1;
}

double vmath::calculateEpsilon(Polygon &poly) {
    auto n = (double) poly.Size();
    auto n_int = poly.Size();

    // предподсчет для построения ближайшего n-угольника
    Point Coeff0 = zerothFourierCoeff(poly);    // среднее арифметическое по всем точкам
    // 1-ый коэффиент фурье:
    Point Coeff1 = firstFourierCoeff(poly);

    // воостановление правильного ближайшего n-угольника:
    Polygon near_poly(n_int); // ближай1ший правльный n-угольник
    for(int i = 0; i < n_int; ++i) {
        auto temp = Coeff1;       // по коэффициентам фурье
        temp.Rotate(i * 2 * M_PI / n);
        near_poly[i] = Coeff0 + temp;
    }

    // вычисление приближения построенного многоугольника и ближайшего к нему:
    double eps = 0;      // максимальное значение приближения у n-угольника
    for(int i = 0; i < n_int; ++i) {     // шагаем по соотв вершинам и считаем расстояние
        eps = std::max(eps, euclide_distance(poly[i], near_poly[i]));
    }
    return eps;
}

void vmath::calculate(Polygon &poly, Point point) {
    auto n_int = poly.Size();
    //построение целочисленного n-угольника:
    auto int_poly = makeIntPolygon(point, n_int);
    auto eps = calculateEpsilon(int_poly);
    // вывод информации в консоль

    std::cout << std::fixed << std::setprecision(0);
    std::cout << "Cordinates of new integer " << n_int << "-gon: " << std::endl;

    // вывод точек правильного n-угольника на экран:
    int_poly.ConsolePrint();

    poly = int_poly;

    // вывод значения приближения n-угольника
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "eps = " << eps << std::endl;
}

sf::Vector2f vmath::func_1(sf::Vector2f v) {
    sf::Vector2f tmp;
    tmp.x = 0;
    tmp.y = 0.16 * v.y;
    return tmp;
}

sf::Vector2f vmath::func_2(sf::Vector2f v) {
    sf::Vector2f tmp;
    tmp.x = 0.85 * v.x + 0.04 * v.y;
    tmp.y = -0.04 * v.x + 0.85 * v.y + 1.6;
    return tmp;
}

sf::Vector2f vmath::func_3(sf::Vector2f v) {
    sf::Vector2f tmp;
    tmp.x = 0.2 * v.x - 0.26 * v.y;
    tmp.y = 0.23 * v.x + 0.22 * v.y + 1.6;
    return tmp;
}

sf::Vector2f vmath::func_4(sf::Vector2f v) {
    sf::Vector2f tmp;
    tmp.x = -0.15 * v.x + 0.28 * v.y;
    tmp.y = 0.26 * v.x + 0.24 * v.y + 0.44;
    return tmp;
}

double vmath::rand0_1() {
    return (double)rand() / (RAND_MAX + 1.0);
}