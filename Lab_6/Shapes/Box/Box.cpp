#include "Box.h"

Box::Box() {}

Box::Box(Point startPoint, Point endPoint, int size)
{
    this->top_left_front = startPoint;
    this->bottom_right_back = endPoint;
    this->size = size;
    triangles = new Triangle[size];
    capacity = 0;
}

Box::Box(const Box &box)
{
    this->bottom_right_back = box.bottom_right_back;
    this->top_left_front = box.top_left_front;
    this->size = box.size;
    this->triangles = new Triangle[size];
    this->capacity = 0;
    //for (int i = 0; i < size; i++)
    //    this->triangles[i] = box.triangles[i];
    //this->triangles = box.triangles;
}

void Box::resize(Position pos)
{
    double midX = (top_left_front.getX() + bottom_right_back.getX()) * 0.5,
           midY = (top_left_front.getY() + bottom_right_back.getY()) * 0.5,
           midZ = (top_left_front.getZ() + bottom_right_back.getZ()) * 0.5;

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

void Box::setTLF(Point &point)
{
    this->top_left_front = point;
}

void Box::setBRB(Point &point)
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

int Box::getCapacity()
{
    return capacity;
}

void Box::setTriangle(Triangle &triangle)
{
    triangles[capacity++] = triangle;
}

Triangle *Box::getTriangles()
{
    return triangles;
}

bool Box::containsPoint(Point point)
{
    if (point.getX() < this->top_left_front.getX() || point.getX() > this->bottom_right_back.getX())
    {
        return false;
    }

    if (point.getY() > this->bottom_right_back.getY() || point.getY() < this->top_left_front.getY())
    {
        return false;
    }

    if (point.getZ() > this->bottom_right_back.getZ() || point.getZ() < this->top_left_front.getZ())
    {
        return false;
    }

    return true;
}

bool Box::lineIntersect(Line &line)
{
    Point p1, p2, p3, intersect;
    Plane plane;

    /*front*/
    p1 = this->top_left_front;
    p2 = this->top_left_front;
    p2.setZ(this->bottom_right_back.getZ());
    p3 = this->top_left_front;
    p3.setY(this->bottom_right_back.getY());
    plane = Plane(p1, p2, p3);
    intersect = plane.intersect(line);

    if (this->containsPoint(intersect))
        return true;

    /*front-right*/
    p1 = this->bottom_right_back;
    p2 = this->bottom_right_back;
    p2.setZ(this->top_left_front.getZ());
    p3 = this->bottom_right_back;
    p3.setX(this->top_left_front.getX());
    plane = Plane(p1, p2, p3);
    intersect = plane.intersect(line);

    if (this->containsPoint(intersect))
        return true;

    /*front-top*/
    p1 = this->top_left_front;
    p2 = this->top_left_front;
    p2.setX(this->bottom_right_back.getX());
    p3 = this->top_left_front;
    p3.setY(this->bottom_right_back.getY());
    plane = Plane(p1, p2, p3);
    intersect = plane.intersect(line);

    if (this->containsPoint(intersect))
        return true;

    /*back*/
    p1 = this->bottom_right_back;
    p2 = this->bottom_right_back;
    p2.setY(this->top_left_front.getY());
    p3 = this->bottom_right_back;
    p3.setZ(this->top_left_front.getZ());
    plane = Plane(p1, p2, p3);
    intersect = plane.intersect(line);

    if (this->containsPoint(intersect))
        return true;

    /*bottom*/
    p1 = this->top_left_front;
    p2 = this->top_left_front;
    p2.setX(this->bottom_right_back.getX());
    p3 = this->bottom_right_back;
    plane = Plane(p1, p2, p3);
    intersect = plane.intersect(line);

    if (this->containsPoint(intersect))
        return true;

    /*back-left*/
    p1 = this->top_left_front;
    p2 = this->top_left_front;
    p2.setZ(this->bottom_right_back.getZ());
    p3 = this->top_left_front;
    p3.setY(this->bottom_right_back.getY());
    plane = Plane(p1, p2, p3);
    intersect = plane.intersect(line);

    if (this->containsPoint(intersect))
        return true;

    return false;
}