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
    parser.parse("cow.obj");

    vector<Triangle> parsedTriangles = parser.getTriangles();
    Box box(parser.findMinPoint(), parser.findMaxPoint(), parsedTriangles.size());
    Octree octree(box);

    for (auto it = parsedTriangles.begin(); it != parsedTriangles.end(); ++it)
    {
        octree.insert(*it);
    }

    Camera camera;
    camera.photo(octree);

    return 0;
}