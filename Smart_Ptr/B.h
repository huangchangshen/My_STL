#pragma once 
#include <iostream>
#include "SharedPtr.h"
#include "WeakPtr.h"
class A;
class B 
{
public:
	B() = default;
	~B()
    {
        std::cout << "~B()" << std::endl;
    }

    WeakPtr<A> m_a;
};
