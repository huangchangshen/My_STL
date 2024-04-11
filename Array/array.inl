template<class T, std::size_t N>
Array<T, N>::Array()
{
}

template<class T, std::size_t N>
int Array<T, N>::size() const
{
    return N;
}

template<class T, std::size_t N>
bool Array<T, N>::isempty() const
{
    return N == 0;
}

template<class T, std::size_t N>
void Array<T, N>::fill(const int & value)
{
    for (int i = 0; i < N; ++ i)
    {
        m_data[i] = value;
    }
}

template<class T, std::size_t N>
T * Array<T, N>::data() const
{
    return m_data;
}

template<class T, std::size_t N>
void Array<T, N>::swap(Array<T, N> &other)
{
    if (this == &other)
        return;
    for (int i = 0; i < N; ++i)
    {
        auto temp = other.m_data[i];
        other.m_data[i] = m_data[i];
        m_data[i] = temp;
    }
}

template<class T, std::size_t N>
T & Array<T, N>::operator[](int index)
{
    if (index >= N)
    {
        throw std::logic_error("out of bound!");
    }
    return m_data[index];
}

template<class T, std::size_t N>
const T & Array<T, N>::operator[](int index) const
{
    if (index >= N)
    {
        throw std::logic_error("out of bound!");
    }
    return m_data[index];
}

template<class T, std::size_t N>
T & Array<T, N>::at(int index)
{
    if (index >= N)
    {
        throw std::logic_error("out of bound!");
    }
    return m_data[index];
}

template<class T, std::size_t N>
const T & Array<T, N>::at(int index) const
{
    if (index >= N)
    {
        throw std::logic_error("out of bound!");
    }
    return m_data[index];
}

template<class T, std::size_t N>
T & Array<T, N>::front()
{
    return m_data[0];
}

template<class T, std::size_t N>
const T & Array<T, N>::front() const
{
    return m_data[0];
}

template<class T, std::size_t N>
T & Array<T, N>::back()
{
    return m_data[N - 1];
}

template<class T, std::size_t N>
const T & Array<T, N>::back() const
{
    return m_data[N - 1];
}

template<class T, std::size_t N>
void Array<T, N>::show() const
{
    for (int i = 0; i < N; ++i)
    {
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}

template<class T, std::size_t N>
Iterator<T> Array<T, N>::begin()
{
    return Iterator<T> (m_data);
}

template<class T, std::size_t N>
const Iterator<T> Array<T, N>::begin() const
{
    return Iterator<T> (m_data);
}

template<class T, std::size_t N>
Iterator<T> Array<T, N>::end()
{
    return Iterator<T> (&m_data[N]);
}

template<class T, std::size_t N>
const Iterator<T> Array<T, N>::end() const
{
    return Iterator<T> (&m_data[N]);
}

template<class T, std::size_t N>
Const_Iterator<T> Array<T, N>::cbegin()
{
    return Const_Iterator<T> (m_data);
}

template<class T, std::size_t N>
const Const_Iterator<T> Array<T, N>::cbegin() const
{
    return Const_Iterator<T> (m_data);
}

template<class T, std::size_t N>
Const_Iterator<T> Array<T, N>::cend()
{
    return Const_Iterator<T> (&m_data[N]);
}

template<class T, std::size_t N>
const Const_Iterator<T> Array<T, N>::cend() const
{
    return Const_Iterator<T> (&m_data[N]);
}

template<class T, std::size_t N>
Reverse_Iterator<T> Array<T, N>::rbegin()
{
    return Reverse_Iterator<T> (&m_data[N - 1]);
}

template<class T, std::size_t N>
const Reverse_Iterator<T> Array<T, N>::rbegin() const
{
    return Reverse_Iterator<T> (&m_data[N - 1]);
}

template<class T, std::size_t N>
Reverse_Iterator<T> Array<T, N>::rend()
{
    return Reverse_Iterator<T> ((m_data - 1));
}

template<class T, std::size_t N>
const Reverse_Iterator<T> Array<T, N>::rend() const
{
    return Reverse_Iterator<T> ((m_data - 1));
}

template<class T, std::size_t N>
Array<T, N>::~Array()
{
}

