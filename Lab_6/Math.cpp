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

bool Triangle::LineIntersect(Line& line) 
{
    return true;
}

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z), length(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) {}

Vector::Vector(Point a, Point b)
{
    this->x = a.getX() - b.getX();
    this->y = a.getY() - b.getY();
    this->z = a.getZ() - b.getZ();
    this->length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double Vector::getX()
{
    return this->x;
}

double Vector::getY()
{
    return this->y;
}

double Vector::getZ()
{
    return this->z;
}

double Vector::getLength()
{
    return this->length;
}

void Vector::print()
{
    printf("Point: % 2.6f, % 2.6f, % 2.6f, %2.6f\n", this->x, this->y, this->z, this->length);
}

Line::Line(Point firstPoint, Point secondPoint) : firstPoint(firstPoint), secondPoint(secondPoint)
{
    double x = this->secondPoint.getX() - this->firstPoint.getX();
    double y = this->secondPoint.getY() - this->firstPoint.getY();
    double z = this->secondPoint.getZ() - this->firstPoint.getZ();

    this->directionVector = Vector(x, y, z);
}

Vector Line::getDirectionVector()
{
    return this->directionVector;
}

bool Line::contains(Point point)
{
    double x = point.getX();
    double y = point.getY();
    double z = point.getZ();

    if (((x - this->firstPoint.getX()) / (this->directionVector.getX())) != ((y - this->firstPoint.getY()) / (this->directionVector.getY())))
    {
        return false;
    }

    if (((y - this->firstPoint.getY()) / (this->directionVector.getY())) != ((z - this->firstPoint.getZ()) / (this->directionVector.getZ())))
    {
        return false;
    }

    if (((x - this->firstPoint.getX()) / (this->directionVector.getX())) != ((z - this->firstPoint.getZ()) / (this->directionVector.getZ())))
    {
        return false;
    }

    return true;
}

void Line::print()
{
    if (this->directionVector.getX() == 0 || this->directionVector.getY() == 0 || this->directionVector.getZ() == 0)
    {
        printf("Line: x = %1.2ft + %1.2f, y = %1.2ft + %1.2f, z = %1.2ft + %1.2f \n", this->directionVector.getX(), this->firstPoint.getX(), this->directionVector.getY(), this->firstPoint.getY(), this->directionVector.getZ(), this->firstPoint.getZ());
    }
    else
    {
        printf("Line: (x - %1.2f) / %1.2f = (y - %1.2f) / %1.2f = (z - %1.2f) / %1.2f \n", this->firstPoint.getX(), this->directionVector.getX(), this->firstPoint.getY(), this->directionVector.getY(), this->firstPoint.getZ(), this->directionVector.getZ());
    }
}

