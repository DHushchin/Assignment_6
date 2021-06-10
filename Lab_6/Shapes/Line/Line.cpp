#include "Line.h"

Line::Line(Point firstPoint, Point secondPoint) : firstPoint(firstPoint), secondPoint(secondPoint)
{
    double x = this->secondPoint.getX() - this->firstPoint.getX(),
           y = this->secondPoint.getY() - this->firstPoint.getY(),
           z = this->secondPoint.getZ() - this->firstPoint.getZ();

    this->directionVector = Vector(x, y, z);
}

Vector Line::getDirectionVector()
{
    return this->directionVector;
}

bool Line::contains(Point point)
{
    double x = point.getX(),
           y = point.getY(),
           z = point.getZ();

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
        printf("Line: x = %1.3ft + %1.3f, y = %1.3ft + %1.3f, z = %1.3ft + %1.3f \n", this->directionVector.getX(), this->firstPoint.getX(), this->directionVector.getY(), this->firstPoint.getY(), this->directionVector.getZ(), this->firstPoint.getZ());
    }
    else
    {
        printf("Line: (x - %1.3f) / %1.3f = (y - %1.3f) / %1.3f = (z - %1.3f) / %1.3f \n", this->firstPoint.getX(), this->directionVector.getX(), this->firstPoint.getY(), this->directionVector.getY(), this->firstPoint.getZ(), this->directionVector.getZ());
    }
}

Point Line::getFirstPoint()
{
    return this->firstPoint;
}

Point Line::getSecondPoint()
{
    return this->secondPoint;
}