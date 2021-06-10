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
    parser.parse("sphere.obj");

    vector<Triangle> triangles = parser.getTriangles();
    Box box(parser.findMinPoint(), parser.findMaxPoint());
    Octree octree(box);

    for (auto it = triangles.begin(); it != triangles.end(); ++it)
    {
        octree.insert(*it);
    }
    /*
    int sum = 0;
    octree.getTriangleNumber(sum);
    cout << sum << endl;
    */

    Camera camera;
    camera.photo(triangles, octree);
    return 0;
}