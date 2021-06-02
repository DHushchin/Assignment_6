#include <vector>
#include <string>
#include <fstream>
#include <iostream>

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
    Point() : x(0), y(0), z(0) {}

    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    void setX(double x);

    double getX();

    void setY(double y);

    double getY();

    void setZ(double z);

    double getZ();

    void print()
    {
        printf("Point: % 2.6f, % 2.6f, % 2.6f \n", this->x, this->y, this->z);
    }
};

void Point::setX(double x)
{
    this->x = x;
}

double Point::getX()
{
    return this->x;
}

void Point::setY(double y)
{
    this->y = y;
}

double Point::getY()
{
    return this->y;
}

void Point::setZ(double z)
{
    this->z = z;
}

double Point::getZ()
{
    return this->z;
}

class Triangle : public Shape
{
private:
    Point vertexes[3];

public:
    Triangle(Point a, Point b, Point c);

    void print()
    {
        cout << "Triangle: " << endl;
        for (size_t i = 0; i < 3; i++)
        {
            vertexes[i].print();
        }
    }
};

Triangle::Triangle(Point a, Point b, Point c)
{
    this->vertexes[0] = a;
    this->vertexes[1] = b;
    this->vertexes[2] = c;
}

class Parser
{
private:
    vector<Point> points;
    vector<Triangle> triangles;

    vector<string> split(string line, string separator);

    Point parsePoint(string line);

    Triangle parseTriangle(string line);

public:
    Parser() {}

    void parse(string fileName);

    void print();
};

vector<string> Parser::split(string line, string separator)
{
    vector<string> tokens;
    string token;

    for (size_t i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ' || i == line.length() - 1)
        {
            tokens.push_back(token);
            token = "";
        }
        else
        {
            token += line[i];
        }
    }

    return tokens;
}

Point Parser::parsePoint(string line)
{
    vector<string> splittedLine = split(line, " ");
    splittedLine.erase(splittedLine.begin());
    double coordinates[3];

    for (size_t i = 0; i < splittedLine.size(); i++)
    {
        coordinates[i] = stod(splittedLine[i]);
    }

    Point point(coordinates[0], coordinates[1], coordinates[2]);

    return point;
}

Triangle Parser::parseTriangle(string line)
{
    vector<string> splittedLine = split(line, " ");
    splittedLine.erase(splittedLine.begin());
    Point vertexes[3];

    for (size_t i = 0; i < splittedLine.size(); i++)
    {
        string currentToken = splittedLine[i];
        int pointIndex = stoi(currentToken.substr(0, currentToken.find("/"))) - 1;

        vertexes[i] = this->points[pointIndex];
    }

    Triangle triangle(vertexes[0], vertexes[1], vertexes[2]);

    return triangle;
}

void Parser::parse(string fileName)
{
    ifstream file(fileName);
    string currentLine;

    while (getline(file, currentLine))
    {
        if (currentLine.find("v ") != string::npos)
        {
            Point point = parsePoint(currentLine);

            this->points.push_back(point);
        }
        else if (currentLine.find("f ") != string::npos)
        {
            Triangle triangle = parseTriangle(currentLine);

            this->triangles.push_back(triangle);
        }
    }
}

void Parser::print()
{
    for (size_t i = 0; i < this->triangles.size(); i++)
    {
        cout << "#" << i + 1 << endl;
        this->triangles[i].print();
        cout << endl;
    }
}

class Box
{
};

class Node
{
private:
    vector<Node> children;
    vector<Triangle> triangles;
    Box box;

public:
    Node() {}

    void addTriangle(Triangle triangle);

    void addChild(Node node)
};

void Node::addTriangle(Triangle triangle)
{
    this->triangles.push_back(triangle);
}

void Node::addChild(Node node)
{
    this->children.push_back(node);
}

class Tree
{
};

int main()
{
    Parser parser;
    parser.parse("cow.obj");
    parser.print();

    return 0;
}