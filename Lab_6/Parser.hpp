#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

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

public:
    Point() {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    void print();
    double getX();
    double getY();
    double getZ();
};


class Triangle : public Shape
{
private:
    Point vertexes[3];

public:
    Triangle() {}
    Triangle(Point a, Point b, Point c);
    double getMaxX();
    double getMaxY();
    double getMaxZ();
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


class Box
{
};


class Parser
{
private:
    vector<Point> points;
    vector<Triangle> triangles;
    vector<string> split(string line, char separator);
    Point parsePoint(string line);
    string trim(string line);
    Triangle parseTriangle(string line);
public:
    Parser() {}
    void parse(string fileName);
    void print();
};


