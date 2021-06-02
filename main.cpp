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

    void print()
    {
        printf("Point: % 2.6f, % 2.6f, % 2.6f \n", this->x, this->y, this->z);
    }

    double getX();

    double getY();

    double getZ();
};

double Point::getX()
{
    return this->x;
}

double Point::getY()
{
    return this->y;
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
    Triangle() {}

    Triangle(Point a, Point b, Point c);

    double getMaxX();

    double getMaxY();

    double getMaxZ();

    void print();
};

Triangle::Triangle(Point a, Point b, Point c)
{
    this->vertexes[0] = a;
    this->vertexes[1] = b;
    this->vertexes[2] = c;
}

double Triangle::getMaxX()
{
    double currentX;
    double maxX = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        currentX = vertexes[i].getX();

        if (vertexes[i].getX() > maxX)
        {
            maxX = currentX;
        }
    }

    return maxX;
}

double Triangle::getMaxY()
{
    double currentY;
    double maxY = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        currentY = vertexes[i].getY();

        if (vertexes[i].getY() > maxY)
        {
            maxY = currentY;
        }
    }

    return maxY;
}

double Triangle::getMaxZ()
{
    double currentZ;
    double maxZ = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        currentZ = vertexes[i].getZ();

        if (vertexes[i].getZ() > maxZ)
        {
            maxZ = currentZ;
        }
    }

    return maxZ;
}

void Triangle::print()
{
    cout << "Triangle: " << endl;
    for (int i = 0; i < 3; i++)
    {
        vertexes[i].print();
    }
}

class Vector : public Shape
{
private:
    double x;
    double y;
    double z;
    double length;

public:
    Vector() {}

    Vector(Point a, Point b);

    Vector(double x, double y, double z) : x(x), y(y), z(z), length(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) {}

    double getLength();

    void print();
};

Vector::Vector(Point a, Point b)
{
    this->x = a.getX() - b.getX();
    this->y = a.getY() - b.getY();
    this->z = a.getZ() - b.getZ();
    this->length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double Vector::getLength()
{
    return this->length;
}

void Vector::print()
{
    printf("Point: % 2.6f, % 2.6f, % 2.6f, %2.6f\n", this->x, this->y, this->z, this->length);
}

class Box
{
};

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

string Parser::trim(string line)
{
    string trimmed = line;
    int i = 0;

    while (trimmed.size() && (isspace(trimmed.front()) || trimmed.front() == '\r'))
    {
        trimmed.erase(trimmed.begin());
    }

    while (trimmed.size() && (isspace(trimmed.back()) || trimmed.back() == '\r'))
    {
        trimmed.pop_back();
    }

    return trimmed;
}

vector<string> Parser::split(string line, string separator)
{
    vector<string> tokens;
    string token;

    for (int i = 0; i < line.length(); i++)
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

    for (int i = 0; i < splittedLine.size(); i++)
    {
        coordinates[i] = stod(splittedLine[i]);
    }

    Point point(coordinates[0], coordinates[1], coordinates[2]);

    return point;
}

Triangle Parser::parseTriangle(string line)
{
    vector<string> splittedLine = split(trim(line), " ");
    splittedLine.erase(splittedLine.begin());
    Point vertexes[3];

    for (int i = 0; i < splittedLine.size(); i++)
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
        if (currentLine != "")
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
}

vector<Point> Parser::getPoints()
{
    return this->points;
}

void Parser::print()
{
    for (int i = 0; i < this->triangles.size(); i++)
    {
        cout << "#" << i + 1 << endl;
        this->triangles[i].print();
        cout << endl;
    }
}

class Node
{
private:
    vector<Node> children;
    vector<Triangle> triangles;
    Box box;

public:
    Node() {}

    void addTriangle(Triangle triangle);

    void addChild(Node node);
};

void Node::addTriangle(Triangle triangle)
{
    this->triangles.push_back(triangle);
}

void Node::addChild(Node node)
{
    this->children.push_back(node);
}

class Screen
{
private:
    Point base;
    int width;
    int height;
    string **array;

public:
    Screen(int width, int height) : width(width), height(height), base(0, -5, 0)
    {
        array = new string *[height];

        for (size_t i = 0; i < height; i++)
        {
            array[i] = new string[width];
            for (size_t j = 0; j < width; j++)
            {
                array[i][j] = " ";
            }
        }
    }

    void addPixel(int x, int z)
    {
        this->array[x][z] = "*";
    }

    void print()
    {
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                cout << array[i][j];
            }
            cout << endl;
        }
    }

    Point getBase();
};

Point Screen::getBase()
{
    return this->base;
}

class Camera
{
private:
    Point base;
    Screen screen;

public:
    Camera() : base(Point(0, -10, 0)), screen(100, 100) {}

    void photo(vector<Point> points)
    {
        double x1 = base.getX();
        double y1 = base.getY();
        double z1 = base.getZ();

        double x2;
        double y2;
        double z2;

        double t;

        double x;
        double y;
        double z;

        for (size_t i = 0; i < points.size(); i++)
        {
            x2 = points[i].getX();
            y2 = points[i].getY();
            z2 = points[i].getZ();

            t = (-5 - y1) / (y2 - y1);

            x = t * (x2 - x1) + x1;
            y = t * (y2 - y1) + y1;
            z = t * (z2 - z1) + z1;

            screen.addPixel(floor(x * 5) < 0 ? 50 + abs(floor(x * 5)) : 50 - floor(x * 20), floor(z * 20) < 0 ? 50 + abs(floor(z * 20)) : 50 - floor(z * 20));
        }

        screen.print();
    }
};

int main()
{
    Parser parser;
    parser.parse("sphere.obj");

    Camera camera;

    camera.photo(parser.getPoints());

    return 0;
}