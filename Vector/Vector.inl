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

template<class T>
typename Vector<T>::Iterator Vector<T>::begin()
{
    return VectorIterator<T>((T *)m_data);
}

template<class T>
typename Vector<T>::Iterator Vector<T>::end()
{
    return VectorIterator<T>((T *)(m_data + m_Size));
}

template<class T>
typename Vector<T>::Const_Iterator  Vector<T>::cbegin() const
{
    return ConstVectorIterator<T>((T *)m_data);
}

template<class T>
typename Vector<T>::Const_Iterator Vector<T>::cend() const
{
    return ConstVectorIterator<T>((T *)(m_data + m_Size));
}

template<class T>
typename Vector<T>::Reverse_Iterator Vector<T>::rbegin()
{
    return ReverseVectorIterator<T>((T *)m_data + m_Size - 1);
}

template<class T>
typename Vector<T>::Reverse_Iterator Vector<T>::rend()
{
    return ReverseVectorIterator<T>((T *)m_data - 1);
}

template <class T>
typename Vector<T>::Iterator Vector<T>::insert(Iterator pos, int value)
{
    insert(pos, 1, value);
}


template <class T>
typename Vector<T>::Iterator Vector<T>::insert(Iterator pos, int n, const T & value)
{
    Iterator temp = begin();
    int index = pos - temp;
    if (m_Size + n <= m_Capacity)
    {
        for (int i = index; i < m_Size; ++ i)
        {
            m_data[i + n] = m_data[i];
        }

        for (int i = index; i <= index + n; ++ i)
        {
            m_data[i] = value;
        }
        m_Size += n;
        return pos;
    }
    
    while (m_Size + n > m_Capacity)
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

    if (m_data != nullptr)
    {
        delete [] m_data;
        m_data = nullptr;
    }
    m_data = data;
    
    // std::cout << "insert" << std::endl;
    // std::cout << "index: " << index << " n: " << n << std::endl;
    for (int i = m_Size - 1; i >= index; -- i)
    {
        m_data[i + n] = m_data[i];
    }

    for (int i = index; i < index + n; ++ i)
    {
        m_data[i] = value;
    }
    m_Size += n;
    return pos;
}

template <class T>
typename Vector<T>::Iterator Vector<T>::erase(Iterator first, Iterator last)
{
    int n = last - first;
    Iterator beg = begin();
    int left = first - beg;
    int right = last - beg;
    for (int i = left; i < m_Size; ++ i)
    {
        m_data[i] = m_data[i + n];
    }
    m_Size -= n;
    return first;
}

template <class T>
typename Vector<T>::Iterator Vector<T>::erase(Iterator pos)
{
    Iterator en = end();
    Iterator beg = begin();
    if (pos == en)
    {
        throw std::out_of_range("pos out of range");
    }
    int index = pos - beg;
    for (int i = index; i < m_Size - 1; ++ i)
    {
        m_data[i] = m_data[i + 1];
    }
    m_Size--;
    return pos;
}