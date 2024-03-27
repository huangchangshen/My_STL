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

    for (auto item = v.rbegin(); item != v.rend(); item ++)
    {
        std::cout << *item << " ";
    }

    return 0;
}