#include "Point.h"

Point::Point() {}

Point::Point(const Point &point)
{
    this->x = point.getX();
    this->y = point.getY();
    this->z = point.getZ();
}

Point::Point(double x, double y, double z) : x(x), y(y), z(z)
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