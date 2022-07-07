#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>

#define N 100

void func1()
{
    std::size_t sum = 0;
    for(std::size_t i = 0; i < N; ++i)
        ++sum;
}

void func2()
{
    std::size_t sum = 0;
    for(std::size_t i = 0; i < N; ++i)
        for(std::size_t j = 0; j < N; ++j)
            ++sum;
}

void func3()
{
    std::size_t sum = 0;
    for(std::size_t i = 0; i < N; ++i)
        for(std::size_t j = 0; j < N * N; ++j)
            ++sum;
}

void func4()
{
    std::size_t sum = 0;
    for(std::size_t i = 0; i < N; ++i)
        for(std::size_t j = 0; j < i; ++j)
            ++sum;
}

void func5()
{
    std::size_t sum = 0;
    for(std::size_t i = 0; i < N; ++i)
        for(std::size_t j = 0; j < i * i; ++j)
            for(std::size_t k = 0; k < j; ++k)
                ++sum;
}

void func6()
{
    std::size_t sum = 0;
    for(std::size_t i = 1; i < N; ++i)
        for(std::size_t j = 1; j < i * i; ++j)
            if( j % i == 0)
                for(std::size_t k = 0; k < j; ++k)
                    ++sum;
}

void stopwatch(void (*funcN)(), std::size_t idx)
{
    std::string big_oh[6] = {"O(N)", "O(N2)", "O(N3)", "O(N2)", "O(N5)", "O(N4)"};
    std::chrono::time_point start = std::chrono::steady_clock::now();
    funcN();
    std::chrono::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> runtime = end - start;
    std::cout << "[THEORETICAL] \tRuntime : " << big_oh[idx] << std::endl;
    std::cout << "[ACTUAL] \tRuntime : " << std::fixed << std::setprecision(9) << std::left << std::setw(9) << runtime.count() << std::endl;
}

int main()
{
    void (*functions [])() = {func1, func2, func3, func4, func5, func6};
    std::size_t idx = 0;
    for(void (*f)() : functions)
        stopwatch(f, idx++);
    return 0;
}