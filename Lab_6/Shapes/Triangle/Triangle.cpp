#include "Triangle.h"

Triangle::Triangle(Point& a, Point& b, Point& c)
{
    this->vertexes[0] = a;
    this->vertexes[1] = b;
    this->vertexes[2] = c;
    this->isInserted = false;
}

double Triangle::getMaxX()
{
    double currentX, maxX = INT_MIN;

    for (int i = 0; i < 3; ++i)
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

    for (int i = 0; i < 3; ++i)
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

    for (int i = 0; i < 3; ++i)
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
    for (int i = 0; i < 3; ++i)
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

    for (int i = 0; i < 3; ++i)
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

    for (int i = 0; i < 3; ++i)
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

    for (int i = 0; i < 3; ++i)
    {
        currentZ = vertexes[i].getZ();

        if (vertexes[i].getZ() < minZ)
        {
            minZ = currentZ;
        }
    }

    return minZ;
}

double Triangle::distEuclid(Point& A, Point& B)
{
    return sqrt((A.getX() - B.getX()) * (A.getX() - B.getX()) + (A.getY() - B.getY()) * (A.getY() - B.getY()) + (A.getZ() - B.getZ()) * (A.getZ() - B.getZ()));
}

double Triangle::Space(Point& A, Point& B, Point& C)
{
    double a = distEuclid(A, B), b = distEuclid(B, C), c = distEuclid(A, C), p = (a + b + c) / 2.0;
    return sqrt(fabs(p * (p - a) * (p - b) * (p - c)));
}

bool Triangle::contains(Point& point)
{
    return Space(point, this->vertexes[0], this->vertexes[1]) + Space(point, this->vertexes[0], this->vertexes[2]) + Space(this->vertexes[1], this->vertexes[2], point) - 1e-5 < Space(this->vertexes[0], this->vertexes[1], this->vertexes[2]);
}

Point Triangle::intersect(Line& line)
{
    Plane trianglePlane(this->vertexes[0], this->vertexes[1], this->vertexes[2]);
    Point intersectPoint = trianglePlane.intersect(line);

    if (this->contains(intersectPoint))
    {
        return intersectPoint;
    }

    return Point(INT_MAX, INT_MAX, INT_MAX);
}
