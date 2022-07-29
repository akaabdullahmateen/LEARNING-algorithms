#ifndef STACK_H
#define STACK_H

#define GUARANTEED_CAPACITY 2

template<typename T>
class sequence
{
public:
    typedef const T&        const_reference;
    typedef T&              reference;
    typedef T*              iterator;
    typedef T               value_type;
    typedef std::size_type  size_type;

    sequence() : m_size(0U), m_base(GUARANTEED_CAPACITY)
    {
        m_base = new T[GUARANTEED_CAPACITY];
    }

    template<typename... _Args>
    void emplace(_Args &&...__args);
    bool empty()
    {
        return m_size == 0;
    }
    void pop_back();
    void push_back(const value_type &__x);
    void push_back(value_type &&__x);
    size_type size() const
    {
        return m_size;
    }
    reference back();
    const_reference back() const;

private:
    iterator m_base;
    size_type m_size;
    size_type m_capacity;

    void reallocate(size_type __capacity)
    {
        if(m_capacity >= __capacity) return;
        iterator __tmp_base = new value_type[__capacity];
        for(size_type idx = 0; idx != m_size; ++idx)
            __tmp_base[idx] = m_base[idx];
        std::destroy(m_base, m_base + m_size);
        m_base = __tmp_base;
        delete __tmp_base;
    }
};

class stack
{
    typedef sequence::const_reference   const_reference;
    typedef sequence::reference         reference;
    typedef sequence::value_type        value_type;
    typedef sequence::size_type         size_type;

    stack(const sequence &__c);
    stack(sequence &&__c = sequence());
    template<typename... _Args>
    void emplace(_Args &&...__args)
    {
        c.emplace(__args);
    }
    bool empty() const
    {
        return c.empty();
    }
    void pop()
    {
        c.pop_back();
    }
    void push(const value_type &__x)
    {
        c.push_back(__x);
    }
    void push(value_type &&__x)
    {
        c.push_back(__x);
    }
    size_type size() const
    {
        return c.size();
    }
    void swap(stack &__s);
    reference top()
    {
        return c.back();
    }
    const_reference top() const
    {
        return c.back();
    }

    private:
        sequence c;
};

#endif