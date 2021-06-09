#include "Triangle.h"

Triangle::Triangle(Point a, Point b, Point c)
{
    this->vertexes[0] = a;
    this->vertexes[1] = b;
    this->vertexes[2] = c;
    this->isInserted = false;
}

double Triangle::getMaxX()
{
    double currentX, maxX = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        currentX = vertexes[i].getX();

        if (vertexes[i].getX() > maxX)
        {
            maxX = currentX;
        }
    }

    return maxX;
}

double Triangle::getMaxY()
{
    double currentY, maxY = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        currentY = vertexes[i].getY();

        if (vertexes[i].getY() > maxY)
        {
            maxY = currentY;
        }
    }

    return maxY;
}

double Triangle::getMaxZ()
{
    double currentZ,
        maxZ = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        currentZ = vertexes[i].getZ();

        if (vertexes[i].getZ() > maxZ)
        {
            maxZ = currentZ;
        }
    }

    return maxZ;
}

void Triangle::print()
{
    cout << "Triangle: " << endl;
    for (int i = 0; i < 3; i++)
    {
        vertexes[i].print();
    }
}

void Triangle::setInserted(bool flag)
{
    this->isInserted = flag;
}

bool Triangle::getInserted()
{
    return this->isInserted;
}

Point *Triangle::getPoints()
{
    return vertexes;
}

double Triangle::getMinX()
{
    double currentX,
        minX = INT_MAX;

    for (int i = 0; i < 3; i++)
    {
        currentX = vertexes[i].getX();

        if (vertexes[i].getX() < minX)
        {
            minX = currentX;
        }
    }

    return minX;
}

double Triangle::getMinY()
{
    double currentY,
        minY = INT_MAX;

    for (int i = 0; i < 3; i++)
    {
        currentY = vertexes[i].getY();

        if (vertexes[i].getY() < minY)
        {
            minY = currentY;
        }
    }

    return minY;
}

double Triangle::getMinZ()
{
    double currentZ,
        minZ = INT_MAX;

    for (int i = 0; i < 3; i++)
    {
        currentZ = vertexes[i].getZ();

        if (vertexes[i].getZ() < minZ)
        {
            minZ = currentZ;
        }
    }

    return minZ;
}

double Triangle::distEuclid(Point A, Point B)
{
    return sqrt((A.getX() - B.getX()) * (A.getX() - B.getX()) + (A.getY() - B.getY()) * (A.getY() - B.getY()) + (A.getZ() - B.getZ()) * (A.getZ() - B.getZ()));
}

double Triangle::s(Point A, Point B, Point C)
{
    double a = distEuclid(A, B);
    double b = distEuclid(B, C);
    double c = distEuclid(A, C);
    double p = (a + b + c) / 2.0;
    return sqrt(fabs(p * (p - a) * (p - b) * (p - c)));
}

bool Triangle::contains(Point point)
{
    // Point a = this->vertexes[0];
    // Point b = this->vertexes[1];
    // Point c = this->vertexes[2];

    // double t1 = (a.getX() - point.getX()) * (b.getY() - a.getY()) - (b.getX() - a.getX()) * (a.getY() - point.getY()),
    //        t2 = (b.getX() - point.getX()) * (c.getY() - b.getY()) - (c.getX() - b.getX()) * (b.getY() - point.getY()),
    //        t3 = (c.getX() - point.getX()) * (a.getY() - c.getY()) - (a.getX() - c.getX()) * (c.getY() - point.getY());

    // if (t1 >= 0 && t2 >= 0 && t3 >= 0)
    //     return true;

    // if (t1 < 0 && t2 < 0 && t3 < 0)
    //     return true;

    // return false;
    return s(point, this->vertexes[0], this->vertexes[1]) + s(point, this->vertexes[0], this->vertexes[2]) + s(this->vertexes[1], this->vertexes[2], point) - 1e-5 < s(this->vertexes[0], this->vertexes[1], this->vertexes[2]);
}

Point Triangle::intersect(Line line)
{
    Plane trianglePlane(this->vertexes[0], this->vertexes[1], this->vertexes[2]);
    Point intersectPoint = trianglePlane.intersect(line);

    if (this->contains(intersectPoint))
    {
        return intersectPoint;
    }

    return Point(-9999, -9999, -9999);
}
