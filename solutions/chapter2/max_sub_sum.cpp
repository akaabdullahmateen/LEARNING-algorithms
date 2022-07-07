#include <vector>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdlib>
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
    for(std::vector<int>::difference_type idx = center; idx > left; --idx)
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

void stopwatch(int (*maxSubSumN)(const std::vector<int>&), const std::vector<int> &v)
{
    std::chrono::time_point start = std::chrono::steady_clock::now();
    std::cout << maxSubSumN(v) << std::endl;
    std::chrono::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> runtime = end - start;
    std::cout << "(time) : " << std::fixed << std::setprecision(9) << std::left << std::setw(9) << runtime.count();
}

int randInt()
{
    return std::rand() % 101 - 50;
}

void populate(std::vector<int> &v)
{
    for(int &i : v)
        i = randInt();
}

int main()
{
    std::srand(std::time(NULL));
    std::vector<int> small(1000);
    std::vector<int> big(10000);
    populate(small);
    populate(big);
    std::cout << "[BRUTE FORCE] \t\t\t: ";
    stopwatch(maxSubSum1, small);
    std::cout << std::endl;
    std::cout << "[BRUTE FORCE] \t\t\t: ";
    //stopwatch(maxSubSum1, big); // <-- Commented out because it would take too long
    std::cout << std::endl;
    std::cout << "[OPTIMIZED BRUTE FORCE] \t: ";
    stopwatch(maxSubSum2, small);
    std::cout << std::endl;
    std::cout << "[OPTIMIZED BRUTE FORCE] \t: ";
    stopwatch(maxSubSum2, big);
    std::cout << std::endl;
    std::cout << "[DIVIDE AND CONQUER] \t\t: ";
    stopwatch(maxSubSum3, small);
    std::cout << std::endl;
    std::cout << "[DIVIDE AND CONQUER] \t\t: ";
    stopwatch(maxSubSum3, big);
    std::cout << std::endl;
    std::cout << "[LINEAR] \t\t\t: ";
    stopwatch(maxSubSum4, small);
    std::cout << std::endl;
    std::cout << "[LINEAR] \t\t\t: ";
    stopwatch(maxSubSum4, big);
    std::cout << std::endl;
    return 0;
}