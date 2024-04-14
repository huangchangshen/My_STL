#pragma once
#include <stdexcept>
#include <Iterator/iterator.h>
#include <Iterator/ConstIterator.h>
#include <Iterator/ReverseIterator.h>

namespace hcs
{
    namespace stl
    {
        template<class T, std::size_t N>
        class Array
        {
        public:
            Array();
            int size() const;
            bool isempty() const;
            void fill(const int & value);
            T * data() const;

            void swap(Array<T, N> &other);

            T & operator[](int index);
            const T & operator[](int index) const;

            T & at(int index);
            const T & at(int index) const;

            T & front();
            const T & front() const;

            T & back();
            const T & back() const;

            void show() const;

            ~Array();

            Iterator<T> begin();
            const Iterator<T> begin() const;

            Iterator<T> end();
            const Iterator<T> end() const;

            Const_Iterator<T> cbegin();
            const Const_Iterator<T> cbegin() const;

            Const_Iterator<T> cend();
            const Const_Iterator<T> cend() const;

            Reverse_Iterator<T> rbegin();
            const Reverse_Iterator<T> rbegin() const;

            Reverse_Iterator<T> rend();
            const Reverse_Iterator<T> rend() const;

        private:

            T m_data[N];
        };
#include <array.inl>
    }
}