#pragma once

#include <iostream>
#include <cmath>

#include "Shape.h"
#include "Point.h"

using namespace std;

class Vector : public Shape
{
private:
    double x;
    double y;
    double z;
    double length;

public:
    Vector() {}

    Vector(Point a, Point b);

    Vector(double x, double y, double z);

    double getLength();

    void print();
};