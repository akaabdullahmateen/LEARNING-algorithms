#ifndef COLLECTION_H
#define COLLECTION_H

#include <string>
#include <vector>


template<typename OBJECT>
class Collection
{
private:
    std::vector<OBJECT> objects;

public:
    explicit Collection(const std::vector<OBJECT> &m_objects = std::vector<OBJECT>{}) : objects{m_objects} {};
    
    bool isEmpty() const
    {
        return objects.empty();
    }

    void makeEmpty()
    {
        objects.clear();
    }

    void insert(const OBJECT &x)
    {
        objects.push_back(x);
    }

    void remove()
    {
        objects.pop_back();
    }

    bool contains(const OBJECT &x) const
    {
        for(const OBJECT i : objects)
        {
            if(i == x) return true;
        }
        return false;
    }
};

#endif