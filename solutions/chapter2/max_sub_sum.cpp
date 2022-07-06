#include <vector>
#include <iostream>

#include "header.h"

int max3(int n1, int n2, int n3)
{
    if(n1 >= n2 && n1 >= n3) return n1;
    if(n2 >= n1 && n2 >= n3) return n2;
    if(n3 >= n1 && n3 >= n2) return n3;
    return 0; // <--- Should never happen
}

int maxSubSum1(const std::vector<int> &v)
{
    int maxSum = 0;
    for(std::size_t begin = 0; begin < v.size(); ++begin)
        for(std::size_t end = begin; end < v.size(); ++end)
        {
            int thisSum = 0;
            for(std::size_t idx = begin; idx <= end; idx++)
                thisSum += v[idx];
            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    return maxSum;
}

int maxSubSum2(const std::vector<int> &v)
{
    int maxSum = 0;
    for(std::size_t begin = 0; begin < v.size(); ++begin)
    {
        int thisSum = 0;
        for(std::size_t end = begin; end < v.size(); ++end)
        {
            thisSum += v[end];
            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

int maxSubSum3(const std::vector<int> &v)
{
    return maxSumRec(v, 0, v.size() - 1);
}

int maxSubSum4(const std::vector<int> &v)
{
    int maxSum = 0;
    int thisSum = 0;
    for(std::vector<int>::size_type idx = 0; idx < v.size(); ++idx)
    {
        thisSum += v[idx];
        if(thisSum > maxSum)
            maxSum = thisSum;
        else if(thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}

int maxSumRec(const std::vector<int> &v, std::vector<int>::size_type left, std::vector<int>::size_type right)
{
    if(left == right)
        if(v[left] > 0)
            return v[left];
        else
            return 0;
    std::vector<int>::size_type center = (left + right) / 2;
    int maxLeftSum = maxSumRec(v, left, center);
    int maxRightSum = maxSumRec(v, center + 1, right);
    int maxLeftBorderSum = 0;
    int leftBorderSum = 0;
    for(std::vector<int>::size_type idx = center; idx < v.size(); --idx)
    {
        leftBorderSum += v[idx];
        if(leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
    int maxRightBorderSum = 0;
    int rightBorderSum = 0;
    for(std::vector<int>::size_type idx = center + 1; idx <= right; ++idx)
    {
        rightBorderSum += v[idx];
        if(rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int main()
{
    const std::vector<int> v {-2, 11, -4, 13, -5, -2};
    std::cout << "ALGORITHM 1 : " << maxSubSum1(v) << std::endl;
    std::cout << "ALGORITHM 2 : " << maxSubSum2(v) << std::endl;
    std::cout << "ALGORITHM 3 : " << maxSubSum3(v) << std::endl;
    std::cout << "ALGORITHM 4 : " << maxSubSum4(v) << std::endl;
    return 0;
}