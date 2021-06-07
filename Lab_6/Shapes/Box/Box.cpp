#include "Box.h"

Box::Box() {}

Box::Box(Point startPoint, Point endPoint)
{
    this->top_left_front = startPoint;
    this->bottom_right_back = endPoint;
}

Box::Box(const Box& box)
{
    this->bottom_right_back = box.bottom_right_back;
    this->top_left_front = box.top_left_front;
    this->triangles = box.triangles;
}

void Box::resize(Position pos)
{
    double midX = (top_left_front.getX() + bottom_right_back.getX()) / 2,
           midY = (top_left_front.getY() + bottom_right_back.getY()) / 2,
           midZ = (top_left_front.getZ() + bottom_right_back.getZ()) / 2;

    switch (pos)
    {
    case Position::TLF:
        this->bottom_right_back.setX(midX);
        this->bottom_right_back.setY(midY);
        this->bottom_right_back.setZ(midZ);
        break;

    case Position::TRF:
        this->top_left_front.setX(midX);
        this->bottom_right_back.setY(midY);
        this->bottom_right_back.setZ(midZ);
        break;

    case Position::BRF:
        this->top_left_front.setX(midX);
        this->top_left_front.setY(midY);
        this->bottom_right_back.setZ(midZ);
        break;

    case Position::BLF:
        this->bottom_right_back.setX(midX);
        this->top_left_front.setY(midY);
        this->bottom_right_back.setZ(midZ);
        break;

    case Position::TLB:
        this->bottom_right_back.setX(midX);
        this->bottom_right_back.setY(midY);
        this->top_left_front.setZ(midZ);
        break;
    case Position::TRB:
        this->top_left_front.setX(midX);
        this->bottom_right_back.setY(midY);
        this->top_left_front.setZ(midZ);
        break;

    case Position::BRB:
        this->top_left_front.setX(midX);
        this->top_left_front.setY(midY);
        this->top_left_front.setZ(midZ);
        break;

    case Position::BLB:
        this->bottom_right_back.setX(midX);
        this->top_left_front.setY(midY);
        this->top_left_front.setZ(midZ);
        break;
    }
}

void Box::setTLF(Point point)
{
    this->top_left_front = point;
}

void Box::setBRB(Point point)
{
    this->bottom_right_back = point;
}

Point Box::getTLF()
{
    return this->top_left_front;
}

Point Box::getBRB()
{
    return this->bottom_right_back;
}

void Box::setTriangle(Triangle triangle)
{
    this->triangles.push_back(triangle);
}

vector<Triangle> Box::getTriangles()
{
    return this->triangles;
}

bool Box::lineIntersect(Line &line)
{
    return true;
}