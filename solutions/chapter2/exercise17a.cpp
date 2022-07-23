#include <vector>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <iostream>

int bruteforce(const std::vector<int> &v){
    int minSum = v[0];
    int sum;
    for(std::vector<int>::size_type begin = 0; begin < v.size(); ++begin)
    {
        sum = 0;
        for(std::vector<int>::size_type end = begin; end < v.size(); ++end)
        {   sum += v[end];
            if(sum < minSum)
                minSum = sum;
        }
    }
    return minSum;
}

int minSubSum(const std::vector<int> &v)
{
    int thisSum = 0;
    int minSum = v[0];
    for(std::vector<int>::size_type idx = 0; idx < v.size(); ++idx)
    {
        thisSum += v[idx];
        if(thisSum < minSum)
            minSum = thisSum;
        else if(thisSum > 0)
            thisSum = 0;
    }
    return minSum;
}

void stopwatch(int (*func)(const std::vector<int>&), const std::vector<int> &v)
{
    std::chrono::time_point start = std::chrono::steady_clock::now();
    std::cout << "(return) : " << func(v) << std::endl;
    std::chrono::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> runtime = end - start;
    std::cout << "(time) : " << std::fixed << std::setprecision(9) << std::left << std::setw(9) << runtime.count() << std::endl;
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
    std::vector<int> v(10000);
    std::cout << "Generating vector ..." << std::endl;
    populate(v);
    std::cout << "[BRUTE FORCE]" << std::endl;
    stopwatch(bruteforce, v);
    std::cout << std::endl;
    std::cout << "[LINEAR]" << std::endl;
    stopwatch(minSubSum, v); 
    return 0;
}