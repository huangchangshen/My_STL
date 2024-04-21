#pragma once

namespace hcs
{
    namespace stl
    {
        template <class T>
        class ListNode
        {
        public:
            ListNode() : m_value(0), m_next(nullptr) {}
            ListNode(int value) : m_value(value), m_next(nullptr) {}
            ListNode(ListNode<T> & other)
            {
                ListNode<T> * temp = new ListNode<T>();
                temp->m_next = other.m_next;
                temp->m_value = other.m_value;
                this = temp;
            }
            ~ListNode() {}

        public:
            ListNode<T> * m_next;
            T m_value;
        };
    }
}