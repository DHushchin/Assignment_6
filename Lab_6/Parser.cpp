#include "Parser.hpp"

using namespace std;


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

Point Parser::findMinPoint() {
    Point Min(0, 0, 0);
    for (int i = 0; i < this->triangles.size(); i++)
    {
        double MinX = this->triangles[i].getMinX();
        double MinY = this->triangles[i].getMinY();
        double MinZ = this->triangles[i].getMinZ();
        if (Min.getX() > MinX)
            Min.setX(MinX);
        if (Min.getY() > MinY)
            Min.setY(MinY);
        if (Min.getZ() > MinZ)
            Min.setZ(MinZ);
    }
    return Min;
}


Point Parser::findMaxPoint() {
    Point Max(0, 0, 0);
    for (int i = 0; i < this->triangles.size(); i++)
    {
        double MaxX = this->triangles[i].getMaxX();
        double MaxY = this->triangles[i].getMaxY();
        double MaxZ = this->triangles[i].getMaxZ();
        if (Max.getX() < MaxX)
            Max.setX(MaxX);
        if (Max.getY() < MaxY)
            Max.setY(MaxY);
        if (Max.getZ() < MaxZ)
            Max.setZ(MaxZ);
    }
    return Max;
}