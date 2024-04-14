#pragma once

namespace hcs
{
    namespace stl
    {
        template<class T>
        class Const_Iterator
        {
        public:
            Const_Iterator() : m_pointer(nullptr) {}
            Const_Iterator(T * pointer) : m_pointer(pointer) {}
            ~Const_Iterator() {}

            T & operator * () const
            {
                return *m_pointer;
            }

            //前缀++
            const T * operator ++ ()
            {
                m_pointer++;
                return m_pointer;
            }

            //后缀++
            const T * operator ++ (int)
            {
                T * temp = m_pointer;
                m_pointer ++;
                return temp;
            }

            const T * operator += (int index)
            {
                T * temp = m_pointer;
                m_pointer += index;
                return temp;
            }

            //前缀 --
            const T * operator -- ()
            {
                m_pointer--;
                return m_pointer;
            }

            //后缀 --
            const T * operator -- (int)
            {
                T * temp = m_pointer;
                m_pointer--;
                return m_pointer;
            }

            const T * operator -= (int index)
            {
                T * temp = m_pointer;
                m_pointer -= index;
                return m_pointer;
            }

            bool operator != (Const_Iterator<T> other)
            {
                return m_pointer != other.m_pointer;
            }

            bool operator == (Const_Iterator<T> other)
            {
                return m_pointer == other.m_pointer;
            }

        private:
            T * m_pointer;
        };
    }

}