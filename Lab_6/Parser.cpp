#include "Parser.hpp"

using namespace std;

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

void Point::print()
{
    printf("Point: % 2.6f, % 2.6f, % 2.6f \n", this->x, this->y, this->z);
}

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

double Vector::getLength()
{
    return this->length;
}

void Vector::print()
{
    printf("Point: % 2.6f, % 2.6f, % 2.6f, %2.6f\n", this->x, this->y, this->z, this->length);
}


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

vector<string> Parser::split(string line, char separator)
{
    vector<string> tokens;
    string token;

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == separator || i == line.length() - 1)
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
    vector<string> splittedLine = split(line, ' ');
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
    vector<string> splittedLine = split(trim(line), ' ');
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

void Parser::print()
{
    for (int i = 0; i < this->triangles.size(); i++)
    {
        cout << "#" << i + 1 << endl;
        this->triangles[i].print();
        cout << endl;
    }
}