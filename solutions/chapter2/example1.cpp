/* Calculate sum of all cubes from i = 1 until (and including) N */

#include <iostream>

std::size_t cubeSum(std::size_t n)
{
    std::size_t partialSum = 0;
    for(std::size_t i = 0; i <= n; ++i)
        partialSum += i * i * i;
    return partialSum;
}

int main()
{
    for(std::size_t i = 1; i < 10; ++i)
    {
        std::size_t j = 1;
        for(; j < i; ++j)
            std::cout << j << "^3 + ";
        std::cout << j << "^3 :" << std::endl;
        std::cout << cubeSum(i) << std::endl;
    }
    return 0;
}