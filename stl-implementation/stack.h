#ifndef STACK_H
#define STACK_H

#include <vector>

template<typename T>
class stack
{
public:
    typedef typename std::vector<T>::const_reference   const_reference;
    typedef typename std::vector<T>::reference         reference;
    typedef typename std::vector<T>::value_type        value_type;
    typedef typename std::vector<T>::size_type         size_type;

    stack(const std::vector<T> &__c) : c{__c} {}
    stack(std::vector<T> &&__c = std::vector<T>()) : c{__c} {};
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
    reference top()
    {
        return c.back();
    }
    const_reference top() const
    {
        return c.back();
    }

private:
        std::vector<T> c;
};

#endif