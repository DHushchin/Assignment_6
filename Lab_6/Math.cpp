#include "Math.hpp"


using namespace std;

void Point::setX(double x) 
{
    this->x = x;
}

void Point::setY(double y) 
{
    this->y = y;
}

void Point::setZ(double z) 
{
    this->z = z;
}

void Point::setPos(Position pos) 
{
    this->pos = pos;
}

Position Point::getPos() 
{
    return pos;
}

double Point::getX()
{
    return this->x;
}

double Point::getY()
{
    return this->y;
}

double Point::getZ()
{
    return this->z;
}

void Point::print()
{
    printf("Point: % 2.6f, % 2.6f, % 2.6f \n", this->x, this->y, this->z);
}

Triangle::Triangle(Point a, Point b, Point c)
{
    this->vertexes[0] = a;
    this->vertexes[1] = b;
    this->vertexes[2] = c;
    inserted = false;
}

void Triangle::setInsert() {
    inserted = true;
}

bool Triangle::getInsert() {
    return inserted;
}

vector<Point> Triangle::getPoints() {
    vector<Point> points;
    for (int i = 0; i < 3; i++)
        points.push_back(vertexes[i]);
    return points;
}

double Triangle::getMaxX()
{
    double currentX;
    double maxX = INT_MIN;

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
    double currentY;
    double maxY = INT_MIN;

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
    double currentZ;
    double maxZ = INT_MIN;

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

double Triangle::getMinX()
{
    double currentX;
    double minX = INT_MAX;

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
    double currentY;
    double minY = INT_MAX;

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
    double currentZ;
    double minZ = INT_MAX;

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

void Triangle::print()
{
    cout << "Triangle: " << endl;
    for (int i = 0; i < 3; i++)
    {
        vertexes[i].print();
    }
}

double Vector::getLength()
{
    return this->length;
}

void Vector::print()
{
    printf("Point: % 2.6f, % 2.6f, % 2.6f, %2.6f\n", this->x, this->y, this->z, this->length);
}

