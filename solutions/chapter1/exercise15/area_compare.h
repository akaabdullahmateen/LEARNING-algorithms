#ifndef AREA_COMPARE
#define AREA_COMPARE

#include "rectangle.h"

class AreaCompare
{
public:
    bool operator()(const Rectangle &lhs, const Rectangle &rhs)
    {
        return lhs.getArea() < rhs.getArea();
    }
};

#endif