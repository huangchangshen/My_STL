#pragma once

template<class T> 
class SmartPtr
{
public:
    SmartPtr() = default;
    SmartPtr(T * data): m_data(data){};
    ~SmartPtr()
    {
        if (m_data != NULL)
        {
            delete m_data;
            m_data = NULL;
        }
    }

    T* operator -> ()
    {
        return m_data;
    }

    T& operator * (T * data)
    {
        return *m_data;
    }

private:
    T * m_data;
};
