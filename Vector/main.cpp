#include <iostream>
#include "Vector.h"

using namespace Vector_stl;

int main()
{
    Vector<int> v;
    for (int i = 1; i <= 10; ++ i)
    {
        v.push_back(i);
    }
    // v.show();

    // v.resize(12);
    // v.show();

    // v.reserve(20);
    // v.show();

    v.insert(v.begin(), 7, 9);
    v.show();

    v.erase(v.end() - 1);
    v.show();

    v.erase(v.begin(), v.end());
    v.show();
    return 0;
}