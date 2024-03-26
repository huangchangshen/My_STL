#pragma once

template <class T>
class SharedPtr 
{
    template<class Y> friend class WeakPtr;
public:
    SharedPtr(): m_data(nullptr), m_count(nullptr) {};
    SharedPtr(T *data) : m_data(data), m_count(new int(1)) {};
    SharedPtr(const SharedPtr &other) noexcept
    {
        m_data = other.m_data;
        m_count = other.m_count;
        (*m_count)++;
    }

    SharedPtr(const SharedPtr &&other) noexcept
    {
        m_data = other.m_data;
        m_count = other.m_count;
        m_data = nullptr;
        m_count = nullptr;
    }

    SharedPtr &operator = (const SharedPtr &other) noexcept
    {
        m_data = other.m_data;
        m_count = other.m_count;
        (*m_count)++;
        return *this;
    }

    SharedPtr &operator = (const SharedPtr &&other) noexcept
    {
        if (m_data != &other)
        {
            m_data = other.m_data;
            m_count = other.m_count;
            other.m_data = nullptr;
            other.m_count = nullptr;
        }
    }

    void swap(SharedPtr<T> &other)
    {
        auto data = other.m_data;
        auto count = other.m_count;
        other.m_data = m_data;
        other.m_count = m_count;
        m_data = data;
        m_count = count;
    }

    T * operator ->()
    {
        return m_data;
    }

    T & operator *()
    {
        return *m_data;
    }

    T * get()
    {
        return m_data;
    }

    T * operator [] (int i) const
    {
        return m_data[i];
    }

    int use_count()
    {
        if (m_count == nullptr)
        {
            return 0;
        }
        return *m_count;
    }

    bool unique()
    {
        if (m_count == nullptr)
        {
            return false;
        }
        return *m_count == 1;
    }

    explicit operator bool () const 
    {
        return m_data != nullptr;
    }

    void reset(const T* &other)
    {
        if (m_data != &other)
        {
            m_data = other.m_data;
            m_count = other.m_count;
            m_data = nullptr;
            m_count = nullptr;
        }
    }

    T* release()
    {
        auto temp = m_data;
        m_data = nullptr;
        m_count = nullptr;
        return temp;
    }


    ~SharedPtr()
    {
        if (m_data != nullptr)
        {
            (*m_count) --;
            // std::cout << (*m_count) << std::endl;
            if (*m_count <= 0)
            {
                delete m_data;
                m_data = nullptr;
                delete m_count;
                m_count = nullptr;
            }
        }
    }

private:
    T * m_data;
    int *m_count;
};