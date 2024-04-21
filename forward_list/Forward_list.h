#pragma once

#include <ListNode.h>
#include <forward_list_iterator/iterator.h>
#include <forward_list_iterator/const_iterator.h>

namespace hcs
{
    namespace stl
    {
        template <class T>
        class Forward_list
        {
        public:
            Forward_list();
            Forward_list(Forward_list<T> &other);
            ~Forward_list();

            void merge(Forward_list<T> &other);
            void assign(int n, const T & value);
            void clear();
            bool empty() noexcept;
            int size() noexcept;

            void insert_after(ConstIterator<T> pos, const T & value);
            void remove_after(ConstIterator<T> pos);

            void push_front(const T & value) noexcept;
            void pop_front() noexcept;

            void remove(const T & value) noexcept;
            void resize(int size) noexcept;
            void resize(int size, const T & value) noexcept;

            void reverse() noexcept;
            void sort() noexcept;
            void swap(Forward_list<T> & other);
            void unique();

            void show() const;

            const Iterator<T> & begin() const;
            const Iterator<T> & end() const;

            const ConstIterator<T> cbegin() const;
            const ConstIterator<T> cend() const;

        private:
            ListNode<T> * merge(ListNode<T> * left, ListNode<T> * right);
            ListNode<T> * findMid(ListNode<T> * head);
            ListNode<T> * sortList(ListNode<T> * head);

        private:
            ListNode<T> * m_head;
            ListNode<T> * m_end;
            int m_size;
        };

#include "Forward_list.inl"
    }
}