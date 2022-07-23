#ifndef HEADER_H
#define HEADER_H

#include <functional>
#include <vector>
#include <string>

#include "rectangle.h"

template<typename Object, typename Comparator>
const std::string findMax(const std::vector<Object> &vec, Comparator isLessThan)
{
    std::size_t maxIndex = 0;
    for(typename std::vector<Object>::size_type idx = 1; idx < vec.size(); ++idx)
    {
        if(isLessThan(vec[maxIndex], vec[idx]))
        {
            maxIndex = idx;
        }
    }
    return vec[maxIndex].getName();
}

template<typename Object>
const std::string findMax(const std::vector<Object> &vec)
{
    return findMax(vec, std::less<Object>{});
}

std::size_t getRandom();
void print(const std::vector<Rectangle> &rectangles);
void populate(std::vector<Rectangle> &rectangles);
void seed();
void compare(const std::vector<Rectangle> &rectangles);

#endif