#pragma once

namespace Vector_stl
{
    template<class T>
    class ReverseVectorIterator
    {
        typedef ReverseVectorIterator<T> Iterator;
    public:
        ReverseVectorIterator(): m_pointer(nullptr) {};
        ReverseVectorIterator(T * pointer) :m_pointer(pointer) {};
        ~ReverseVectorIterator() {};

        T & operator *() const
        {
            return *m_pointer;
        }

        T * operator ->() const
        {
            return m_pointer;
        }
        
        bool operator == (Iterator &other) const
        {
            return m_pointer == other.m_pointer;
        }
        
        bool operator != (const Iterator &other) const
        {
            return m_pointer != other.m_pointer;
        }

        Iterator & operator = (Iterator &other) const
        {
            if (this == &other)
                return *this;
            m_pointer = other.m_pointer;
            return *this;
        }

        //前缀 ++
        Iterator * operator ++ ()
        {
            m_pointer--;
            return this;
        }

        //后缀 ++
        Iterator operator ++ (int)
        {
            Iterator temp = *this;
            m_pointer--;
            return temp;
        }  

        //前缀 --
        Iterator & operator -- ()
        {
            m_pointer++;
            return this;
        } 

        //后缀 --
        Iterator & operator -- (int)
        {
            Iterator temp = *this;
            m_pointer++;
            return temp;
        }

        Iterator & operator += (int n)
        {
            m_pointer -= n;
            return *this;
        };

        Iterator & operator -= (int n)
        {
            m_pointer += n;
            return *this;
        }

        T * operator + (int n)
        {
            T * temp = m_pointer - n;
            return temp;
        }

        T * operator - (int n)
        {
            T * temp = m_pointer + n;
            return temp;
        }

    private:
        T * m_pointer;
    };
}