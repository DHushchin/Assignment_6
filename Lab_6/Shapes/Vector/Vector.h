#pragma once

#include <iostream>
#include <cmath>

#include "../Shape/Shape.h"
#include "../Point/Point.h"

const double M_PI = 3.141592653589793238463;

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

    double getX();

    double getY();

    double getZ();

    double getLength();

    void print();
};

double scalarProduct(Vector a, Vector b);

double angleBetween(Vector a, Vector b);