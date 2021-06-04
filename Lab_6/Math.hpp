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
};


class Vector : public Shape
{
private:
    double x;
    double y;
    double z;
    double length;

public:
    Vector() {}
    Vector(double x, double y, double z) : x(x), y(y), z(z), length(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) {}
    double getLength();
    void print();
};


