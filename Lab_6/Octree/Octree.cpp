#include "Octree.h"

Octree::Octree() {}

Octree::Octree(Box& box)
{
    this->box = box;
    this->children = new Octree*[8];
    for (int i = 0; i < 8; i++)
        children[i] = NULL;
}

void Octree::insert(Triangle& triangle)
{
    if (triangle.getInserted())
        return;
    double midX = (this->box.getTLF().getX() + this->box.getBRB().getX()) * 0.5,
           midY = (this->box.getTLF().getY() + this->box.getBRB().getY()) * 0.5,
           midZ = (this->box.getTLF().getZ() + this->box.getBRB().getZ()) * 0.5;

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

    if (triangle.getPoints()[0].getPosition() == triangle.getPoints()[1].getPosition() && 
        triangle.getPoints()[1].getPosition() == triangle.getPoints()[2].getPosition())
    {
        int index = (int)points[0].getPosition();

        if (children[index] == NULL)
        {
            delete children[index];
            Box newBox(box);
            newBox.resize(points[0].getPosition());
            children[index] = new Octree(newBox);           
        }
        children[index]->insert(triangle);
        
    }
    else if (!triangle.getInserted())
    {
        this->box.setTriangle(triangle);
        triangle.setInserted(true);
    }
}

void Octree::findIntersectedPoint(Line& line, Point& currentPoint, Point& resultPoint, double& minLength)
{
    if (this->box.lineIntersect(line))
    {

        vector<Triangle>& triangles = this->box.getTriangles();
        for (auto it = triangles.begin(); it != triangles.end(); ++it)
        {
            Point intersectPoint = (*it).intersect(line);

            if (intersectPoint.getX() != INT_MAX)
            {
                float Euclid = (*it).distEuclid(currentPoint, intersectPoint);
                if (Euclid < minLength)
                {
                    resultPoint = intersectPoint;
                    minLength = Euclid;
                }
            }
        }

        for (size_t i = 0; i < 8; i++)
        {
            if (children[i] != NULL)
                children[i]->findIntersectedPoint(line, currentPoint, resultPoint, minLength);
        }
    }
}