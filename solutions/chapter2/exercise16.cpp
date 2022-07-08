#include <iostream>

std::size_t gcd(std::size_t a, std::size_t b)
{
    if(a == b)
        return a;
    if(b > a)
    {
        std::size_t temp = a;
        a = b;
        b = temp;
    }
    if(((a & (~1)) == a) && ((b & (~1)) == b))
        return 2 * gcd(a >> 1, b >> 1);
    if(((a & (~1)) == a) && !((b & (~1)) == b))
        return gcd(a >> 1, b);
    if(!((a & (~1)) == a) && ((b & (~1)) == b))
        return gcd(a, b >> 1);
    return gcd((a + b) >> 1, (a - b) >> 1);
}

int main()
{
    std::cout << gcd(1989, 1590) << std::endl;
    return 0;  
}