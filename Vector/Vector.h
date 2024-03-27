#pragma once 

#include <iostream>
#include <stdexcept>
#include "VectorIterator.h"
#include "ConstVectorIterator.h"
#include "ReverseVectorItertor.h"

namespace Vector_stl
{
    
    template <class T>
    class Vector
    {
        typedef VectorIterator<T> Iterator;
        typedef ConstVectorIterator<T> Const_Iterator;
        typedef ReverseVectorIterator<T> Reverse_Iterator;
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

        Iterator insert(Iterator pos, int n, const T & value);
        Iterator insert(Iterator pos, int value);

        Iterator erase(Iterator first, Iterator last);
        Iterator erase(Iterator pos);

        Iterator begin();
        Iterator end();

        Const_Iterator cbegin() const;
        Const_Iterator cend() const;

        Reverse_Iterator rbegin();
        Reverse_Iterator rend();


    private:
        T* m_data;
        int m_Size;
        int m_Capacity;
    };
    #include "Vector.inl"
};
