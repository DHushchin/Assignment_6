#include "Vector.h"

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z), length(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) {}

Vector::Vector(Point a, Point b)
{
    this->x = a.getX() - b.getX();
    this->y = a.getY() - b.getY();
    this->z = a.getZ() - b.getZ();
    this->length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double Vector::getX()
{
    return this->x;
}

double Vector::getY()
{
    return this->y;
}

double Vector::getZ()
{
    return this->z;
}

double Vector::getLength()
{
    return this->length;
}

void Vector::print()
{
    printf("Vector: (% 2.6f, % 2.6f, % 2.6f), %2.6f\n", this->x, this->y, this->z, this->length);
}