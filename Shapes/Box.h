#pragma once

#include <vector>

#include "Triangle.h"
#include "Point.h"

using namespace std;

class Box
{
private:
    Point top_left_front, bottom_right_back;
    vector<Triangle> triangles;

public:
    Box(){};
    Box(Point start, Point end);
    Box(const Box &other);
    void resize(Position pos);
    void setTLF(Point point);
    void setBRB(Point point);
    Point getTLF();
    Point getBRB();
    void setTriangle(Triangle triangle);
    vector<Triangle> getTriangles();
    bool lineIntersect(Line &line);
};
