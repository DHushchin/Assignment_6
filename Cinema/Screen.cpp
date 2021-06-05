#include "Screen.h"

Screen::Screen() {}

Screen::Screen(const Point &base, const Plane &image, int width, int height) : width(width), height(height), base(base), image(image)
{
}

void Screen::addPixel(int x, int y)
{
}

void Screen::print()
{
}

Plane Screen::getImage()
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