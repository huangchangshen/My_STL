#pragma once
#include "SharedPtr.h"
#include "B.h"
class A
{
public:
    A() = default;

    ~A()
    {
        std::cout << "~A()" << std::endl;
    }

    SharedPtr<B> m_b;
}; 