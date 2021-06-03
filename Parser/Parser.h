#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "../Shapes/Point.h"
#include "../Shapes/Triangle.h"

using namespace std;

class Parser
{
private:
    vector<Point> points;
    vector<Triangle> triangles;

    vector<string> split(string line, string separator);

    Point parsePoint(string line);

    string trim(string line);

    Triangle parseTriangle(string line);

public:
    Parser() {}

    void parse(string fileName);

    vector<Point> getPoints();

    void print();
};