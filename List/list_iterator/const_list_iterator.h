#pragma once

#include <ListNode.h>

namespace hcs
{
    namespace stl
    {
        template <class T>
        class ConstListIterator
        {
        public:
            ConstListIterator() : m_pointer(nullptr) {}
            ConstListIterator(ListNode<T> * pointer) : m_pointer(pointer) {}

            bool operator == (const ConstListIterator<T> &other) const
            {
                return other.m_pointer == m_pointer;
            }

            bool operator != (const ConstListIterator<T> &other) const
            {
                return other.m_pointer != m_pointer;
            }

            ConstListIterator<T> operator ++ ()
            {
                m_pointer = m_pointer->m_next;
                return *this;
            }

            ConstListIterator<T> operator ++ (int)
            {
                auto t = *this;
                m_pointer = m_pointer->m_next;
                return t;
            }

            ConstListIterator<T> operator += (int index)
            {
                auto t = *this;
                for (int i = 0; i < index; ++ i)
                {
                    m_pointer = m_pointer->m_next;
                }
                return t;
            }

            ConstListIterator<T> operator -= (int index)
            {
                auto t = *this;
                for (int i = 0; i < index; ++ i)
                {
                    m_pointer = m_pointer->m_prev;
                }
                return t;
            }

            ConstListIterator<T> operator -- ()
            {
                m_pointer = m_pointer->m_prev;
                return *this;
            }

            ConstListIterator<T> operator -- (int)
            {
                auto t = *this;
                m_pointer = m_pointer->m_prev;
                return t;
            }

            T & operator * ()
            {
                return m_pointer->m_value;
            }

            ~ConstListIterator() {}

        private:
            ListNode<T> * m_pointer;
        };
    }
}