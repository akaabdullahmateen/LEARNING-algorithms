#include <cmath>
#include <chrono>
#include <iomanip>
#include <iostream>

bool isPrime(std::size_t n)
{
    std::size_t max = std::sqrt(n) + 1;
    for(std::size_t i = 2; i < max; ++i)
        if(!(n % i))
            return false;
    return true;
}

std::size_t countBits(std::size_t n)
{
    std::size_t i = 0;
    while((1ll << i) <= n)
        ++i;
    return i;
}

void stopwatch(std::size_t n)
{
    std::chrono::time_point start = std::chrono::steady_clock::now();
    bool prime = isPrime(n);
    std::chrono::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> runtime = end - start;
    std::cout << "[BITS] : " << countBits(n) << std::endl;
    if(prime)
        std::cout << "Prime" << std::endl;
    else
        std::cout << "Composite" << std::endl;
    std::cout << "(time) : " << std::fixed << std::setprecision(9) << std::left << std::setw(9) << runtime.count() << std::endl;
}

int main()
{
    std::size_t n;
    std::cout << ">> ";
    while(std::cin >> n)
    {
        stopwatch(n);
        std::cout << ">> ";
    }
    std::cout << "\b\b\b   \b\b  \b \n";
    return 0;
}