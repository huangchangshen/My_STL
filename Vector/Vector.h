#pragma once 

#include <iostream>
#include <stdexcept>

namespace Vector_stl
{
    template <class T>
    class Vector
    {
    public:
        Vector();
        ~Vector();

        // 访问下标为index的值
        T & at(int index);
        const T & at(int index) const;

        //重载 []
        T & operator [] (int index);
        const T & operator [] (int index) const;


        //取末尾元素
        T * back();
        const T * back() const;

        //取首部元素
        T * front();
        const T * front() const;

        void push_back(const T & value);
        void pop_back();

        bool empty() const;     //是否为空
        int size() const;       //大小
        int capacity() const;   //容量
        void clear() const;     //清空

        void assign(int n, const T & value);    //初始化
        void resize(int n);
        void resize(int n, const T & value);    //重设大小
        void reserve(int n);    //预留空间

        void swap(Vector<T> & other);
        void show() const;

    private:
        T* m_data;
        int m_Size;
        int m_Capacity;

    };
    #include "Vector.inl"
};
