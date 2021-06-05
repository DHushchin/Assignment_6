#pragma once

#include <vector>

#include "../Shapes/Point.h"
#include "../Shapes/Plane.h"

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