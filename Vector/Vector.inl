template<class T>
Vector<T>::Vector(): m_data(nullptr), m_Size(0), m_Capacity(0) 
{

}

template<class T>
Vector<T>::~Vector()
{
    if (m_data != nullptr)
    {
        delete[] m_data;
        m_data = nullptr;
    }
}

template<class T>
// 访问下标为index的值
T & Vector<T>::at(int index)
{
    if (index < 0 || index >= m_Size)
    {
        throw std::out_of_range("index out of range");
    }
    return m_data[index];
}

template<class T>
const T & Vector<T>::at(int index) const
{
    if (index < 0 || index >= m_Size)
    {
        throw std::out_of_range("index out of range");
    }
    return m_data[index];
}


//重载 []
template<class T>
T & Vector<T>::operator [] (int index)
{
    return m_data[index];
}

template<class T>
const T & Vector<T>::operator [] (int index) const
{
    return m_data[index];
}

//取末尾元素
template<class T>
T * Vector<T>::back()
{
    return m_data[m_Size - 1];
}

template<class T>
const T * Vector<T>::back() const
{
    return m_data[m_Size - 1];
}


//取首部元素
template<class T>
T * Vector<T>:: front()
{
    return m_data[0];
}

template<class T>
const T * Vector<T>::front() const
{
    return m_data[0];
}


template<class T>
void Vector<T>::push_back(const T & value)
{   
    if (m_Size == m_Capacity)
    {
        if (m_Capacity == 0)
        {
            m_Capacity = 1;
        }
        else
        {
            m_Capacity *= 2;
        }
        T * data = new T[m_Capacity];
        for (int i = 0; i < m_Size; i++)
        {
            data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = data;
    }
    m_data[m_Size++] = value;
    
}

template<class T>
void Vector<T>::pop_back()
{
    if (m_Size > 0)
    {
        m_Size--;
    }
}

template<class T>
bool Vector<T>::empty() const
{
    return m_Size == 0;
}

template<class T>
int Vector<T>::size() const
{
    return m_Size;
}

template<class T>
int Vector<T>::capacity() const
{
    return m_Capacity;
}

template<class T>
void Vector<T>::clear() const
{
    m_Size = 0;
}

template<class T>
void Vector<T>::assign(int n, const T & value)
{
    if (m_Capacity > n)
    {
        for (int i = 0; i < n; ++ i)
        {
            m_data[i] = value;
        }
        m_Size = n;
        return;
    }

    while (n > m_Capacity)
    {
        if (m_Capacity == 0)
        {
            m_Capacity = 1;
        }
        else 
        {
            m_Capacity *= 2;
        }
    }
    T * data = new T[m_Capacity];
    for (int i = 0; i < m_Size; i++)
    {
        data[i] = value;
    }

    if (m_data != nullptr)
    {
        delete [] m_data;
        m_data = nullptr;
    }
    m_data = data;
}   

template <class T>
void Vector<T>::resize(int n)
{
    resize(n, T());
}

template <class T>
void Vector<T>::resize(int n, const T & value)
{
    if (m_Size >= n || n <= m_Capacity)
    {
        for (int i = m_Size; i < n; ++ i)
        {
            m_data[i] = value;
        }
        m_Size = n;
        return;
    }

    while(n <= m_Capacity)
    {
        if (m_Capacity == 0)
        {
            m_Capacity = 1;
        }
        else 
        {
            m_Capacity *= 2;
        }
    }

    T * data = new T[m_Capacity];
    for (int i = 0; i < m_Size; ++ i)
    {
        data[i] = m_data[i];
    }

    for (int i = m_Size; i < n; ++ i)
    {
        data[i] = value;
    }

    if (m_data != nullptr)
    {
        delete[] m_data;
        m_data = nullptr;
    }
    m_data = data;
    m_Size = n;
}


template <class T>
void Vector<T>::reserve(int n)
{
    if (n <= m_Capacity)
    {
        return;
    }

    while (n > m_Capacity)
    {
        if (m_Capacity == 0)
        {
            m_Capacity = 1;
        }
        else
        {
            m_Capacity *= 2;
        }
    }

    T * data = new T[m_Capacity];
    for (int i = 0; i < m_Size; i++)
    {
        data[i] = m_data[i];
    }
    
    if (m_data != nullptr)
    {
        delete [] m_data;
        m_data = nullptr;
    }
    m_data = data;

}

template <class T>
void Vector<T>::swap(Vector<T> & other)
{
    T * data = other.m_data;
    int size = other.m_Size;
    int capacity = other.m_Capacity;

    other.m_data = m_data;
    other.m_Size = m_Size;
    other.m_Capacity = m_Capacity;

    m_data = data;
    m_Size = size;
    m_Capacity = capacity;
}

template<class T>
void Vector<T>::show() const
{
    std::cout << "size: " << m_Size << " capacity: " << m_Capacity << std::endl;
    for (int i = 0; i < m_Size; ++ i)
    {
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}