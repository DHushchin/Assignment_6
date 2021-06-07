#include "Box.h"

Box::Box() {}

Box::Box(Point startPoint, Point endPoint)
{
    this->top_left_front = startPoint;
    this->bottom_right_back = endPoint;
}

Box::Box(const Box& box)
{
    this->bottom_right_back = box.bottom_right_back;
    this->top_left_front = box.top_left_front;
    this->triangles = box.triangles;
}

void Box::resize(Position pos)
{
    double midX = (top_left_front.getX() + bottom_right_back.getX()) * 0.5,
           midY = (top_left_front.getY() + bottom_right_back.getY()) * 0.5,
           midZ = (top_left_front.getZ() + bottom_right_back.getZ()) * 0.5;

    switch (pos)
    {
    case Position::TLF:
        this->bottom_right_back.setX(midX);
        this->bottom_right_back.setY(midY);
        this->bottom_right_back.setZ(midZ);
        break;

    case Position::TRF:
        this->top_left_front.setX(midX);
        this->bottom_right_back.setY(midY);
        this->bottom_right_back.setZ(midZ);
        break;

    case Position::BRF:
        this->top_left_front.setX(midX);
        this->top_left_front.setY(midY);
        this->bottom_right_back.setZ(midZ);
        break;

    case Position::BLF:
        this->bottom_right_back.setX(midX);
        this->top_left_front.setY(midY);
        this->bottom_right_back.setZ(midZ);
        break;

    case Position::TLB:
        this->bottom_right_back.setX(midX);
        this->bottom_right_back.setY(midY);
        this->top_left_front.setZ(midZ);
        break;
    case Position::TRB:
        this->top_left_front.setX(midX);
        this->bottom_right_back.setY(midY);
        this->top_left_front.setZ(midZ);
        break;

    case Position::BRB:
        this->top_left_front.setX(midX);
        this->top_left_front.setY(midY);
        this->top_left_front.setZ(midZ);
        break;

    case Position::BLB:
        this->bottom_right_back.setX(midX);
        this->top_left_front.setY(midY);
        this->top_left_front.setZ(midZ);
        break;
    }
}

void Box::setTLF(Point point)
{
    this->top_left_front = point;
}

void Box::setBRB(Point point)
{
    this->bottom_right_back = point;
}

Point Box::getTLF()
{
    return this->top_left_front;
}

Point Box::getBRB()
{
    return this->bottom_right_back;
}

void Box::setTriangle(Triangle& triangle)
{
    this->triangles.push_back(triangle);
}

vector<Triangle> Box::getTriangles()
{
    return this->triangles;
}

bool Box::IntersectCurrentPlane(Line line, Point& intersect, int a, int b, int c,int d) {
	double tmp, tmp2;
	tmp = a * line.getDirectionVector().getX() + b * line.getDirectionVector().getY() + c * line.getDirectionVector().getZ();
	if (abs(tmp) < 1e-3)
		return false;
	tmp2 = -(a*line.getFirstPoint().getX() + b * line.getFirstPoint().getY() + c * line.getFirstPoint().getZ() + d) / tmp;
	intersect = Point(line.getFirstPoint().getX() + line.getDirectionVector().getX() * tmp2, line.getFirstPoint().getZ() + line.getDirectionVector().getZ() * tmp2, line.getFirstPoint().getZ() + line.getDirectionVector().getZ() * tmp2);
	return true;
}

bool Box::IfIntersect(Point & p1, Point & p2, Point & p3, Line & line, Point & intersect) {

	double a, b, c, d, mod;

	a = p2.getY()*p3.getZ() - p1.getY()*p3.getZ() - p2.getY()* p1.getZ() - p3.getY() * p2.getZ() + p3.getY()*p1.getZ() + p1.getY()*p2.getZ();
	b = p2.getZ()*p3.getX() - p1.getZ()*p3.getX() - p2.getZ()* p1.getX() - p3.getZ() * p2.getX() + p3.getZ()*p1.getX() + p1.getZ()*p2.getZ();
	c = p2.getX()*p3.getY() - p1.getX()*p3.getY() - p2.getX()* p1.getY() - p3.getX() * p2.getY() + p3.getX()*p1.getY() + p1.getX()*p2.getY();

	/*Normalize*/
	mod = sqrt(pow(a, 2)*pow(b, 2)*pow(c, 2));
	mod = 1 / mod;
	a = a * mod;
	b = b * mod;
	c = c * mod;
	/**/
	d = -p1.getX()*a - p1.getY()*b - p1.getZ() * c;

	if (IntersectCurrentPlane(line, intersect, a, b, c, d))
		if (intersect.getX() >= p1.getX() && intersect.getX() <= p2.getX() && intersect.getY() >= p1.getY() && intersect.getY() <= p3.getY())
			return true;
}

bool Box::lineIntersect(Line &line)
{
	Point p1, p2, p3, intersect;

	/*front*/
	p1 = this->top_left_front;
	p2 = this->top_left_front;
	p2.setZ(this->bottom_right_back.getZ());
	p3 = this->top_left_front;
	p3.setY(this->bottom_right_back.getY());

	if (IfIntersect(p1, p2, p3, line, intersect))
		return true;
	/*front-right*/
	p1 = this->bottom_right_back;
	p2 = this->bottom_right_back;
	p2.setZ(this->top_left_front.getZ());
	p3 = this->bottom_right_back;
	p3.setX(this->top_left_front.getX());

	if (IfIntersect(p1, p2, p3, line, intersect))
		return true;
	/*front-top*/
	p1 = this->top_left_front;
	p2 = this->top_left_front;
	p2.setX(this->bottom_right_back.getX());
	p3 = this->top_left_front;
	p3.setY(this->bottom_right_back.getY());

	if (IfIntersect(p1, p2, p3, line, intersect))
		return true;
	/*back*/
	p1 = this->bottom_right_back;
	p2 = this->bottom_right_back;
	p2.setY(this->top_left_front.getY());
	p3 = this->bottom_right_back;
	p3.setZ(this->top_left_front.getZ());

	if (IfIntersect(p1, p2, p3, line, intersect))
		return true;
	/*bottom*/
	p1 = this->top_left_front;
	p2 = this->top_left_front;
	p2.setX(this->bottom_right_back.getX());
	p3 = this->bottom_right_back;

	if (IfIntersect(p1, p2, p3, line, intersect))
		return true;
	/*back-left*/
	p1 = this->top_left_front;
	p2 = this->top_left_front;
	p2.setZ(this->bottom_right_back.getZ());
	p3 = this->top_left_front;
	p3.setY(this->bottom_right_back.getY());

	if (IfIntersect(p1, p2, p3, line, intersect))
		return true;

    return false;

}