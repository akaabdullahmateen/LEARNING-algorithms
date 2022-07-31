#include <list>
#include <iostream>

/*
* @param List: must have typedef type const_iterator, which implements the following overloaded operators:
* ---- operator *: for dereferencing the underlying data, which must implement the following relational overloaded operators:
* ---- ---- operator >: for less than
* ---- ---- operator <: for greater than
* ---- ---- operator ==: for equality (although, not explicitly used, it is implied)
* ---- operator ++: for incrementing iterator to point to the next node in the list 
* @param List: must implement begin() member function
* @param List: must implement end() member function
* @param List: must implement push_back() member function
* @param List: must implement size() member function
*/

template<typename List>
List find_union(const List &L1, const List &L2)
{
    List __union;
    typename List::const_iterator p = L1.begin();
    typename List::const_iterator q = L2.begin();
    const typename List::size_type limit = L1.size() + L2.size();
    bool invalidate_A = false;
    bool invalidate_B = false;
    for(typename List::size_type idx = 0; idx < limit; ++idx)
    {
        if(p == L1.end()) invalidate_A = true;
        if(q == L2.end()) invalidate_B = true;
        if(invalidate_A && invalidate_B) return __union;
        if(invalidate_A)
        {
            __union.push_back(*q);
            ++q;
        }
        else if(invalidate_B)
        {
            __union.push_back(*p);
            ++p;
        }
        else if(*p < *q)
        {
            __union.push_back(*p);
            ++p;
        }
        else if(*p > *q)
        {
            __union.push_back(*q);
            ++q;
        }
        else if(*p == *q)
        {
            __union.push_back(*p);
            ++p, ++q;
        }
        else
        {
            return __union;
        }
    }
    return __union;
}

/*
* @param List: must have typedef type const_iterator, which implements the following overloaded operators:
* ---- operator *: for dereferencing the underlying data
* ---- operator ++: for incrementing iterator to point to the next node in the list 
* @param List: must implement begin() member function
* @param List: must implement end() member function
*/

template<typename List>
void print(const List &L, std::ostream &os)
{
    typename List::const_iterator itr = L.begin();
    while(itr != L.end())
    {
        os << *itr << " ";
        ++itr;
    }
    os << std::endl;
}

int main()
{
    std::list<int> L1{1,2,3,4,5};
    std::list<int> L2{5,6,7,8};
    std::list<int> __union = find_union(L1, L2);
    print(__union, std::cout);
    return 0;
}