#pragma once

#include <ListNode.h>

namespace hcs
{
    namespace stl
    {
        template <class T>
        class ConstIterator
        {
        public:
            ConstIterator() : m_pointer(nullptr) {}
            ConstIterator(ListNode<T> * pointer) : m_pointer(pointer) {}
            ~ConstIterator() {}

            ListNode<T> & operator * ()
            {
                return *m_pointer;
            }

            //前置 ++
            ConstIterator<T> & operator ++ ()
            {
                m_pointer = m_pointer->m_next;
                return *this;
            }

            //后置 ++
            ConstIterator<T> & operator ++ (int)
            {
                auto temp = *this;
                m_pointer = m_pointer->m_next;
                return temp;
            }

            ConstIterator<T> & operator += (int index)
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

            bool operator == (const ConstIterator<T> & other) const
            {
                return other.m_pointer == m_pointer;
            }

            bool operator != (const ConstIterator<T> & other) const
            {
                return other.m_pointer != m_pointer;
            }

        private:
            ListNode<T> * m_pointer;
        };
    }
}