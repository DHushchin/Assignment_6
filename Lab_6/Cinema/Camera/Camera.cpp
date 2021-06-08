#include "Camera.h"

Camera::Camera() : base(0, -20, 0)
{
    Point screenBase(this->base.getX(), this->base.getY() + 5, this->base.getZ());
    Plane screenImage(0, 1, 0, -this->base.getY() - 5);
    this->screen = Screen(screenBase, screenImage, 100, 100);

    Point lightBase(this->base.getX(), this->base.getY(), this->base.getZ() + 10);
    this->light = Light(lightBase);
}

void Camera::photo(vector<Triangle>& triangles)
{
    Point screenBase = this->screen.getBase();
    Point currentPoint;

    vector<Line> cameraLines;
    vector<Line> lightLines;

    double x;
    double y;
    double z;

    int screenWidth = screen.getWidth();
    int screenHeight = screen.getHeight();
    int screenSize = screen.getSize();
    Bmp image = this->screen.getImage();

    bool isIntersected = false;
    
    for (double i = screenBase.getZ() + (double)screenSize * 0.5 ; i >= screenBase.getZ() - (double)screenSize * 0.5; i -= (double)screenSize / (double)screenHeight)
    {
        for (double j = screenBase.getX() - (double)screenSize * 0.5; j <= screenBase.getX() + (double)screenSize * 0.5; j += (double)screenSize / (double)screenWidth)
        {
            currentPoint = Point(j, screenBase.getY(), i);
            Line cameraRay = Line(this->base, currentPoint);

            for (int k = 0; k < triangles.size(); k++)
            {
                Point *triangleIntersect = triangles[i].lineIntersect(cameraRay);

                if (triangleIntersect != NULL)
                {
                    isIntersected = true;
                    Line lightRay(*triangleIntersect, this->light.getBase());
                    double angle = angleBetween(cameraRay.getDirectionVector(), lightRay.getDirectionVector());

                    Color pixelColor(angle * 255, angle * 255, angle * 255);

                    image.setPixel(j + screenSize * 0.5, i + screenSize * 0.5, pixelColor);
                }               
            }
            cout << isIntersected ? "intersect" : "false";
            cout << endl;
            isIntersected = false;
        }
    }
    /*
    Triangle a(Point(0, 0, 1), Point(0, 1, 0), Point(1, 0, 0));
    Line line(Point(0, 0, 0), Point(1, 1, 1));
    if (a.lineIntersect(line))
        cout << "intersect";
    else
        cout << "false";
    cout << endl;*/
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