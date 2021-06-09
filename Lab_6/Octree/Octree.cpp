#include "Octree.h"

Octree::Octree() {}

Octree::Octree(Box& box)
{
    this->box = box;
    children.assign(8, NULL);
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

void Octree::findIntersectedTriangles(Line& line, Point& currentPoint, Point& resultPoint, double& minLength)
{

    for (size_t i = 0; i < children.size(); i++)
    {
        if (children[i] == NULL)
            continue;

        if (children[i]->box.lineIntersect(line))
        {
            children[i]->findIntersectedTriangles(line, currentPoint, resultPoint, minLength);
        }
        else
        {
            vector<Triangle> triangles = box.getTriangles();

            for (size_t i = 0; i < triangles.size(); i++)
            {
                if (triangles[i].intersect(line).getX() != -9999)
                {
                    if (triangles[i].distEuclid(currentPoint, resultPoint) <= minLength)
                    {
                        resultPoint = triangles[i].intersect(line);
                        minLength = triangles[i].distEuclid(currentPoint, resultPoint);
                    }
                }
            }
        }
    }
}