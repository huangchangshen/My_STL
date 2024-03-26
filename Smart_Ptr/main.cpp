#include <iostream>
#include <Windows.h>
#include <string>
#include "SmartPtr.h"
#include "AutoPtr.h"
#include "UniquePtr.h"
#include "SharedPtr.h"
#include "A.h"
#include "B.h"

using std::string;

class Person
{
public:
    Person() = default;
    Person(int age, string name): m_age(age), m_name(name) {};

    string name() const 
    {
        return m_name; 
    }
    void name(string name) 
    {
        m_name = name;
    }

    ~Person()
    {
        std::cout << "~Person()" << std::endl;
    }

private:
    int m_age;
    string m_name;
};

int main()
{   
    auto p = new Person();

    // ------------------------------------------------------------------------------------------------
    // SmartPtr<Person> sp(p);

    // sp->name("zhangsan");
    // std::cout << sp->name() << std::endl;

    // ------------------------------------------------------------------------------------------------

    // AutoPtr<Person> ap(p);
    // ap->name("lisi");
    // // std::cout << ap->name() << std::endl;
    
    // AutoPtr<Person> ap2;
    // ap2 = ap;
    // std::cout << ap2->name() << std::endl;
    // // std::cout << ap->name() << std::endl;
    // AutoPtr 废弃的原因：多个AutoPtr 指向同一个对象，不知道哪个指针拥有对象的所有权

    // ------------------------------------------------------------------------------------------------
    //UniquePtr 不能直接进行赋值和拷贝，但是还是能进行移动拷贝和移动赋值的

    // UniquePtr<Person> up(p);
    // p->name("wangwu");
    // std::cout << up->name() << std::endl; 

    // UniquePtr<Person> up2;

    // up2 = std::move(up);
    // std::cout << up2->name() << std::endl;
    // // std::cout << up->name() << std::endl;
    // ------------------------------------------------------------------------------------------------

    // SharedPtr<Person> sp(p);
    // sp->name("zhaoliu");
    // std::cout << sp.use_count() << std::endl;
    // std::cout << sp.unique() << std::endl;
    // std::cout << std::endl;
    // SharedPtr<Person> sp2(sp);
    // std::cout << sp.use_count() << std::endl;
    // std::cout << sp.unique() << std::endl;
    // std::cout << sp->name() << std::endl;
    // ------------------------------------------------------------------------------------------------
    // auto a = new A();
    // auto b = new B();
    // SharedPtr<A> sp1(a);
    // SharedPtr<B> sp2(b);
    // std::cout << "sp1:use_count: " << sp1.use_count() << std::endl;
    // std::cout << "sp2:use_count: " << sp2.use_count() << std::endl;

    // a->m_b = sp2;
    // b->m_a = sp1;

    // std::cout << "sp1:use_count: " << sp1.use_count() << std::endl;
    // std::cout << "sp2:use_count: " << sp2.use_count() << std::endl;

    return 0;
}