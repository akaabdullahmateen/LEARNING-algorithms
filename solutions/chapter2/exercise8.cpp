#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <string>
#include <iostream>

std::size_t randInt(std::size_t min, std::size_t max)
{
    return std::rand() % (max - min + 1) + min;
}

bool contains(const std::vector<std::size_t> &a, const std::size_t x)
{
    for(const std::size_t i : a)
        if(x == i)
            return true;
    return false;
}

template<typename Container>
void print(const Container &a)
{
    std::cout << "[ ";
    for(auto i : a)
        std::cout << i << ", ";
    std::cout << "\b\b ]" << std::endl;
}

template<typename Container>
void swap(Container &a, typename Container::size_type i, typename Container::size_type j)
{
    auto temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void algo1(std::size_t N)
{
    std::vector<std::size_t> a;
    for(std::vector<std::size_t>::size_type i = 0; i < N; ++i)
    {
        std::size_t random;
        do
            random = randInt(1, N);
        while(contains(a, random));
        a.push_back(random);
    }    
}

void algo2(std::size_t N)
{
    std::vector<std::size_t> a;
    std::size_t used[N] = {0};
    for(std::vector<std::size_t>::size_type i = 0; i < N; ++i)
    {
        std::size_t random;
        while(true)
        {
            random = randInt(1, N);
            if(used[random - 1])
                continue;
            used[random - 1] = 1;
            break;
        }
        a.push_back(random);
    }    
}

void algo3(std::size_t N)
{
    std::vector<std::size_t> a;
    for(std::vector<std::size_t>::size_type i = 0; i < N; ++i)
        a.push_back(i + 1);
    for(std::vector<std::size_t>::size_type i = 0; i < N; ++i)
        swap(a, i, randInt(0, i));
}

void stopwatch(std::string name, void (*algoN)(std::size_t), std::size_t n)
{
    double runtimeSum = 0;
    for(std::size_t count = 0; count < 10; ++count)
    {
        std::chrono::time_point start = std::chrono::steady_clock::now();
        algoN(n);
        std::chrono::time_point end = std::chrono::steady_clock::now();
        std::chrono::duration<double> runtime = end - start;    
        runtimeSum += runtime.count();
    }
    double runtimeAvg = runtimeSum / 10;
    std::cout << name << " ( " << n << " ) \t: " << std::fixed << std::setprecision(9) << std::left << std::setw(9) << runtimeAvg << std::endl;
}

int main()
{
    std::srand(std::time(NULL));

    const std::size_t iter1[] = {250, 500, 1000, 2000};
    const std::size_t iter2[] = {25000, 50000, 100000, 200000, 400000, 800000};
    const std::size_t iter3[] = {100000, 200000, 400000, 800000, 1600000, 3200000, 6400000};

    for(const std::size_t n : iter1)
        stopwatch("[ALGO1]", algo1, n);
    for(const std::size_t n :iter2)
        stopwatch("[ALGO2]", algo2, n);
    for(const std::size_t n : iter3)
        stopwatch("[ALGO3]", algo3, n);

    return 0;
}