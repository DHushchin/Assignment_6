#pragma once

#include <vector>

#include "../Triangle/Triangle.h"
#include "../Point/Point.h"

using namespace std;

class Box
{
private:
    Point top_left_front, bottom_right_back;
    vector<Triangle> triangles;

public:
    Box();

    Box(Point startPoint, Point endPoint);

    Box(const Box &box);

    void resize(Position position);

    void setTLF(Point point);

    void setBRB(Point point);

    Point getTLF();

    Point getBRB();

    void setTriangle(Triangle triangle);

    vector<Triangle> getTriangles();

    bool lineIntersect(Line &line);
};
