#pragma once

//#include <list.h>
//class List;
namespace hcs
{
    namespace stl
    {
        template <class T>
        class ListNode
        {
//            friend class List;
        public:
            ListNode() : m_value(0), m_next(nullptr), m_prev(nullptr) {}
            ListNode(const T & value) : m_value(value), m_next(nullptr), m_prev(nullptr) {}
            ~ListNode() {}

        public:
            T m_value;
            ListNode * m_next;
            ListNode * m_prev;
        };
    }
}