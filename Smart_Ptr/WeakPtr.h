#pragma once
#include "SharedPtr.h"

template<class T>
class WeakPtr
{
public:
    WeakPtr(): m_data(nullptr), m_count(nullptr) {};
    WeakPtr(const T *data): m_data(data), m_count(new int(1)) {};
    WeakPtr(const SharedPtr<T> &other) :m_data(other.m_data), m_count(other.m_count) {};
    WeakPtr(const WeakPtr &other)
    {
        if (m_data != &other)
        {
            m_data = other.m_data;
            m_count = other.m_count;
        }
    }

    WeakPtr(SharedPtr<T> &other)
    {
        if (m_data != other.m_data)
        {
            m_data = other.m_data;
            m_count = other.m_count;
        }
    }

    WeakPtr(WeakPtr &&other)
    {
        m_data = other.m_data;
        m_count = other.m_count;
        other.m_data = nullptr;
        other.m_count = nullptr;
    }

    void reset() noexcept
    {
        m_data = nullptr;
        m_count = nullptr;
    }

    void swap(WeakPtr<T> &other) 
    {
        auto data = other.m_data;
        auto count = other.m_count;
        other.m_data = m_data;
        other.m_count = m_count;
        m_data = data;
        m_count = count;
    }

    int use_count() noexcept
    {
        return *m_count;
    }

    bool expired() noexcept
    {
        return m_count == nullptr;
    }


    WeakPtr<T> &operator=(const WeakPtr<T> &other)
    {
        if (this != &other)
        {
            m_data = other.m_data;
            m_count = other.m_count;
        }
        return *this;
    }

    WeakPtr<T> &operator=(WeakPtr<T> &&other)
    {
        if (this != &other)
        {
            m_data = other.m_data;
            m_count = other.m_count;
            other.m_data = nullptr;
            other.m_count = nullptr;
        }
        return *this;
    }

    WeakPtr<T> &operator=(SharedPtr<T> &other)
    {

        m_data = other.m_data;
        m_count = other.m_count;
        return *this;
    }

    SharedPtr<T> lock() const noexcept
    {
       if (expired()) 
       {
            return SharedPtr<T>();
       }
       else 
       {
            SharedPtr<T> sp;
            sp.m_data = m_data;
            sp.m_count = new int (*m_count + 1);
            return sp;
       }
    }

private:
    T *m_data;
    int *m_count;
};