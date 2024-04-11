#include <iostream>
#include <array.h>

using namespace hcs::array;

int main()
{
    Array<int, 10> arr;
    for (int i = 0; i < 10; ++ i)
    {
        arr[i] = i;
    }
    arr.show();
    for (auto it = arr.rbegin(); it != arr.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}