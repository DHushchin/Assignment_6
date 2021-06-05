#include "Octree.hpp"

using namespace std;

Box::Box(Point start, Point end) 
{
	this->top_left_front = start;
	this->bottom_right_back = end;
    vector <Triangle> triangles;
}

Box::Box(const Box& other) {
    this->bottom_right_back = other.bottom_right_back;
    this->top_left_front = other.top_left_front;
    this->triangles = other.triangles;
}

void Box::resize(Position pos) 
{
    double midX = (top_left_front.getX() + bottom_right_back.getX()) / 2,
           midY = (top_left_front.getY() + bottom_right_back.getY()) / 2,
           midZ = (top_left_front.getZ() + bottom_right_back.getZ()) / 2;
    switch (pos) {
    case Position::TLF:
        bottom_right_back.setX(midX);
        bottom_right_back.setY(midY);
        bottom_right_back.setZ(midZ);
        break;
    case Position::TRF:
        top_left_front.setX(midX);
        bottom_right_back.setY(midY);
        bottom_right_back.setZ(midZ);
        break;
    case Position::BRF:
        top_left_front.setX(midX);
        top_left_front.setY(midY);
        bottom_right_back.setZ(midZ);
        break;
    case Position::BLF:
        bottom_right_back.setX(midX);
        top_left_front.setY(midY);
        bottom_right_back.setZ(midZ);
        break;
    case Position::TLB:
        bottom_right_back.setX(midX);
        bottom_right_back.setY(midY);
        top_left_front.setZ(midZ);
        break;
    case Position::TRB:
        top_left_front.setX(midX);
        bottom_right_back.setY(midY);
        top_left_front.setZ(midZ);
        break;
    case Position::BRB:
        top_left_front.setX(midX);
        top_left_front.setY(midY);
        top_left_front.setZ(midZ);
        break;
    case Position::BLB:
        bottom_right_back.setX(midX);
        top_left_front.setY(midY);
        top_left_front.setZ(midZ);
        break;
    }
}

void Box::setTLF(Point point) 
{
    top_left_front = point;
}

void Box::setBRB(Point point) 
{
    bottom_right_back = point;
}

Point Box::getTLF() 
{
    return top_left_front;
}

Point Box::getBRB() 
{
    return bottom_right_back;
}

void Box::setTriangle(Triangle triangle)
{
    triangles.push_back(triangle);
}

vector<Triangle> Box::getTriangles() {
    return triangles;
}

bool Box::LineIntersect(Line& line) {
    return true;
}

Octree::Octree(Box box) 
{
	this->box = box;
	children.assign(8, nullptr);
    for (int i = 0; i < 8; i++) {
        children[i] = new Octree();
    }
}

void Octree::setBox(Box box) 
{
    this->box = box;
}


void Octree::insert(Triangle triangle) 
{
    int midX = (box.getTLF().getX() + box.getBRB().getX()) / 2,
        midY = (box.getTLF().getY() + box.getBRB().getY()) / 2,
        midZ = (box.getTLF().getZ() + box.getBRB().getZ()) / 2;

    vector<Point> points = triangle.getPoints();
    for (int i = 0; i < 3; i++) {
        double x = points[i].getX();
        double y = points[i].getY();
        double z = points[i].getZ();

        try {
            if (x < box.getTLF().getX() || x > box.getBRB().getX()
                || y < box.getTLF().getY() || y > box.getBRB().getY()
                || z < box.getTLF().getZ() || z > box.getBRB().getZ())
                throw "Point out of range";
        }
        catch (const char* exception)
        {
            std::cerr << "Error: " << exception << '\n';
        }

        if (x <= midX) {
            if (y <= midY) {
                if (z <= midZ)
                    points[i].setPos(Position::TLF);
                else
                    points[i].setPos(Position::TLB);
            }
            else {
                if (z <= midZ)
                    points[i].setPos(Position::BLF);
                else
                    points[i].setPos(Position::BLB);
            }
        }
        else {
            if (y <= midY) {
                if (z <= midZ)
                    points[i].setPos(Position::TRF);
                else
                    points[i].setPos(Position::TRB);
            }
            else {
                if (z <= midZ)
                    points[i].setPos(Position::BRF);
                else
                    points[i].setPos(Position::BRB);
            }
        }
    }

    if (points[0].getPos() == points[1].getPos() && points[1].getPos() == points[2].getPos()) {
        int index = (int)points[0].getPos();
        Box newBox(box);
        newBox.resize(points[0].getPos());
        children[index]->setBox(newBox);
        children[index]->insert(triangle);
    }
    else if (!triangle.getInsert()) {
        box.setTriangle(triangle);
        triangle.setInsert();
    }

}


void Octree::findIntersectedTriangles(Line& line, vector<Triangle>& IntersectedTriangles) 
{
    if (children.size() > 0) {
        for (int i = 0; i < children.size(); i++) {
            if (children[i]->box.LineIntersect(line)) {
                findIntersectedTriangles(line, IntersectedTriangles);
            }
            else 
            {
                vector <Triangle> triangles = children[i]->box.getTriangles();
                for (size_t i = 0; i < triangles.size(); i++) {
                    if (triangles[i].LineIntersect(line)) {
                        IntersectedTriangles.push_back(triangles[i]);
                    }
                }
            }
        }
    }
}