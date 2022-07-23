/* Calculate sum of all cubes from i = 1 until (and including) N */

#include <iostream>

#define N 100

int main()
{
    std::string expansion;
    std::size_t partialSum = 0;
    for(std::size_t i = 1; i < N; ++i)
    {
        expansion += std::to_string(i) + "^3 + ";
        std::cout << expansion << "\b\b:" << std::endl;
        partialSum += i * i * i;
        std::cout << partialSum << std::endl << std::endl;
    }
    return 0;
}