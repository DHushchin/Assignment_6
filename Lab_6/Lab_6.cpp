#include <iostream>
#include <windows.h>

#include "Cinema/Camera/Camera.h"
#include "Octree/Octree.h"

using namespace std;

int main()
{

    Parser parser;
    parser.parse("sphere.obj");

    Camera camera;
    camera.photo(parser.getTriangles());

    return 0;
}