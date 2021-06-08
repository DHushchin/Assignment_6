#include "Camera.h"

Camera::Camera() : base(0, -50, 0)
{
    int distance = 10;

    Point screenBase(this->base.getX(), this->base.getY() + distance, this->base.getZ());
    Plane screenImage(0, 1, 0, -this->base.getY() - distance);
    this->screen = Screen(screenBase, screenImage, 1000, 1000);

    Point lightBase(this->base.getX(), this->base.getY(), this->base.getZ() + 2);
    this->light = Light(lightBase);
}

void Camera::photo(vector<Triangle> &triangles)
{
    Point screenBase = this->screen.getBase();
    Point currentPoint;

    int screenWidth = screen.getWidth();
    int screenHeight = screen.getHeight();
    int screenSize = screen.getSize();

    int pixelX, pixelY = screenHeight - 1;

    Bmp image = this->screen.getImage();

    for (double i = screenBase.getZ() + (double)screenSize * 0.5; i > (screenBase.getZ() - screenSize * 0.5); i -= screenSize / (double)screenHeight, pixelY--)
    {
        for (double j = screenBase.getX() - (double)screenSize * 0.5, pixelX = 0; j < (screenBase.getX() + screenSize * 0.5); j += screenSize / (double)screenWidth, pixelX++)
        {
            currentPoint = Point(j, screenBase.getY(), i);
            Line cameraRay = Line(this->base, currentPoint);

            for (int k = 0; k < triangles.size(); k++)
            {
                Point triangleIntersect = triangles[k].intersect(cameraRay);

                if (triangleIntersect.getX() != -9999)
                {
                    Line lightRay(triangleIntersect, this->light.getBase());

                    double angle = angleBetween(cameraRay.getDirectionVector(), lightRay.getDirectionVector());
                    double cosAbs = abs(cos(angle));

                    Color pixelColor(cosAbs * 255, cosAbs * 255, cosAbs * 255);

                    image.setPixel(pixelX, pixelY, pixelColor);
                }
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