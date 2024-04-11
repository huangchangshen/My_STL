#pragma once

namespace hcs
{
    namespace ReverseIterator
    {
        template<class T>
        class Reverse_Iterator
        {
        public:
            Reverse_Iterator() : m_pointer(nullptr) {}
            Reverse_Iterator(T * pointer) : m_pointer(pointer) {}
            ~Reverse_Iterator() {}

            T & operator * ()
            {
                return *m_pointer;
            }

            //前缀++
            T * operator ++ ()
            {
                m_pointer--;
                return m_pointer;
            }

            //后缀++
            T * operator ++ (int)
            {
                T * temp = m_pointer;
                m_pointer --;
                return temp;
            }

            T * operator += (int index)
            {
                T * temp = m_pointer;
                m_pointer -= index;
                return temp;
            }

            //前缀 --
            T * operator -- ()
            {
                m_pointer++;
                return m_pointer;
            }

            //后缀 --
            T * operator -- (int)
            {
                T * temp = m_pointer;
                m_pointer++;
                return m_pointer;
            }

            T * operator -= (int index)
            {
                T * temp = m_pointer;
                m_pointer += index;
                return m_pointer;
            }

            bool operator != (Reverse_Iterator<T> other)
            {
                return m_pointer != other.m_pointer;
            }

            bool operator == (Reverse_Iterator<T> other)
            {
                return m_pointer == other.m_pointer;
            }

        private:
            T * m_pointer;
        };
    }

}