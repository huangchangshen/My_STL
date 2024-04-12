#pragma once

#include <ListNode.h>
#include <list_iterator/list_iterator.h>
#include <list_iterator/const_list_iterator.h>
#include <list_iterator/reverse_list_iterator.h>

namespace hcs
{
    namespace stl
    {
        template<class T>
        class List
        {
        public:
            List();
            ~List();
            void assign(List<T> & other);
            void assign(int n, const T & value);
            T & back();
            T & front();
            int size();
            void push_back(const T & value);
            void pop_back();
            void push_front(const T & value);
            void pop_front();
            void clear();
            bool empty() const;
            void reverse() noexcept;
            void show() const;
            void merge(List<T> & other);

            ListIterator<T> begin();
            ListIterator<T> end();

            ConstListIterator<T> cbegin();
            ConstListIterator<T> cend();

            ReverseListIterator<T> rbegin();
            ReverseListIterator<T> rend();

        private:
            ListNode<T> * m_head;
            ListNode<T> * m_tail;
            int m_size;
        };
#include  "list.inl"
    }
}