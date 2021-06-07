#pragma once

#include <vector>

#include "../../Shapes/Point/Point.h"
#include "../../Shapes/Plane/Plane.h"

using namespace std;

class Light
{
private:
    Point base;

public:
    Light();

    Light(const Point &point);

    Point getBase();
};