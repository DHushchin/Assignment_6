#pragma once
#include "Parser.hpp"

using namespace std;



class Octree {
private:
	Box box;
	vector<Octree*> children;
public:
	Octree() {};

};
