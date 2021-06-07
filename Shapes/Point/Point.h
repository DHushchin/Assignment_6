#pragma once

#include <iostream>

#include "../Shape/Shape.h"
#include "../Position/Position.h"

using namespace std;

class Point : public Shape
{
private:
    double x;
    double y;
    double z;
    Position position;

public:
    Point();

    Point(const Point &point);

    Point(double x, double y, double z);

    void print();

    double getX() const;

    double getY() const;

    double getZ() const;

    void setX(double x);

    void setY(double y);

    void setZ(double z);

    void setPosition(Position position);

    Position getPosition();
};