#include "Octree.hpp"

using namespace std;


int main()
{
    Parser parser;
    parser.parse("objects//sphere.obj");
    parser.print();
    Octree* root = new Octree();
    return 0;
}
