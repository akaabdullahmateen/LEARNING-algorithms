#ifndef ORDERED_COLLECTION_H
#define ORDERED_COLLECTION_H

#include <vector>
#include <iostream>

template<typename OBJECT>
class OrderedCollection
{
private:
    std::vector<OBJECT> objects;
    typename std::vector<OBJECT>::size_type size;

public:
    explicit OrderedCollection(const std::vector<OBJECT> &m_objects = std::vector<OBJECT>{}) : objects{m_objects}, size{0} {}

    bool isEmpty() const
    {
        return objects.empty();
    }

    void makeEmpty()
    {
        objects.clear();
        size = 0;
    }

    void insert(const typename std::vector<OBJECT>::size_type pos, const OBJECT obj)
    {
         typename std::vector<OBJECT>::const_iterator itr = objects.cbegin() + pos;
         objects.insert(itr, obj);
         ++size;
    }

    void remove(const OBJECT obj)
    {
        if(isEmpty()) return;
        for(typename std::vector<OBJECT>::size_type idx = 0; idx < objects.size(); ++idx)
        {
            if(objects.at(idx) == obj)
            {
                typename std::vector<OBJECT>::const_iterator itr = objects.cbegin() + idx;
                objects.erase(itr);
                --size;
            }
        }
    }

    OBJECT findMin() const
    {
        OBJECT min = objects[0]; // <-- initial seed
        for(const OBJECT &current : objects)
        {
            if(current < min)
            {
                min = current;
            }
        }
        return min;
    }

    OBJECT findMax() const
    {
        OBJECT max = OBJECT{};
        for(const OBJECT &current : objects)
        {
            if(current > max)
            {
                max = current;
            }
        }
        return max;
    }

    void read() const
    {
        if(isEmpty())
        {
            std::cout << "[EMPTY]" << std::endl;
            return;
        }
        for(const OBJECT &obj : objects)
        {
            std::cout << obj << " ";
        }
        std::cout << std::endl;
    }
};

#endif