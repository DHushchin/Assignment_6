#include "Camera.h"

Camera::Camera() : base(0, -20, 0)
{
    Point screenBase(this->base.getX(), this->base.getY() + 5, this->base.getZ());
    Plane screenImage(0, 1, 0, -this->base.getY() - 5);
    this->screen = Screen(screenBase, screenImage, 1000, 1000);

    Point lightBase(this->base.getX(), this->base.getY(), this->base.getZ() + 10);
    this->light = Light(lightBase);
}

void Camera::photo()
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

    for (double i = screenBase.getZ() + screenSize / 2; i >= screenBase.getZ() - screenSize / 2; i -= screenSize / (double)screenHeight)
    {
        for (double j = screenBase.getX() - screenSize / 2; j <= screenBase.getX() + screenSize / 2; j += screenSize / (double)screenWidth)
        {
            currentPoint = Point(j, screenBase.getY(), i);
            cameraLines.push_back(Line(this->base, currentPoint));
            lightLines.push_back(Line(this->light.getBase(), currentPoint));
        }
    }

    cout << "Rays lines:" << endl;
    for (int i = 0; i < cameraLines.size(); i++)
    {
        cout << "#" << i + 1 << endl;
        cameraLines[i].print();
        lightLines[i].print();
        cout << "Angle: " << angleBetween(cameraLines[i].getDirectionVector(), lightLines[i].getDirectionVector()) << "°" << endl;
        cout << endl;
    }
    cout << endl;

    cout << "Screen plane:" << endl;
    this->screen.getImage().print();
    cout << endl
         << endl;

    cout << "Screen base:" << endl;
    this->screen.getBase().print();
    cout << endl
         << endl;

    cout << "Camera base:" << endl;
    this->base.print();
    cout << endl
         << endl;

    cout << "Light base:" << endl;
    this->light.getBase().print();
    cout << endl
         << endl;
}