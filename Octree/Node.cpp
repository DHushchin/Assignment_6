#include "Node.h"

void Node::addTriangle(Triangle triangle)
{
    this->triangles.push_back(triangle);
}

void Node::addChild(Node node)
{
    this->children.push_back(node);
}