#pragma once

#include <iostream>

#include "Shape.h"
#include "Point.h"

using namespace std;

class Triangle : public Shape
{
private:
    Point vertexes[3];

public:
    Triangle() {}

    Triangle(Point a, Point b, Point c);

    double getMaxX();

    double getMaxY();

    double getMaxZ();

    void print();
};