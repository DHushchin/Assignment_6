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
    vector<Octree*> children;

public:
    Octree();

    Octree(Box& box);

    void setBox(Box box);

    void insert(Triangle& triangle);

    void findIntersectedTriangles(Line &line, vector<Triangle> &intersected);

    void getTriangleNumber(int& sum) {
        for (int i = 0; i < children.size(); i++)
        {
            if (children.size() > 0)
            {
                if (children[i] != NULL)
                    children[i]->getTriangleNumber(sum);
            }
        }
        sum += box.getTriangles().size();
    }
};