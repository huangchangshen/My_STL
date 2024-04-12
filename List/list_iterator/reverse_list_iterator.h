#pragma once

#include <ListNode.h>

namespace hcs
{
    namespace stl
    {
        template <class T>
        class ReverseListIterator
        {
        public:
            ReverseListIterator() : m_pointer(nullptr) {}
            ReverseListIterator(ListNode<T> * pointer) : m_pointer(pointer) {}

            bool operator == (const ReverseListIterator<T> &other) const
            {
                return other.m_pointer == m_pointer;
            }

            bool operator != (const ReverseListIterator<T> &other) const
            {
                return other.m_pointer != m_pointer;
            }

            ReverseListIterator<T> operator ++ ()
            {
                m_pointer = m_pointer->m_prev;
                return *this;
            }

            ReverseListIterator<T> operator ++ (int)
            {
                auto t = *this;
                m_pointer = m_pointer->m_prev;
                return t;
            }

            ReverseListIterator<T> operator += (int index)
            {
                auto t = *this;
                for (int i = 0; i < index; ++i)
                {
                    m_pointer = m_pointer->m_prev;
                }
                return t;
            }

            ReverseListIterator<T> operator -= (int index)
            {
                auto t = *this;
                for (int i = 0; i < index; ++i)
                {
                    m_pointer = m_pointer->m_next;
                }
                return t;
            }

            ReverseListIterator<T> operator -- ()
            {
                m_pointer = m_pointer->m_next;
                return *this;
            }

            ReverseListIterator<T> operator -- (int)
            {
                auto t = *this;
                m_pointer = m_pointer->m_next;
                return t;
            }

            T & operator * ()
            {
                return m_pointer->m_value;
            }

            ~ReverseListIterator() {}

        private:
            ListNode<T> * m_pointer;
        };
    }
}