#pragma once

#include <vector>

#include "../Triangle/Triangle.h"
#include "../Point/Point.h"

using namespace std;

class Box
{
private:
    Point top_left_front, bottom_right_back;
    Triangle *triangles;
    unsigned int size;
    unsigned int capacity;

public:
    Box();

    Box(Point startPoint, Point endPoint, int size);

    Box(const Box &box);

    void resize(Position position);

    void setTLF(Point &point);

    void setBRB(Point &point);

    Point getTLF();

    Point getBRB();

    int getCapacity();

    void setTriangle(Triangle &triangle);

    Triangle *getTriangles();

    bool lineIntersect(Line &line);

    bool containsPoint(Point point);
};
