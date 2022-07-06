#include <iostream>
#include <vector>

#define NOT_FOUND -1

template<typename Comparable>
Comparable binarySearch(const std::vector<Comparable> &v, const Comparable &x)
{
    typename std::vector<Comparable>::size_type low = 0;
    typename std::vector<Comparable>::size_type high = v.size() - 1;
    while(low <= high)
    {
        typename std::vector<Comparable>::size_type mid = (low + high) / 2;
        if(v[mid] < x)
            low = mid + 1;
        else if(v[mid] > x)
            high = mid - 1;
        else
            return mid;
    }
    return NOT_FOUND;
}

int main()
{
    std::vector<int> v{1,2,3,4,5,6,7,8,9};
    std::cout << "[BINARY SEARCH] : " << binarySearch(v, 4) << std::endl;
    return 0;
}