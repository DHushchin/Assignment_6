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
	double nX, nY, nZ, d;
	/*Параметры плоскости*/
	nX = (vertexes[1].getY() - vertexes[0].getY()) * (vertexes[2].getZ() - vertexes[0].getZ()) - (vertexes[1].getZ() - vertexes[0].getZ()) * (vertexes[2].getY() - vertexes[0].getY());
	nY = (vertexes[1].getZ() - vertexes[0].getZ()) * (vertexes[2].getX() - vertexes[0].getX()) - (vertexes[1].getX() - vertexes[0].getX()) * (vertexes[2].getZ() - vertexes[0].getZ());
	nZ = (vertexes[1].getX() - vertexes[0].getX()) * (vertexes[2].getY() - vertexes[0].getY()) - (vertexes[1].getY() - vertexes[0].getY()) * (vertexes[2].getX() - vertexes[0].getX());
    
	/*Нормализовать Н*/
	double mod = sqrt(pow(nX,2)*pow(nY, 2)*pow(nZ, 2));
	mod = 1 / mod;
	nX = nX * mod;
	nY = nY * mod;
	nZ = nZ * mod;
	/**/

	d = -nX * vertexes[0].getX() - nY * vertexes[0].getY() - nZ * vertexes[0].getZ();

	double tmp1;

	tmp1 = nX * (line.secondPoint.getX() - line.firstPoint.getX()) + nY * (line.secondPoint.getY() - line.firstPoint.getY()) + nZ * (line.secondPoint.getZ() - line.firstPoint.getZ());
	if (abs(tmp1) < 1e-3)
		return false;

	double tmp2;

	tmp2 = -(d + nX * line.firstPoint.getX() + nY * line.firstPoint.getY() + nZ * line.firstPoint.getZ());

	Point * intersectPoint = new Point(line.firstPoint.getX() + tmp2 * (line.secondPoint.getX() - line.firstPoint.getX()), line.firstPoint.getY() + tmp2 * (line.secondPoint.getY() - line.firstPoint.getY()), line.firstPoint.getZ() + tmp2 * (line.secondPoint.getZ() - line.firstPoint.getZ()));

	if (tmp2 < 0 || tmp2 > 1)
		return false;

	Point * newVerterex = new Point[3];

	newVerterex[0].setX(vertexes[0].getX() - intersectPoint->getX());
	newVerterex[0].setY(vertexes[0].getY() - intersectPoint->getY());
	newVerterex[0].setZ(vertexes[0].getZ() - intersectPoint->getZ());

	/*Normalize newVertex[0]*/
	mod = sqrt(pow(newVerterex[0].getX(),2) * pow(newVerterex[0].getY(), 2) * pow(newVerterex[0].getZ(), 2));
	mod = 1 / mod;
	newVerterex[0].setX(newVerterex[0].getX() * mod);
	newVerterex[0].setY(newVerterex[0].getY() * mod);
	newVerterex[0].setZ(newVerterex[0].getZ() * mod);
	/**/

	newVerterex[1].setX(vertexes[1].getX() - intersectPoint->getX());
	newVerterex[1].setY(vertexes[1].getY() - intersectPoint->getY());
	newVerterex[1].setZ(vertexes[1].getZ() - intersectPoint->getZ());


	/*Normalize newVertex[1]*/
	mod = sqrt(pow(newVerterex[1].getX(), 2) * pow(newVerterex[1].getY(), 2) * pow(newVerterex[1].getZ(), 2));
	mod = 1 / mod;
	newVerterex[1].setX(newVerterex[1].getX() * mod);
	newVerterex[1].setY(newVerterex[1].getY() * mod);
	newVerterex[1].setZ(newVerterex[1].getZ() * mod);
	/**/

	newVerterex[2].setX(vertexes[2].getX() - intersectPoint->getX());
	newVerterex[2].setY(vertexes[2].getY() - intersectPoint->getY());
	newVerterex[2].setZ(vertexes[2].getZ() - intersectPoint->getZ());
	/*Normalize newVertex[2]*/
	mod = sqrt(pow(newVerterex[2].getX(), 2) * pow(newVerterex[2].getY(), 2) * pow(newVerterex[2].getZ(), 2));
	mod = 1 / mod;
	newVerterex[2].setX(newVerterex[2].getX() * mod);
	newVerterex[2].setY(newVerterex[2].getY() * mod);
	newVerterex[2].setZ(newVerterex[2].getZ() * mod);
	/**/

	double a1, a2, a3;
	a1 = newVerterex[0].getX()*newVerterex[1].getX() + newVerterex[0].getY()*newVerterex[1].getY() + newVerterex[0].getZ()*newVerterex[1].getZ();
	a2 = newVerterex[1].getX()*newVerterex[2].getX() + newVerterex[1].getY()*newVerterex[2].getY() + newVerterex[1].getZ()*newVerterex[2].getZ();
	a3 = newVerterex[2].getX()*newVerterex[0].getX() + newVerterex[2].getY()*newVerterex[0].getY() + newVerterex[2].getZ()*newVerterex[0].getZ();
	
	double total;

	total = (acos(a1) + acos(a2) + acos(a3)) * (180/3.14159265);

	if (abs(total - 360) > 1e-3)
		return false;

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

