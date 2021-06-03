#pragma once

#include <string>

#include "../Shapes/Point.h"
#include "../Shapes/Plane.h"

using namespace std;

class Screen : Plane
{
private:
    Point base;

    int width;
    int height;

    string **array;

public:
    Screen(int width, int height);

    void addPixel(int x, int y);

    void print();

    Point getBase();

    int getWidth();

    int getHeight();
};
