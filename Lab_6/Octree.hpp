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
	Box resize(Position pos);
	void setTLF(Point point);
	void setBRB(Point point);
	Point getTLF();
	Point getBRB();	
};

class Octree {
private:
	Box box;
	vector<Octree*> children;
public:
	Octree() {};
	Octree(Box box);
	void insert(Triangle triangle);
	//Point find(Vector& ScreenRay);
};