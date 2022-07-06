#include <iostream>

#define N 10

std::size_t fibonacci(std::size_t n)
{
    if(n <= 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    for(std::size_t i = 0; i < N; ++i)
        std::cout << fibonacci(i) << std::endl;
    return 0;
}