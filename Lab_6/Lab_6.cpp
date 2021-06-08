#include <iostream>

#include "Cinema/Camera/Camera.h"
#include "Octree/Octree.h"

using namespace std;

#include "Shapes/Plane/Plane.h"
#include "Shapes/Line/Line.h"
#include "Shapes/Triangle/Triangle.h"

int main()
{
    Parser parser;
    parser.parse("сow.obj");

    Plane a(0, 1, 0, -5);
    Line b(Point(0, 0, 0), Point(1, 1, 1));

    // a.intersect(b).print();

    Camera camera;
    camera.photo(parser.getTriangles());

    return 0;
}