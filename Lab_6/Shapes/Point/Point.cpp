#include "Point.h"

Point::Point() {
    position = Position::UNDEFINED;
}

Point::Point(const Point &point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    position = Position::UNDEFINED;
}

Point::Point(double x, double y, double z) : x(x), y(y), z(z), position(Position::UNDEFINED)
{
}

void Point::print()
{
    printf("Point: % 2.6f, % 2.6f, % 2.6f \n", this->x, this->y, this->z);
}

double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

double Point::getZ() const
{
    return this->z;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

void Point::setZ(double z)
{
    this->z = z;
}

void Point::setPosition(Position position)
{
    this->position = position;
}

Position Point::getPosition()
{
    return position;
}