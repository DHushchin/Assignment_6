#include "Plane.h"

Plane::Plane() {}

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