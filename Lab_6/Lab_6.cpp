#include <iostream>
#include <windows.h>

#include "Cinema/Camera/Camera.h"
#include "Octree/Octree.h"

using namespace std;



int main()
{
    /*
    SetConsoleOutputCP(65001);
    Camera camera;
    camera.photo();
    */
    Parser parser;
    parser.parse("objects//sphere.obj");

    Box box(parser.findMinPoint(), parser.findMaxPoint());
    Octree* octree = new Octree(box);
    vector <Triangle>& triangles = parser.getTriangles();
    for (int i = 0; i < triangles.size(); i++)
    {
        (*octree).insert(triangles[i]);
    }
    int sum = 0;
    (*octree).getTriangleNumber(sum);
    cout << "Sum: " << sum << endl;
    return 0;
}