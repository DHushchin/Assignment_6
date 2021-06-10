#pragma once

#include <vector>
#include <iterator>

#include "../Parser/Parser.h"
#include "../Shapes/Line/Line.h"
#include "../Shapes/Triangle/Triangle.h"
#include "../Shapes/Box/Box.h"

using namespace std;

class Octree
{
private:
    Box box;
    Octree **children;

public:
    Octree();

    Octree(Box &box);

    void insert(Triangle &triangle);

    void findIntersectedPoint(Line &line, Point &currentPoint, Point &resultPoint, double &minLength);
};