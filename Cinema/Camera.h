#pragma once

#include <vector>

#include "Screen.h"
#include "Light.h"
#include "../Shapes/Triangle.h"
#include "../Shapes/Vector.h"
#include "../Shapes/Line.h"

using namespace std;

class Camera
{
private:
    Screen screen;
    Light light;
    Point base;
    Line rayTo(Point point);

public:
    Camera();

    void photo();
};