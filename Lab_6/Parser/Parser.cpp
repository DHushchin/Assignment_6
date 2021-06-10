#include "Parser.h"

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

Point Parser::findMinPoint()
{
    Point min(0, 0, 0);

    for (int i = 0; i < this->triangles.size(); i++)
    {
        double minX = this->triangles[i].getMinX(),
               minY = this->triangles[i].getMinY(),
               minZ = this->triangles[i].getMinZ();

        if (min.getX() > minX)
        {
            min.setX(minX);
        }

        if (min.getY() > minY)
        {
            min.setY(minY);
        }

        if (min.getZ() > minZ)
        {
            min.setZ(minZ);
        }
    }

    return min;
}

Point Parser::findMaxPoint()
{
    Point max(0, 0, 0);

    for (int i = 0; i < this->triangles.size(); i++)
    {
        double maxX = this->triangles[i].getMaxX(),
               maxY = this->triangles[i].getMaxY(),
               maxZ = this->triangles[i].getMaxZ();

        if (max.getX() < maxX)
        {
            max.setX(maxX);
        }

        if (max.getY() < maxY)
        {
            max.setY(maxY);
        }

        if (max.getZ() < maxZ)
        {
            max.setZ(maxZ);
        }
    }

    return max;
}

vector<Triangle> &Parser::getTriangles()
{
    return triangles;
}