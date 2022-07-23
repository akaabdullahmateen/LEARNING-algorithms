#include <iostream>

#define MAX_N 10

typedef long long int64;

int64 pow(int64 base, std::size_t n)
{
    if(!n)
        return 1;
    if(n % 2)
        return pow(base, n - 1) * base;
    return pow(base * base, n / 2);
}

int main()
{
    int64 base = 2;
    for(std::size_t n = 0; n < MAX_N; ++n)
        std::cout << base << "^" << n << "\t= " << pow(base, n) << std::endl;
    return 0;
}