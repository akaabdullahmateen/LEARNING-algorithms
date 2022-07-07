#include <iostream>

typedef long long int64;

int64 gcd(int64 m, int64 n)
{
    while(n)
    {
        int64 rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

int main(){
    std::cout << "gcd(1989, 1590) = " << gcd(1989, 1590) << std::endl;
    return 0;
}