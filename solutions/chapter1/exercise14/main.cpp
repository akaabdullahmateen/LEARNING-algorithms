#include <iostream>
#include <string>

#include "ordered_collection.h"

int main()
{
    constexpr std::size_t strings_size = 10;
    std::string strings[strings_size] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    OrderedCollection<std::string> collection;
    collection.read();
    std::cout << "isEmpty() = " << ((collection.isEmpty()) ? "true" : "false") << std::endl;
    for(std::size_t idx = 0; idx < strings_size; ++idx)
    {
        collection.insert(idx, strings[idx]);
        collection.read();
    }
    std::cout << "findMin() = " << collection.findMin() << std::endl;
    std::cout << "findMax() = " << collection.findMax() << std::endl;
    collection.remove("a");
    collection.read();
    collection.makeEmpty();
    collection.read();
    return 0;
}