#ifndef PERIMETER_COMPARE_H
#define PERIMETER_COMPARE_H

#include "rectangle.h"

class PerimeterCompare
{
public:
    bool operator()(const Rectangle &lhs, const Rectangle &rhs)
    {
        return lhs.getPerimeter() < rhs.getPerimeter();
    }
};

#endif