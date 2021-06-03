#include "Screen.h"

Screen::Screen(int width, int height) : width(width), height(height), Plane(0, 0, 1, 5)
{
    array = new string *[height];

    for (size_t i = 0; i < height; i++)
    {
        array[i] = new string[width];
        for (size_t j = 0; j < width; j++)
        {
            array[i][j] = " ";
        }
    }
}

void Screen::addPixel(int x, int y)
{
    this->array[x][y] = "*";
}

void Screen::print()
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }
}

Point Screen::getBase()
{
    return this->base;
}

int Screen::getWidth()
{
    return this->width;
}

int Screen::getHeight()
{
    return this->height;
}