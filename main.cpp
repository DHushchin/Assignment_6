#include <iostream>
#include <windows.h>

#include "Cinema/Camera.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    Camera a;
    a.photo();
    return 0;
}