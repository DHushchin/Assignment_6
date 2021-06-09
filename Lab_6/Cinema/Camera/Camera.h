#pragma once

#include <vector>

#include "../Screen/Screen.h"
#include "../Light/Light.h"
#include "../../Shapes/Triangle/Triangle.h"
#include "../../Shapes/Vector/Vector.h"
#include "../../Shapes/Line/Line.h"
#include "../../Photo/BMP.h"
#include "../../Octree/Octree.h"
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

    void photo(vector<Triangle>& triangles, Octree& octree);
};