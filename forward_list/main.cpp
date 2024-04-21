#include <iostream>

#include <Forward_list.h>

using namespace hcs::stl;

int main()
{
    Forward_list<int> f;
    f.assign(5, 10);
//    for (auto item = f.cbegin(); item != f.cend(); ++ item)
//    {
//        std::cout << (*item).m_value << std::endl;
//    }


//    f.insert_after(static_cast<ConstIterator<int>>(f.cbegin()), 20);
//    f.insert_after(static_cast<ConstIterator<int>>(f.cbegin()), 20);
//    f.show();
//    f.remove(20);
//    f.show();
//    f.remove_after(static_cast<ConstIterator<int>>(f.cbegin()));
//    f.show();

    Forward_list<int> f1;
    f1.assign(5,20);
    f.merge(f1);
    f.show();
    return 0;
}