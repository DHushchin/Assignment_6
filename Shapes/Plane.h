#pragma once

#include <iostream>

#include "Shape.h"

using namespace std;

class Plane : public Shape
{
private:
    double A;
    double B;
    double C;
    double D;

public:
    Plane();

    Plane(double A, double B, double C, double D);

    Plane(const Plane &plane);

    double getA() const;

    double getB() const;

    double getC() const;

    double getD() const;

    void print();
};
