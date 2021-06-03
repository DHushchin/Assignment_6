#include "Plane.h"

Plane::Plane(double A, double B, double C, double D) : A(A), B(B), C(C), D(D) {}

void Plane::print()
{
    printf("Plane: %fx + %fy + %fz + %f = 0", this->A, this->B, this->C, this->D);
}

double Plane::getA()
{
    return this->A;
}

double Plane::getB()
{
    return this->B;
}

double Plane::getC()
{
    return this->C;
}

double Plane::getD()
{
    return this->D;
}