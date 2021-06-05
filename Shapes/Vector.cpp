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
    printf("Point: % 2.6f, % 2.6f, % 2.6f, %2.6f\n", this->x, this->y, this->z, this->length);
}

double scalarProduct(Vector a, Vector b)
{
    return (a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ());
}

double angleBetween(Vector a, Vector b)
{
    return acos((scalarProduct(a, b) / (a.getLength() * b.getLength()))) * 180.0 / M_PI;
}