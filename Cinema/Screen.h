#pragma once

#include <string>

#include "../Shapes/Point.h"
#include "../Shapes/Plane.h"

using namespace std;

class Screen
{
private:
    Point base;
    Plane image;

    int width;
    int height;

public:
    Screen();

    Screen(const Point &base, const Plane &image, int width, int height);

    void addPixel(int x, int y);

    void print();

    Point getBase();

    Plane getImage();

    int getWidth();

    int getHeight();
};
