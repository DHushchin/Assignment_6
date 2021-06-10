#include "Camera.h"

Camera::Camera() : base(0, -10, 0)
{

    Point screenBase(this->base.getX(), this->base.getY() + 9, this->base.getZ());
    Plane screenImage(0, 1, 0, -this->base.getY() - 9);
    this->screen = Screen(screenBase, screenImage, 500, 500);

    Point lightBase(this->base.getX(), this->base.getY() + 9, this->base.getZ() + 0.4);
    this->light = Light(lightBase);
}

void Camera::photo(Octree &octree)
{
    Point screenBase = this->screen.getBase();

    int screenWidth = screen.getWidth();
    int screenHeight = screen.getHeight();
    int screenSize = screen.getSize();
    Point currentPoint;
    int pixelX, pixelY = screenHeight - 1;

    Bmp image = this->screen.getImage();

    double z = (double)screenBase.getZ(), y = screenBase.getY(), x = (double)screenBase.getX();
    double ScrSize = (double)screenSize, height = (double)screenHeight, width = (double)screenWidth;

    for (double i = z + ScrSize * 0.5; i > (z - ScrSize * 0.5); i -= ScrSize / height, pixelY--)
    {
        for (double j = x - ScrSize * 0.5, pixelX = 0; j < (x + ScrSize * 0.5); j += ScrSize / width, pixelX++)
        {
            currentPoint = Point(j, y, i);
            Line cameraRay(this->base, currentPoint);

            Point resultPoint(100, 100, 100);
            double length = 100;

            octree.findIntersectedPoint(cameraRay, currentPoint, resultPoint, length);

            if (resultPoint.getX() != 100)
            {
                Line lightRay(resultPoint, this->light.getBase());

                double cosAbs = abs(cos(angleBetween(cameraRay.getDirectionVector(), lightRay.getDirectionVector())));
                Color pixelColor(cosAbs * 255, cosAbs * 255, cosAbs * 255);

                image.setPixel(pixelX, pixelY, pixelColor);
            }
        }
    }

    string fileName = "a.bmp";
    image.write(fileName, fileName);
}
