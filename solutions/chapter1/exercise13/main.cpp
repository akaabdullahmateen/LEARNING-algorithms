#include <string>
#include <vector>
#include <iostream>

#include "collection.h"

int main()
{
    std::string x;
    std::vector<std::string> objects;

    std::cout << "constructor()" << std::endl;
    Collection collection(objects);

    std::cout << "isEmpty() = " << ((collection.isEmpty()) ? "true" : "false") << std::endl;

    x = "a";
    std::cout << "insert( " << x << " )" << std::endl;
    collection.insert(x);

    x = "b";
    std::cout << "insert( " << x << " )" << std::endl;
    collection.insert(x);

    x = "c";
    std::cout << "insert( " << x << " )" << std::endl;
    collection.insert(x);

    x = "d";
    std::cout << "insert( " << x << " )" << std::endl;
    collection.insert(x);

    x = "e";
    std::cout << "insert( " << x << " )" << std::endl;
    collection.insert(x);
    
    std::cout << "remove()" << std::endl;
    collection.remove();

    x = "a";
    std::cout << "contains( " << x << " ) = " << ((collection.contains(x)) ? "true" : "false") << std::endl;
    
    return 0;
}