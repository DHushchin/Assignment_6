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
    parser.parse("objects\\sphere.obj");

    Camera camera;
    vector <Triangle> triangles = parser.getTriangles();
    Box box(parser.findMinPoint(), parser.findMaxPoint());
    Octree octree(box);
    for (size_t i = 0; i < triangles.size(); i++)
    {
        octree.insert(triangles[i]);
    }

    int sum = 0;
    octree.getTriangleNumber(sum);
    cout << sum << endl;


    camera.photo(triangles, octree);

    return 0;
}