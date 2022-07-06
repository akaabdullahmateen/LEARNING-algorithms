#include <iostream>

#define N 10

std::size_t factorial(std::size_t n)
{
    if(n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    for(std::size_t i = 0; i < N; ++i)
    {
        std::cout << i << "! = " << factorial(i) << std::endl;
    }
    return 0;
}