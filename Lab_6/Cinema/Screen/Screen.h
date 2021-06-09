#pragma once

#include <string>

#include "../../Shapes/Point/Point.h"
#include "../../Photo/BMP.h"
#include "../../Shapes/Plane/Plane.h"

using namespace std;

class Screen
{
private:
    Point base;
    Plane imagePlane;
    Bmp image;

    int size;
    int width;
    int height;

public:
    Screen();

    Screen(const Point &base, const Plane &imagePlane, int width, int height);

    Point getBase();

    Plane getImagePlane();

    Bmp getImage();

    int getWidth();

    int getHeight();

    int getSize();
};
