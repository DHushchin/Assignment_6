#include "Screen.h"

Screen::Screen() {}

Screen::Screen(const Point &base, const Plane &imagePlane, int width, int height) : width(width), height(height), base(base), imagePlane(imagePlane), size(2), image(width, height)
{
}

Plane Screen::getImagePlane()
{
    return this->imagePlane;
}

Bmp Screen::getImage()
{
    return this->image;
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

int Screen::getSize()
{
    return this->size;
}