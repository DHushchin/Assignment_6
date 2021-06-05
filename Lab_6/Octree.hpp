#pragma once
#include "Parser.hpp"

using namespace std;

class Box
{
private:
	Point top_left_front, bottom_right_back;
	vector <Triangle> triangles;
public:
	Box() {};
	Box(Point start, Point end);
	Box(const Box& other);
	void resize(Position pos);
	void setTLF(Point point);
	void setBRB(Point point);
	Point getTLF();
	Point getBRB();	
	void setTriangle(Triangle triangle);
	vector<Triangle> getTriangles();
	bool LineIntersect(Line& line);
};

class Octree {
private:
	Box box;
	vector<Octree*> children;
public:
	Octree() {};
	Octree(Box box);
	void setBox(Box box);
	void insert(Triangle triangle);
	void findIntersectedTriangles(Line& line, vector<Triangle>& intersected);
};