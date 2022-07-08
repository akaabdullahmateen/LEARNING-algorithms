#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <iostream>

void print(const std::vector<int> &v)
{
    std::cout << "[ ";
    for(const int i : v)
        std::cout << i << " ";
    std::cout << " ]\n";
}

int bruteforce(const std::vector<int> &v){
    int minSum = v[0];
    int sum;
    for(std::vector<int>::size_type begin = 0; begin < v.size(); ++begin)
    {
        sum = 0;
        for(std::vector<int>::size_type end = begin; end < v.size(); ++end)
        {   sum += v[end];
            if(sum >= 0 && sum < minSum)
                minSum = sum;
        }
    }
    return minSum;
}

int minSubSum(const std::vector<int> &v)
{
    int sum = v[0];
    int minSum = v[0];
    int current;
    for(std::vector<int>::size_type idx = 1; idx < v.size(); ++idx)
    {
        current = v[idx];
        if(sum == 0 || current == 0)
            return 0;
        if(sum < 0 && current < 0)
            sum = current;
        else if(sum < 0 && current > 0)
        {
            if(current < minSum)
                minSum = current;
            sum += current;
        }
        else if(sum > 0 && current > 0)
        {
            if(current > sum && sum < minSum)
                minSum = sum;
            sum = current;
        }
        else if(sum > 0 && current < 0)
        {
            if((sum + current) < 0 && sum < minSum)
                minSum = sum;
            sum += current;
        }
        if(sum >= 0 && sum < minSum)
            minSum = sum;
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
    std::srand(std::time(NULL));
    std::cout << "Generating vector ..." << std::endl;
    std::cout << std::endl;
    std::vector<int> v(1000);
    populate(v);
    std::cout << "[BRUTE FORCE]" << std::endl;
    stopwatch(bruteforce, v);
    std::cout << std::endl;
    std::cout << "[LINEAR]" << std::endl;
    stopwatch(minSubSum, v); 
    return 0;
}