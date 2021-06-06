#pragma once

#include <string>
#include <iostream>

#include "Shape.h"
#include "Point.h"
#include "Vector.h"

using namespace std;

class Line : public Shape
{
private:
    Point firstPoint;
    Point secondPoint;
    Vector directionVector;

public:
    Line(Point firstPoint, Point secondPoint);

    Vector getDirectionVector();

    bool contains(Point point);

    Point getFirstPoint();

    Point getSecondPoint();

    void print();
};