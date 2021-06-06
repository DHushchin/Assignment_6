#include <iostream>
#include <windows.h>

#include "Cinema/Camera/Camera.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    Camera camera;
    camera.photo();

    return 0;
}