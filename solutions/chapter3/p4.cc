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
*/

template<typename List>
List find_intersection(const List &L1, const List &L2)
{
    List intersection;
    typename List::const_iterator p = L1.begin();
    typename List::const_iterator q = L2.begin();
    for(;p != L1.end() && q != L2.end();)
    {
        if(*p > *q) ++q;
        else if(*p < *q) ++p;
        else{
            intersection.push_back(*p);
            ++p;
            ++q;
        }
    }
    return intersection;
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
    std::list<int> L2{2,3,5};
    std::list<int> intersection = find_intersection(L1, L2);
    print(intersection, std::cout);
    return 0;
}