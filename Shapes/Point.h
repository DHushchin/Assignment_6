#pragma once

#include <iostream>

#include "Shape.h"

using namespace std;

class Point : public Shape
{
private:
    double x;
    double y;
    double z;

public:
    Point();

    Point(const Point &point);

    Point(double x, double y, double z);

    void print();

    double getX() const;

    double getY() const;

    double getZ() const;
};