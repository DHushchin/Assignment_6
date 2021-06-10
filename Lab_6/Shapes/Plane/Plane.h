#pragma once

#include <iostream>

#include "../Point/Point.h"
#include "../Shape/Shape.h"
#include "../Line/Line.h"
#include "../Vector/Vector.h"

using namespace std;

class Plane : public Shape
{
private:
    double A;
    double B;
    double C;
    double D;

public:
    Plane();

    Plane(Point a, Point b, Point c);

    Plane(double A, double B, double C, double D);

    Plane(const Plane &plane);

    Point intersect(Line line);

    double getA() const;

    double getB() const;

    double getC() const;

    double getD() const;

    void print();
};
