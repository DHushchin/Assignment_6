#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

#include "../Shape/Shape.h"
#include "../Point/Point.h"
#include "../Line/Line.h"
#include "../Plane/Plane.h"

using namespace std;

class Triangle : public Shape
{
private:
    Point vertexes[3];
    bool isInserted;
    void getNewVertex(Point *newVertex, Point *intersectPoint);

public:
    Triangle() {}

    bool contains(Point point);

    Triangle(Point a, Point b, Point c);

    double getMaxX();

    double getMaxY();

    double getMaxZ();

    void print();

    void setInserted();

    bool getInserted();

    Point *getPoints();

    double getMinX();

    double getMinY();

    double getMinZ();

    Point intersect(Line line);
};