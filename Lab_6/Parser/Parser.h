#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "../Shapes/Point/Point.h"
#include "../Shapes/Triangle/Triangle.h"

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

    vector<Triangle>& getTriangles();

    Point findMaxPoint();

    Point findMinPoint();

    void print();
};