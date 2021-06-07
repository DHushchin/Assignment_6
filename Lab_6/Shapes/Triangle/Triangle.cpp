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

void Triangle::setInserted()
{
    this->isInserted = true;
}

bool Triangle::getInserted()
{
    return this->isInserted;
}

vector<Point> Triangle::getPoints()
{
    vector<Point> points;

    for (int i = 0; i < 3; i++)
    {
        points.push_back(vertexes[i]);
    }

    return points;
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

bool Triangle::lineIntersect(Line &line)
{
    if (getIntersectPoint(line) == NULL)
        return false;
    Point* intersectPoint = getIntersectPoint(line);

    Point *newVertex = new Point[3];
    getNewVertex(newVertex, intersectPoint);

    double a1, a2, a3;
    a1 = newVertex[0].getX() * newVertex[1].getX() + newVertex[0].getY() * newVertex[1].getY() + newVertex[0].getZ() * newVertex[1].getZ();
    a2 = newVertex[1].getX() * newVertex[2].getX() + newVertex[1].getY() * newVertex[2].getY() + newVertex[1].getZ() * newVertex[2].getZ();
    a3 = newVertex[2].getX() * newVertex[0].getX() + newVertex[2].getY() * newVertex[0].getY() + newVertex[2].getZ() * newVertex[0].getZ();

    double total = (acos(a1) + acos(a2) + acos(a3)) * (180 / M_PI);

    if (abs(total - 360) > 1e-3)
        return false;

    return true;
}


Point* Triangle::getIntersectPoint(Line& line) {
    double nX, nY, nZ, d, mod;

    nX = (vertexes[1].getY() - vertexes[0].getY()) * (vertexes[2].getZ() - vertexes[0].getZ()) - (vertexes[1].getZ() - vertexes[0].getZ()) * (vertexes[2].getY() - vertexes[0].getY());
    nY = (vertexes[1].getZ() - vertexes[0].getZ()) * (vertexes[2].getX() - vertexes[0].getX()) - (vertexes[1].getX() - vertexes[0].getX()) * (vertexes[2].getZ() - vertexes[0].getZ());
    nZ = (vertexes[1].getX() - vertexes[0].getX()) * (vertexes[2].getY() - vertexes[0].getY()) - (vertexes[1].getY() - vertexes[0].getY()) * (vertexes[2].getX() - vertexes[0].getX());

    mod = sqrt(pow(nX, 2) * pow(nY, 2) * pow(nZ, 2));
    mod = 1 / mod;
    nX = nX * mod;
    nY = nY * mod;
    nZ = nZ * mod;

    d = -nX * vertexes[0].getX() - nY * vertexes[0].getY() - nZ * vertexes[0].getZ();

     double tmp1 = nX * (line.getSecondPoint().getX() - line.getFirstPoint().getX()) +
           nY * (line.getSecondPoint().getY() - line.getSecondPoint().getY()) + 
           nZ * (line.getSecondPoint().getZ() - line.getFirstPoint().getZ());

    if (abs(tmp1) < 1e-3)
        return NULL;

     double tmp2 = -(d + nX * line.getFirstPoint().getX() + nY * line.getFirstPoint().getY() + nZ * line.getFirstPoint().getZ());

    if (tmp2 < 0 || tmp2 > 1)
        return NULL;

    Point* intersectPoint = new Point(line.getFirstPoint().getX() + tmp2 * (line.getSecondPoint().getX() - line.getFirstPoint().getX()), line.getFirstPoint().getY() + tmp2 * (line.getSecondPoint().getY() - line.getFirstPoint().getY()), line.getFirstPoint().getZ() + tmp2 * (line.getSecondPoint().getZ() - line.getFirstPoint().getZ()));

    return intersectPoint;
}


void Triangle::getNewVertex(Point* newVertex, Point* intersectPoint) 
{
    for (int i = 0; i < 3; i++) {
        newVertex[i].setX(vertexes[i].getX() - intersectPoint->getX());
        newVertex[i].setY(vertexes[i].getY() - intersectPoint->getY());
        newVertex[i].setZ(vertexes[i].getZ() - intersectPoint->getZ());

        double mod = sqrt(pow(newVertex[i].getX(), 2) * pow(newVertex[i].getY(), 2) * pow(newVertex[i].getZ(), 2));
        mod = 1 / mod;
        newVertex[i].setX(newVertex[0].getX() * mod);
        newVertex[i].setY(newVertex[0].getY() * mod);
        newVertex[i].setZ(newVertex[0].getZ() * mod);
    }
}