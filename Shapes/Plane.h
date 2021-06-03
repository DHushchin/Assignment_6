#pragma once

#include <iostream>

#include "Shape.h"

using namespace std;

class Plane
{
private:
    double A;
    double B;
    double C;
    double D;

public:
    Plane(double A, double B, double C, double D);

    void print();

    double getA();

    double getB();

    double getC();

    double getD();
};
