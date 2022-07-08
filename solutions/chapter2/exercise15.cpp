#include <vector>
#include <iostream>

/*
 * 1. Assumes Container has difference_type, size()
 * 2. Assumes Object has comparison operators (<, >) overloaded
 */

template <typename Container, typename Object>
bool contains(Container &v, Object x)
{
    typename Container::difference_type low = 0;
    typename Container::difference_type high = v.size() - 1;
    typename Container::difference_type mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(v[mid] > x)
            high = mid - 1;
        else if(v[mid] < x)
            low = mid + 1;
        else
            return true;
    }
    return false;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << (contains(v, 5) ? "true" : "false") << std::endl;
    return 0;
}