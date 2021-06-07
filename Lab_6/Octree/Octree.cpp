#include "Octree.h"

Octree::Octree() {}

Octree::Octree(Box& box)
{
    this->box = box;

    children.assign(8, NULL);
}

void Octree::setBox(Box box)
{
    this->box = box;
}

void Octree::insert(Triangle& triangle)
{

    double midX = (box.getTLF().getX() + box.getBRB().getX()) * 0.5,
           midY = (box.getTLF().getY() + box.getBRB().getY()) * 0.5,
           midZ = (box.getTLF().getZ() + box.getBRB().getZ()) * 0.5;

    Point* points = triangle.getPoints();

    for (int i = 0; i < 3; i++)
    {
        double x = points[i].getX(),
               y = points[i].getY(),
               z = points[i].getZ();

        try
        {
            if (x < box.getTLF().getX() || x > box.getBRB().getX() || y < box.getTLF().getY() || y > box.getBRB().getY() || z < box.getTLF().getZ() || z > box.getBRB().getZ())
            {
                throw "Point out of range";
            }
        }
        catch (const char* exception)
        {
            cerr << "Error: " << exception << '\n';
        }

        if (x <= midX)
        {
            if (y <= midY)
            {
                if (z <= midZ)
                {
                    points[i].setPosition(Position::TLF);
                }
                else
                {
                    points[i].setPosition(Position::TLB);
                }
            }
            else
            {
                if (z <= midZ)
                {
                    points[i].setPosition(Position::BLF);
                }
                else
                {
                    points[i].setPosition(Position::BLB);
                }
            }
        }
        else
        {
            if (y <= midY)
            {
                if (z <= midZ)
                {
                    points[i].setPosition(Position::TRF);
                }
                else
                {
                    points[i].setPosition(Position::TRB);
                }
            }
            else
            {
                if (z <= midZ)
                {
                    points[i].setPosition(Position::BRF);
                }
                else
                {
                    points[i].setPosition(Position::BRB);
                }
            }
        }
    }

    if (points[0].getPosition() == points[1].getPosition() && points[1].getPosition() == points[2].getPosition())
    {
        int index = (int)points[0].getPosition();
        if (children[index] == NULL) {
            Box newBox(box);
            newBox.resize(points[0].getPosition());
            children[index] = new Octree(newBox);
        }
        children[index]->insert(triangle);
    }
    else
    {
        this->box.setTriangle(triangle);
        triangle.setInserted();
    }
}

void Octree::findIntersectedTriangles(Line &line, vector<Triangle> &IntersectedTriangles)
{
    if (children.size() > 0)
    {
        for (int i = 0; i < children.size(); i++)
        {
            if (children[i]->box.lineIntersect(line))
            {
                findIntersectedTriangles(line, IntersectedTriangles);
            }
            else
            {
                vector<Triangle> triangles = children[i]->box.getTriangles();

                for (int i = 0; i < triangles.size(); i++)
                {
                    if (triangles[i].lineIntersect(line))
                    {
                        IntersectedTriangles.push_back(triangles[i]);
                    }
                }
            }
        }
    }
}