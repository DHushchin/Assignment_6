#include "Camera.h"

Camera::Camera() : base(0, -2, 0)
{
    int distance = 1;

    Point screenBase(this->base.getX(), this->base.getY() + distance, this->base.getZ());
    Plane screenImage(0, 1, 0, -this->base.getY() - distance);
    this->screen = Screen(screenBase, screenImage, 300, 300);

    Point lightBase(this->base.getX(), this->base.getY(), this->base.getZ() + 2);
    this->light = Light(lightBase);
}

void Camera::photo(vector<Triangle> &triangles, Octree& octree)
{
    Point screenBase = this->screen.getBase();
    Point currentPoint;

    int screenWidth = screen.getWidth();
    int screenHeight = screen.getHeight();
    int screenSize = screen.getSize();

    int pixelX = 0, pixelY = screenHeight - 1;

    Bmp image = this->screen.getImage();

    for (double i = screenBase.getZ() + (double)screenSize * 0.5; i > (screenBase.getZ() - screenSize * 0.5); i -= screenSize / (double)screenHeight, pixelY--)
    {
        for (double j = screenBase.getX() - (double)screenSize * 0.5, pixelX = 0; j < (screenBase.getX() + screenSize * 0.5); j += screenSize / (double)screenWidth, pixelX++)
        {
            currentPoint = Point(j, screenBase.getY(), i);
            Line cameraRay(this->base, currentPoint);

            Point resultPoint(INT_MAX, INT_MAX, INT_MAX);
            double length = INT_MAX;
            octree.findIntersectedPoint(cameraRay, currentPoint, resultPoint, length);

            if (resultPoint.getX() != INT_MAX) {
                Line lightRay(resultPoint, this->light.getBase());

                double angle = angleBetween(cameraRay.getDirectionVector(), lightRay.getDirectionVector());
                double cosAbs = abs(cos(angle));

                Color pixelColor(cosAbs * 255, cosAbs * 255, cosAbs * 255);

                image.setPixel(pixelX, pixelY, pixelColor);
            }
        }
    }

    string fileName = "a.bmp";
    image.write(fileName, fileName);

    // cout << "Rays lines:" << endl;
    // for (int i = 0; i < cameraLines.size(); i++)
    // {
    //     cout << "#" << i + 1 << endl;
    //     cameraLines[i].print();
    //     lightLines[i].print();
    //     cout << "Angle: " << angleBetween(cameraLines[i].getDirectionVector(), lightLines[i].getDirectionVector()) << "°" << endl;
    //     cout << endl;
    // }
    // cout << endl;

    // cout << "Screen plane:" << endl;
    // this->screen.getImagePlane().print();
    // cout << endl
    //      << endl;

    // cout << "Screen base:" << endl;
    // this->screen.getBase().print();
    // cout << endl
    //      << endl;

    // cout << "Camera base:" << endl;
    // this->base.print();
    // cout << endl
    //      << endl;

    // cout << "Light base:" << endl;
    // this->light.getBase().print();
    // cout << endl
    //      << endl;
}