#include "Plane.h"

Plane::Plane() {}

Plane::Plane(Point a, Point b, Point c)
{
    double a1 = b.getX() - a.getX();
    double b1 = b.getY() - a.getY();
    double c1 = b.getZ() - a.getZ();

    double a2 = c.getX() - a.getX();
    double b2 = c.getY() - a.getY();
    double c2 = c.getZ() - a.getZ();

    this->A = b1 * c2 - b2 * c1;
    this->B = a2 * c1 - a1 * c2;
    this->C = a1 * b2 - b1 * a2;
    this->D = (-this->A * a.getX() - this->B * a.getY() - this->C * a.getZ());
}

Plane::Plane(double A, double B, double C, double D) : A(A), B(B), C(C), D(D) {}

Plane::Plane(const Plane &plane)
{
    this->A = plane.getA();
    this->B = plane.getB();
    this->C = plane.getC();
    this->D = plane.getD();
}

void Plane::print()
{
    printf("Plane: %1.3fx + %1.3fy + %1.3fz + %1.3f = 0 \n", this->A, this->B, this->C, this->D);
}

double Plane::getA() const
{
    return this->A;
}

double Plane::getB() const
{
    return this->B;
}

double Plane::getC() const
{
    return this->C;
}

double Plane::getD() const
{
    return this->D;
}

Point Plane::intersect(Line line)
{
    Point linePoint = line.getFirstPoint();
    Vector lineVector = line.getDirectionVector();
    double t = -(this->A * linePoint.getX() + this->B * linePoint.getY() + this->C * linePoint.getZ() + this->D) / (this->A * lineVector.getX() + this->B * lineVector.getY() + this->C * lineVector.getZ());

    return Point(lineVector.getX() * t + linePoint.getX(), lineVector.getY() * t + linePoint.getY(), lineVector.getZ() * t + linePoint.getZ());
}