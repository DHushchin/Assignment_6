#pragma once

#include <vector>

#include "Screen.h"
#include "../Shapes/Point.h"
#include "../Shapes/Triangle.h"

using namespace std;

class Camera : Point
{
private:
    Screen screen;

public:
    Camera();

    void photo(vector<Triangle> triangles);
};