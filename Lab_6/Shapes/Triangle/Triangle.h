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
    double s(Point A, Point B, Point C);

public:
    Triangle() { isInserted = false; }

    bool contains(Point point);

    Triangle(Point a, Point b, Point c);

    double getMaxX();

    double getMaxY();

    double getMaxZ();

    void print();

    void setInserted(bool flag);

    bool getInserted();

    Point *getPoints();

    double getMinX();

    double getMinY();

    double getMinZ();

    Point intersect(Line line);

    double distEuclid(Point A, Point B);

    friend bool operator==(const Triangle& a, const Triangle& b) {
        for (int i = 0; i < 3; i++)
        {
            if (a.vertexes[i] != b.vertexes[i])
                return false;
        }
        if (a.isInserted != b.isInserted)
            return false;
        return true;
    }
};