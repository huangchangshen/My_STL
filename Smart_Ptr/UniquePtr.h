#pragma once

template <class T>
class UniquePtr
{
public:
    UniquePtr() : m_data(nullptr) {};
    UniquePtr(T* data) : m_data(data) {};;
    UniquePtr(const UniquePtr<T> &) = delete;
    
    UniquePtr(UniquePtr<T> && other): m_data(other.release()) {};

    T * get ()
    {
        return m_data;
    }

    T * release()
    {
        T* p = m_data;
        m_data = nullptr;
        return p;
    }

    T * reset(T *p = nullptr)
    {
        if (m_data != p) delete m_data;
        return m_data = p;
    }

    T * operator -> () const
    {
        return m_data;
    }

    T & operator * () const
    {
        return *m_data;
    }

    void swap(UniquePtr &other)
    {
        auto t = m_data;
        m_data = other;
        other = t;
    }

    T & operator [] (int i) const 
    {   
        return m_data[i];
    }

    UniquePtr & operator = (const UniquePtr<T> &) = delete;
    UniquePtr & operator = (UniquePtr<T> && other)
    {
        if (this == &other) return *this;
        reset(other.release());
        return *this;
    }

    ~UniquePtr()
    {
        if (m_data != nullptr)
        {
            delete m_data;
            m_data = nullptr;
        }

    }

private:
    T *m_data;
};