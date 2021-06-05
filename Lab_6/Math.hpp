#pragma once
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

enum class Position {
    TLF = 0, // top left front
    TRF = 1, // top right front
    BRF = 2, // bottom right front
    BLF = 3, // bottom left front
    TLB = 4, // top left back
    TRB = 5, // top right back
    BRB = 6, // bottom right back
    BLB = 7, // bottom left back
    UNDEFINED
};


class Shape
{
public:
    virtual void print() {}
};


class Point : public Shape
{
private:
    double x;
    double y;
    double z;
    Position pos;
public:
    Point() {}
    Point(double x, double y, double z) : x(x), y(y), z(z), pos(Position::UNDEFINED) {}
    void print();
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setPos(Position pos);
    Position getPos();
    double getX();
    double getY();
    double getZ();
};


class Vector : public Shape
{
private:
    double x;
    double y;
    double z;
    double length;

public:
public:
    Vector() {};
    Vector(Point a, Point b);
    Vector(double x, double y, double z);
    double getX();
    double getY();
    double getZ();
    double getLength();
    void print();
};

class Line : public Shape
{
private:
    Point firstPoint;
    Point secondPoint;
    Vector directionVector;

public:
    Line(Point firstPoint, Point secondPoint);
    Vector getDirectionVector();
    bool contains(Point point);
    void print();
};

class Triangle : public Shape
{
private:
    Point vertexes[3];
    bool inserted;
public:
    Triangle() {}
    Triangle(Point a, Point b, Point c);
    void setInsert();
    bool getInsert();
    vector<Point> getPoints();
    double getMaxX();
    double getMaxY();
    double getMaxZ();
    double getMinX();
    double getMinY();
    double getMinZ();
    void print();
    bool LineIntersect(Line& line);
};

