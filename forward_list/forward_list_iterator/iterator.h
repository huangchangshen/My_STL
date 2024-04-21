#pragma once

#include <ListNode.h>

namespace hcs
{
    namespace stl
    {
        template <class T>
        class Iterator
        {
        public:
            Iterator() : m_pointer(nullptr) {}
            Iterator(ListNode<T> * pointer) : m_pointer(pointer) {}
            ~Iterator() {}

            ListNode<T> & operator * ()
            {
                return *m_pointer;
            }

            //前置 ++
            Iterator & operator ++ ()
            {
                m_pointer = m_pointer->m_next;
                return *this;
            }

            //后置 ++
            Iterator & operator ++ (int)
            {
                auto temp = *this;
                m_pointer = m_pointer->m_next;
                return temp;
            }

            Iterator & operator += (int index)
            {
                auto temp = *this;
                for (int i = 0; i < index; ++ i)
                {
                    if (m_pointer)
                    {
                        m_pointer = m_pointer->m_next;
                    }
                    else
                    {
                        throw std::logic_error("nullptr error!");
                    }
                }
                return temp;
            }

            bool operator == (const Iterator<T> & other) const
            {
                return other.m_pointer == m_pointer;
            }

            bool operator != (const Iterator<T> & other) const
            {
                return other.m_pointer != m_pointer;
            }

        private:
            ListNode<T> * m_pointer;
        };
    }
}