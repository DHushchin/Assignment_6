#include "Octree.hpp"

using namespace std;

int main()
{
    Parser parser;
    parser.parse("objects//sphere.obj");
    parser.print();
    cout << "Min "; parser.findMinPoint().print();
    cout << "Max "; parser.findMaxPoint().print();
    Box box(parser.findMinPoint(), parser.findMaxPoint());
    
    
    return 0;
}
