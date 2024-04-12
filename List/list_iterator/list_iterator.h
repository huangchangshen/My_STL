#pragma once

#include <ListNode.h>

namespace hcs
{
    namespace stl
    {
        template <class T>
        class ListIterator
        {
        public:
            ListIterator() : m_pointer(nullptr) {}
            ListIterator(ListNode<T> * pointer) : m_pointer(pointer) {}

            bool operator == (const ListIterator<T> &other) const
            {
                return other.m_pointer == m_pointer;
            }

            bool operator != (const ListIterator<T> &other) const
            {
                return other.m_pointer != m_pointer;
            }

            ListIterator<T> operator ++ ()
            {
                m_pointer = m_pointer->m_next;
                return *this;
            }

            ListIterator<T> operator ++ (int)
            {
                auto t = *this;
                m_pointer = m_pointer->m_next;
                return t;
            }

            ListIterator<T> operator += (int index)
            {
                auto t = *this;
                for (int i = 0; i < index; ++ i)
                {
                    m_pointer = m_pointer->m_next;
                }
                return t;
            }

            ListIterator<T> operator -= (int index)
            {
                auto t = *this;
                for (int i = 0; i < index; ++ i)
                {
                    m_pointer = m_pointer->m_prev;
                }
                return t;
            }

            ListIterator<T> operator -- ()
            {
                m_pointer = m_pointer->m_prev;
                return *this;
            }

            ListIterator<T> operator -- (int)
            {
                auto t = *this;
                m_pointer = m_pointer->m_prev;
                return t;
            }

            T & operator * ()
            {
                return m_pointer->m_value;
            }

            ~ListIterator() {}

        private:
            ListNode<T> * m_pointer;
        };
    }
}