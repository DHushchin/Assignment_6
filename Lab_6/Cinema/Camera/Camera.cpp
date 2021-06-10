#include "Camera.h"

Camera::Camera() : base(0, -50, 0)
{
    int distance = 10;

    Point screenBase(this->base.getX(), this->base.getY() + distance, this->base.getZ());
    Plane screenImage(0, 1, 0, -this->base.getY() - distance);
    this->screen = Screen(screenBase, screenImage, 100, 100);

    Point lightBase(this->base.getX(), this->base.getY(), this->base.getZ() + 2);
    this->light = Light(lightBase);
}

void Camera::photo(vector<Triangle> &triangles, Octree &octree)
{
    Point screenBase = this->screen.getBase();

    int screenWidth = screen.getWidth();
    int screenHeight = screen.getHeight();
    int screenSize = screen.getSize();
    Point currentPoint;
    int pixelX, pixelY = screenHeight - 1;

    Bmp image = this->screen.getImage();

    for (double i = (double)screenBase.getZ() + (double)screenSize * 0.5; i > ((double)screenBase.getZ() - (double)screenSize * 0.5); i -= (double)screenSize / (double)screenHeight, pixelY--)
    {
        for (double j = (double)screenBase.getX() - (double)screenSize * 0.5, pixelX = 0; j < ((double)screenBase.getX() + (double)screenSize * 0.5); j += (double)screenSize / (double)screenWidth, pixelX++)
        {
            currentPoint = Point(j, screenBase.getY(), i);
            Line cameraRay(this->base, currentPoint);

            Point resultPoint(INT_MAX, INT_MAX, INT_MAX);
            double length = INT_MAX;
            octree.findIntersectedPoint(cameraRay, currentPoint, resultPoint, length);

            if (resultPoint.getX() != INT_MAX)
            {
                Line lightRay(resultPoint, this->light.getBase());

                double cosAbs = 1 - abs(cos(angleBetween(cameraRay.getDirectionVector(), lightRay.getDirectionVector())));

                Color pixelColor(cosAbs * 255, cosAbs * 255, cosAbs * 255);

                image.setPixel(pixelX, pixelY, pixelColor);
            }
        }
    }

    string fileName = "a.bmp";
    image.write(fileName, fileName);
}