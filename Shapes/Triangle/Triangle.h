#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

#include "../Shape/Shape.h"
#include "../Point/Point.h"
#include "../Line/Line.h"

using namespace std;

class Triangle : public Shape
{
private:
    Point vertexes[3];
    bool isInserted;

public:
    Triangle() {}

    Triangle(Point a, Point b, Point c);

    double getMaxX();

    double getMaxY();

    double getMaxZ();

    void print();

    void setInserted();

    bool getInserted();

    vector<Point> getPoints();

    double getMinX();

    double getMinY();

    double getMinZ();

    bool lineIntersect(Line &line);
};