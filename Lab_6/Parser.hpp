#pragma once
#include "Math.hpp"

using namespace std;

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
    Point findMinPoint();
    Point findMaxPoint();
};


