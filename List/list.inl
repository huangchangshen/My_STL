template<class T>
List<T>::List() : m_size(0)
{
    m_tail = new ListNode<T>(0);
    m_head = new ListNode<T>(0);
    m_tail->m_prev = m_head;
    m_head->m_next = m_tail;
}

template<class T>
void List<T>::assign(List<T> & other)
{
    clear();
    merge(other);
}

template <class T>
void List<T>::merge(List<T> & other)
{
    auto temp = other.m_head->m_next;
    while (temp != other.m_tail)
    {
        push_back(temp->m_value);
    }
}

template<class T>
void List<T>::assign(int n, const T & value)
{
    for (int i = 0; i < n; ++i)
    {
        push_back(value);
    }
}

template<class T>
T & List<T>::back()
{
    return m_tail->m_prev->m_value;
}

template<class T>
T & List<T>::front()
{
    return m_head->m_next->m_value;
}

template<class T>
int List<T>::size()
{
    return m_size;
}
template <class T>
void List<T>::push_back(const T & value)
{
    ListNode<T> *cur = new ListNode<T>(value);

    cur->m_next = m_tail;
    cur->m_prev = m_tail->m_prev;
    m_tail->m_prev->m_next = cur;
    m_tail->m_prev = cur;

    m_size++;
}

template <class T>
void List<T>::pop_back()
{
    ListNode<T> * temp = m_tail->m_prev;

    temp->m_prev->m_next = m_tail;
    m_tail->m_prev = temp->m_prev;

    if (temp != nullptr)
    {
        delete temp;
        temp = nullptr;
    }
    m_size--;
}

template <class T>
void List<T>::push_front(const T & value)
{
    ListNode<T> * cur = new ListNode<T>(value);

    cur->m_next = m_head->m_next;
    m_head->m_next->m_prev = cur;
    cur->m_prev = m_head;
    m_head->m_next = cur;

    m_size++;
}

template<class T>
void List<T>::pop_front()
{
    ListNode<T> * temp = m_head->m_next;

    m_head->m_next = temp->m_next;
    temp->m_next->m_prev = m_head;

    if (temp != nullptr)
    {
        delete temp;
        temp = nullptr;
    }
    m_size--;
}

template <class T>
void List<T>::clear()
{
    while (m_head->m_next != m_tail)
    {
        pop_back();
    }
    m_size = 0;
}

template <class T>
bool List<T>::empty() const
{
    return m_size == 0;
}

template <class T>
void List<T>::reverse() noexcept
{
    if (m_head->m_next == m_tail)
    {
        return;
    }

    ListNode<T> *pre = m_head, *cur = m_head->m_next, *suf = m_head->m_next->m_next, *first = m_head->m_next;

    while (suf)
    {
        cur->m_next = pre;
        cur->m_prev = suf;

        pre = cur; cur = suf;
        suf = suf->m_next;
    }

    ListNode<T> * temp = m_tail;
    m_tail = m_head;
    m_head = temp;

    m_head->m_next = pre;
    m_head->m_prev = nullptr;
    m_tail->m_prev = first;
    m_tail->m_next = nullptr;
}

template<class T>
void List<T>::show() const
{
    ListNode<T> * temp = m_head->m_next;
    while (temp != m_tail)
    {
        std::cout << temp->m_value << " ";
        temp = temp->m_next;
    }
    std::cout << std::endl;
}

template <class T>
ListIterator<T> List<T>::begin()
{
    return ListIterator<T>(m_head->m_next);
}

template <class T>
ListIterator<T> List<T>::end()
{
    return ListIterator<T>(m_tail);
}

template<class T>
ConstListIterator<T> List<T>::cbegin()
{
    return ConstListIterator<T>(m_head->m_next);
}

template<class T>
ConstListIterator<T> List<T>::cend()
{
    return ConstListIterator<T>(m_tail);
}

template<class T>
ReverseListIterator<T> List<T>::rbegin()
{
    return ReverseListIterator<T>(m_tail->m_prev);
}

template<class T>
ReverseListIterator<T> List<T>::rend()
{
    return ReverseListIterator<T>(m_head);
}

template<class T>
List<T>::~List()
{
    clear();
    if (m_tail != nullptr)
    {
        delete m_tail;
        m_tail = nullptr;
    }

    if (m_head != nullptr)
    {
        delete m_head;
        m_head = nullptr;
    }
}