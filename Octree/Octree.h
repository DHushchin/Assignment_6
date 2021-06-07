#pragma once

#include <vector>

#include "../Parser/Parser.h"
#include "../Shapes/Line/Line.h"
#include "../Shapes/Triangle/Triangle.h"
#include "../Shapes/Box/Box.h"

using namespace std;

class Octree
{
private:
    Box box;
    vector<Octree *> children;

public:
    Octree();

    Octree(Box box);

    void setBox(Box box);

    void insert(Triangle triangle);

    void findIntersectedTriangles(Line &line, vector<Triangle> &intersected);
};