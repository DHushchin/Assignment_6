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

    void insert(Triangle& triangle);

    void findIntersectedPoint(Line &line, Point& currentPoint, Point& resultPoint, double& minLength);

    void getTriangleNumber(int& sum) {
        for (size_t i = 0; i < children.size(); i++)
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