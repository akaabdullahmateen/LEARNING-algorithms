#ifndef STL_LIST_H
#define STL_LIST_H

namespace stl
{
    template<typename T>
    struct Node
    {
        Node* prev;
        Node* next;
        T     data;
    };

    class list
    {

    };
}

#endif