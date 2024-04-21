template <class T>
Forward_list<T>::Forward_list() : m_size(0)
{
    m_head = new ListNode<T>();
    m_end = new ListNode<T>();
}

template<class T>
Forward_list<T>::Forward_list(Forward_list<T> &other)
{
    auto temp = new ListNode<T>();
    m_head = temp;
    auto t = other.m_head->m_next;
    while (t)
    {
        temp->m_next = new ListNode<T>();
        temp = temp->m_next;
        temp->m_value = t->m_value;
        t = t->m_next;
    }
}

template <class T>
bool Forward_list<T>::empty() noexcept
{
    return m_size == 0;
}

template <class T>
int Forward_list<T>::size() noexcept
{
    return m_size;
}


template <class T>
void Forward_list<T>::insert_after(ConstIterator<T> pos, const T & value)
{
    ListNode<T> * temp = new ListNode<T>(value);
    temp->m_next = (*pos).m_next;
    (*pos).m_next = temp;
    if (pos == m_end)
    {
        m_end = temp;
    }
}

template <class T>
void Forward_list<T>::remove_after(ConstIterator<T> pos)
{
    auto temp = (*pos).m_next;
    (*pos).m_next = temp->m_next;
    delete temp;
    temp = nullptr;
}

template <class T>
void Forward_list<T>::push_front(const T & value) noexcept
{
    ListNode<T> * temp = new ListNode<T>(value);
    temp->m_next = m_head->m_next;
    m_head->m_next = temp;
    m_size++;

    if (m_size == 1)
    {
        m_end = temp;
    }
}

template <class T>
void Forward_list<T>::merge(Forward_list<T> &other)
{
    auto temp = other.m_head->m_next;
    while (temp)
    {
        m_end->m_next = new ListNode<T>(temp->m_value);
        m_end = m_end->m_next;
        temp = temp->m_next;
    }
    m_size += other.m_size;
}

template <class T>
void Forward_list<T>::assign(int n, const T & value)
{
    for (int i = 0; i < n; ++ i)
    {
        push_front(value);
    }
    m_size += n;
}

template <class T>
void Forward_list<T>::clear()
{
    while (m_head != nullptr)
    {
        auto temp = m_head;
        m_head = m_head->m_next;
        if (temp != nullptr)
        {
            delete temp;
            temp = nullptr;
        }
    }
}

template<class T>
void Forward_list<T>::pop_front() noexcept
{
    auto temp = m_head->m_next;
    m_head->m_next = temp->m_next;
    delete temp;
    temp = nullptr;
    m_size--;
}

template <class T>
void Forward_list<T>::remove(const T & value) noexcept
{
    auto temp = m_head->m_next;
    auto pre = m_head;
    while (temp)
    {
        if (temp->m_value == value)
        {
            auto t = temp;
            temp = temp->m_next;
            pre->m_next = temp;
            delete t;
            t = nullptr;
            continue;
        }

        pre = pre->m_next;
        temp = temp->m_next;
    }
}

template <class T>
void Forward_list<T>::resize(int size) noexcept
{
    resize(size, 0);
}

template <class T>
void Forward_list<T>::resize(int size, const T & value) noexcept
{
    if (m_size == size)
    {
        return;
    }

    if (m_size > size)
    {
        int cnt = m_size - size;
        while (cnt --)
        {
            ListNode<T> * temp = new ListNode<T>(value);
            m_end->m_next = temp;
            m_end = temp;
        }
    }

    if (m_size < size)
    {
        ListNode<T> * temp = m_head;
        for (int i = 0; i < size; ++i)
        {
            temp = temp->m_next;
        }

        m_end = temp;
        temp = temp->m_next;

        while (temp != nullptr)
        {
            auto t = temp;
            temp = temp->m_next;
            delete t;
            t = nullptr;
        }
    }

    m_size = size;
}

template <class T>
void Forward_list<T>::reverse() noexcept
{
    if (m_size <= 1)
    {
        return;
    }

    m_end = m_head->m_next;
    ListNode<T> *pre = m_head, *cur = m_head->m_next, *suf = cur->m_next;
    while (cur != nullptr)
    {
        cur->m_next = pre;
        pre = cur;
        cur = suf;
        if (suf) suf = suf->m_next;
    }

    m_head->m_next = pre;
}

// son of sort
template <class T>
ListNode<T> * Forward_list<T>::findMid(ListNode<T> * head)
{
    if (head == nullptr || head->m_next == nullptr)
    {
        return head;
    }

    ListNode<T> * slow = head, *fast = head;

    while (fast->m_next && fast->m_next->m_next)
    {
        slow = slow->m_next;
        fast = fast->m_next->m_next;
    }

    return slow;
}

// son of sort
template <class T>
ListNode<T> * Forward_list<T>::merge(ListNode<T> * left, ListNode<T> * right)
{
    ListNode<T> *head = new ListNode<T>();
    ListNode<T> *cur = head;
    while (left && right)
    {
        if (left->m_value < right->m_value)
        {
            cur->m_next = left;
            left = left->m_next;
        }
        else
        {
            cur->m_next = right;
            right = right->m_next;
        }
        cur = cur->m_next;
    }
    if (left) cur->m_next = left;
    if (right) cur->m_next = right;
    return head->m_next;
}

//son of sort
template <class T>
ListNode<T> * Forward_list<T>::sortList(ListNode<T> * head)
{
    if (head == nullptr || head->m_next == nullptr)
    {
        return head;
    }

    ListNode<T> * mid = findMid(head);
    ListNode<T> * next_list = mid->m_next;
    mid->m_next = nullptr;

    ListNode<T> * left = sortList(head);
    ListNode<T> * right = sortList(next_list);
    return merge(left, right);
}

template <class T>
void Forward_list<T>::sort() noexcept
{
    m_head->m_next = sortList(m_head->m_next);
}

template <class T>
void Forward_list<T>::swap(Forward_list<T> & other)
{
    auto temp = m_head;
    m_head = other.m_head;
    other.m_head = temp;

    temp = m_end;
    m_end = other.m_end;
    other.m_end = temp;

}

template <class T>
void Forward_list<T>::unique()
{
    if (m_size <= 1)
    {
        return;
    }

    ListNode<T> * pre = m_head->m_next, * cur = pre->m_next;
    while (cur != nullptr)
    {
        if (pre->m_value == cur->m_value)
        {
            auto t = cur;
            cur = cur->m_next;
            pre->m_next = cur;
            delete t;
            t = nullptr;
        }
        else
        {
            pre = pre->m_next;
            cur = cur->m_next;
        }
    }
}

template <class T>
void Forward_list<T>::show() const
{
    auto t = m_head->m_next;
    while (t != nullptr)
    {
        std::cout << t->m_value << " ";
        t = t->m_next;
    }
    std::cout << std::endl;
}

template <class T>
const Iterator<T> & Forward_list<T>::begin() const
{
    auto temp = new Iterator<T>(m_head->m_next);
    return *temp;
}

template <class T>
const Iterator<T> & Forward_list<T>::end() const
{
    auto temp = new Iterator<T>(m_end->m_next);
    return *temp;
}

template <class T>
const ConstIterator<T> Forward_list<T>::cbegin() const
{
    auto temp = new ConstIterator<T>(m_head->m_next);
    return *temp;
}

template <class T>
const ConstIterator<T> Forward_list<T>::cend() const
{
    auto temp = new ConstIterator<T>(m_end->m_next);
    return *temp;
}

template <class T>
Forward_list<T>:: ~Forward_list()
{
    while (m_head != nullptr)
    {
        auto temp = m_head;
        m_head = m_head->m_next;
        if (temp != nullptr)
        {
            delete temp;
            temp = nullptr;
        }
    }
}