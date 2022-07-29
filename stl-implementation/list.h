#ifndef LIST_H
#define LIST_H

template<typename T>
class list
{

private:
    struct Node
    {
        value_type  m_data;
        Node*       m_prev;
        Node*       m_next;

        Node(const T& __data = T{}, Node* __prev = nullptr, Node* __next = nullptr) : m_data{__data}, m_prev{__prev}, m_next{__next} {}
        Node(T&& __data, Node* __prev = nullptr, Node* __next = nullptr) : m_data{std::move(__data)}, m_prev{__prev}, m_next{__next} {}
    };

public:
    class const_iterator
    {
    protected:
        Node* m_node;
        const_iterator(Node* __node) : m_node{__node} {}
        friend class list<T>;

    public:
        const_iterator() : m_node{nullptr} {}
        const T& operator*() const{ return const_cast<const T&>(m_node->m_data); }
        const_iterator& operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        const_iterator operator++(int)
        {
            const_iterator __tmp = *this;
            m_node = m_node->m_next;
            return __tmp;
        }
        const_iterator& operator--()
        {
            m_node = m_node->prev;
            return *this;
        }
        const_iterator operator--(int)
        {
            const_iterator __tmp = *this;
            m_node = m_node->prev;
            return __tmp;
        }
        bool operator==(const const_iterator& rhs){ return m_node == rhs.m_node; }
        bool operator!=(const const_iterator& rhs){ return m_node != rhs.m_node; }
    };

    class iterator
    {
    protected:
        Node* m_node;
        iterator(Node* __node) : m_node{__node} {}
        friend class list<T>;

    public:
        iterator() : m_node{nullptr} {}
        T& operator*(){ return m_node->m_data; }
        const T& operator*() const{ return m_node->m_data; }
        iterator& operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        iterator operator++(int)
        {
            iterator __tmp = *this;
            m_node = m_node->m_next;
            return __tmp;
        }
        iterator& operator--()
        {
            m_node = m_node->prev;
            return *this;
        }
        iterator operator--(int)
        {
            iterator __tmp = *this;
            m_node = m_node->prev;
            return __tmp;
        }
        bool operator==(const iterator& rhs){ return m_node == rhs.m_node; }
        bool operator!=(const iterator& rhs){ return m_node != rhs.m_node; }
    };

public:
    list(){ __init__(); }
    ~list()
    {
        clear();
        delete m_head;
        delete m_tail;
    }
    list(const list& rhs)
    {
        __init__();
        for(auto& __item : rhs)
            push_back(__item);
    }
    list& operator=(const list& rhs)
    {
        if(this != std::addressof(rhs))
        {
            list __copy(rhs);
            std::swap(*this, __copy);            
        }
        return *this;
    }
    list(list&& rhs) : m_size{rhs.m_size}, m_head{rhs.m_head}, m_tail{rhs.m_tail}
    {
        rhs.m_size = 0U;
        rhs.m_head = nullptr;
        rhs.m_tail = nullptr;
    }
    list& operator=(list&& rhs)
    {
        std::swap(m_size, rhs.m_size);
        std::Swap(m_head, rhs.m_head);
        std::swap(m_tail, rhs.m_tail);
        rhs.m_size = 0U;
        rhs.m_head = nullptr;
        rhs.m_tail = nullptr;
        return *this;
    }
    iterator begin(){ return {head->next}; }
    iterator end(){ return {tail}; }
    const_iterator begin() const{ return {head->next}; }
    const_iterator end() const{ return {tail}; }
    std::size_t size(){ return m_size; }
    bool empty(){ return m_size == 0U; }
    void clear()
    {
        while(m_size != 0U)
            pop_front();
    }
    T& front(){ return *begin(); }
    const T& front() const{ return *begin(); }
    T& back(){ return *--end(); }
    const T& back() const{ return *--end(); }
    void push_front(const T& __item){ insert(begin(), __item); }
    void push_front(T&& __item){ insert(begin(), std::move(__item)); }
    void push_back(const T& __item){ insert(end(), __item); }
    void push_back(T&& __item){ insert(end(), std::move(__item)); }
    void pop_front(){ erase(begin()); }
    void pop_back(){ erase(--end()); }
    iterator insert(iterator __itr, const T& __item)
    {
        Node* __node = __itr.m_node;
        ++m_size;
        return {__node->prev = __node->prev->next = new Node{__item, __node->prev, __node}};
    }
    iterator insert(iterator __itr, T&& __item)
    {
        Node* __node = __itr.m_node;
        ++m_size;
        return {__node->prev = __node->prev->next = new Node{std::move(__item), __node->prev, __node}};
    }
    iterator erase(iterator __itr)
    {
        Node* __node = __itr.m_node;
        iterator __ret{__node->next};
        __node->prev->next = __node->next;
        __node->next->prev = __node->prev;
        delete __itr;
        --m_size;
        return __ret;
    }
    iterator erase(iterator __begin, iterator __end)
    {
        for(iterator __itr = __begin, __itr != __end;)
            __itr = erase(__itr);
        return __end;
    }

private:
    std::size_type  m_size;
    Node*           m_head;
    Node*           m_tail;

    void __init__()
    {
        m_size = 0;
        m_head = new Node;
        m_tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
};

#endif