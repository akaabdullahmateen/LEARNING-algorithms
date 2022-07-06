#include <iostream>
#include <cmath>

#define N 10

std::size_t fibonacci(std::size_t n)
{
    double phi = 1.618033988749895;
    double psi = -0.6180339887498948;
    return (std::pow(phi, n) - std::pow(psi, n)) / (phi - psi);
}

int main()
{
    for(std::size_t i = 0; i < N; ++i)
        std::cout << fibonacci(i) << std::endl;
    return 0;
}