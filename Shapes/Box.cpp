#include "Box.h"

Box::Box(Point start, Point end)
{
    this->top_left_front = start;
    this->bottom_right_back = end;
    vector<Triangle> triangles;
}

Box::Box(const Box &other)
{
    this->bottom_right_back = other.bottom_right_back;
    this->top_left_front = other.top_left_front;
    this->triangles = other.triangles;
}

void Box::resize(Position pos)
{
    double midX = (top_left_front.getX() + bottom_right_back.getX()) / 2,
           midY = (top_left_front.getY() + bottom_right_back.getY()) / 2,
           midZ = (top_left_front.getZ() + bottom_right_back.getZ()) / 2;
    switch (pos)
    {
    case Position::TLF:
        bottom_right_back.setX(midX);
        bottom_right_back.setY(midY);
        bottom_right_back.setZ(midZ);
        break;
    case Position::TRF:
        top_left_front.setX(midX);
        bottom_right_back.setY(midY);
        bottom_right_back.setZ(midZ);
        break;
    case Position::BRF:
        top_left_front.setX(midX);
        top_left_front.setY(midY);
        bottom_right_back.setZ(midZ);
        break;
    case Position::BLF:
        bottom_right_back.setX(midX);
        top_left_front.setY(midY);
        bottom_right_back.setZ(midZ);
        break;
    case Position::TLB:
        bottom_right_back.setX(midX);
        bottom_right_back.setY(midY);
        top_left_front.setZ(midZ);
        break;
    case Position::TRB:
        top_left_front.setX(midX);
        bottom_right_back.setY(midY);
        top_left_front.setZ(midZ);
        break;
    case Position::BRB:
        top_left_front.setX(midX);
        top_left_front.setY(midY);
        top_left_front.setZ(midZ);
        break;
    case Position::BLB:
        bottom_right_back.setX(midX);
        top_left_front.setY(midY);
        top_left_front.setZ(midZ);
        break;
    }
}

void Box::setTLF(Point point)
{
    top_left_front = point;
}

void Box::setBRB(Point point)
{
    bottom_right_back = point;
}

Point Box::getTLF()
{
    return top_left_front;
}

Point Box::getBRB()
{
    return bottom_right_back;
}

void Box::setTriangle(Triangle triangle)
{
    triangles.push_back(triangle);
}

vector<Triangle> Box::getTriangles()
{
    return triangles;
}

bool Box::lineIntersect(Line &line)
{
    return true;
}