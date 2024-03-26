#pragma once

template <class T>
class AutoPtr
{
public:
    AutoPtr () :m_data(nullptr) {};
    AutoPtr (T * data): m_data(data) {};
    AutoPtr (AutoPtr<T> & other) :m_data(other.release()) {};
    
    T* operator -> ()
    {
        return m_data;
    } 

    T& operator * (T *m_data)
    {
        return *m_data;
    }

    T* operator = (T* m_data)
    {
        return m_data;
    }

    T * get() const 
    {
        return m_data;
    }

    AutoPtr& operator = (AutoPtr & other)
    {
        reset(other.release());
        return *this;
    }

    void reset(T * p = nullptr)
    {
        if (m_data != p)
        {
            delete m_data;
            m_data = p;
        }
    }

    T* release()
    {
        T * p = m_data;
        m_data = nullptr;
        return p;
    }

    ~AutoPtr ()
    {
        if (m_data != nullptr)
        {
            delete m_data;
            m_data = nullptr;
        }
    }

private:
    T * m_data;
};