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
    parser.parse("objects\\cow.obj");

    Camera camera;
    vector <Triangle> triangles = parser.getTriangles();
    Box box(parser.findMinPoint(), parser.findMaxPoint());
    Octree octree(box);
    for (size_t i = 0; i < triangles.size(); i++)
    {
        octree.insert(triangles[i]);
    }

    camera.photo(triangles, octree);
    
    /*
    Box box(Point(-2, -2, -2), Point(2, 2, 2));
    Octree octree(box);
    Triangle triangle(Point(1, 0, 0), Point(0, 1, 0), Point(0, 0, 1));
    octree.insert(triangle);
    Line line(Point(-5, -5, -5), Point(5, 5, 5));
    int sum = 0;
    //octree.getTriangleNumber(sum);
    //cout << sum << endl;
    Point result(INT_MAX, INT_MAX, INT_MAX);
    double length = INT_MAX;
    Point start(0, 0, 0);
    octree.findIntersectedTriangles(line, start, result, length);
    result.print();
    */
    
    return 0;
}