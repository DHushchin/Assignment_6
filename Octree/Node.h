#pragma once

#include <vector>

#include "../Shapes/Triangle.h"
#include "../Shapes/Box.h"

using namespace std;

class Node
{
private:
    vector<Node> children;
    vector<Triangle> triangles;
    Box box;

public:
    Node() {}

    void addTriangle(Triangle triangle);

    void addChild(Node node);
};
