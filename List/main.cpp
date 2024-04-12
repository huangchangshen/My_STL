#include <iostream>
#include <list.h>

using namespace hcs::stl;
int main()
{
    List<int> L;
    for (int i = 0; i < 10; ++i)
    {
        L.push_back(i);
    }

    for (auto it = L.rbegin(); it != L.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}