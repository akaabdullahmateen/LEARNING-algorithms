#include <string>
#include <iostream>

std::size_t pow(std::size_t base, std::size_t n)
{
    if(!n) return 1;
    if(n % 2)
        return pow(base, n - 1) * base;
    return pow(base * base, n / 2);
}

std::size_t add(std::size_t n1, std::size_t n2)
{
    if(!n1 | !n2) return n1 + n2;
    std::size_t max = ((n1 > n2) ? n1 : n2);
    std::size_t d1;
    std::size_t d2;
    std::size_t carry = 0u;
    std::size_t pos = 0u;
    std::size_t sum = 0;
    std::size_t digitSum;
    while(n1 || n2)
    {
        d1 = n1 % 10u;
        d2 = n2 % 10u;
        digitSum = carry + d1 + d2;
        if(digitSum > 10u)
        {
            carry = 1u;
            digitSum -= 10u;
        }
        else
            carry = 0u;
        n1 /= 10u;
        n2 /= 10u;
        sum += digitSum * pow(10u, pos);
        ++pos;
    }
    return sum;
}

std::size_t multiply(std::size_t n1, std::size_t n2)
{
    if(!n1 || !n2) return 0u;
    std::size_t product = 0u;
    std::size_t carry = 0u;
    std::size_t digitProduct;
    std::size_t pos1 = 0u;
    std::size_t pos2;
    std::size_t d2;
    std::size_t n1_copy;
    while(n2)
    {   d2 = n2 % 10u;
        digitProduct = 0u;
        pos2 = 0;
        n1_copy = n1;
        while(n1_copy)
        {
            digitProduct += d2 * (n1_copy % 10u) * pow(10u, pos2);
            n1_copy /= 10;
            ++pos2;
        }
        product += digitProduct * pow(10u, pos1);
        n2 /= 10u;
        ++pos1;
    }
    return product;
}

std::size_t divide(std::size_t n1, std::size_t n2)
{
    if(!n1 || !n2) return 0u;
    if(n1 == n2) return 1;
    std::size_t n1_copy = n1;
    std::size_t len = 0u;
    std::size_t quotient = 0u;
    std::size_t e;
    std::size_t b;
    std::size_t rem;
    std::size_t currQuotient;
    while(n1_copy){
        n1_copy /= 10u;
        ++len;
    }
    while(n1 > n2)
    {
        do{
            --len;
            e = pow(10u, len);
            b = n1 / e;
        } while(b < n2);
        rem = b % n2;
        currQuotient = (b - rem) * e / n2;
        n1 -= n2 * currQuotient;
        quotient += currQuotient;
    }
    return quotient;
}

std::string verify(std::size_t n1, std::size_t n2)
{
    if(n1 == n2)
        return "Correct";
    return "Wrong";
}

int main()
{
    std::size_t n1 = 123456u;
    std::size_t n2 = 123u;
    std::string space = " ";
    std::size_t (*functions [])(std::size_t, std::size_t) = {add, multiply, divide};
    std::string symbols [] = {"+", "*", "/"};
    std::size_t benchmarks [] = {n1 + n2, n1 * n2, n1 / n2};
    std::size_t ret;
    std::size_t i = 0;
    for(std::size_t (*f)(std::size_t, std::size_t) : functions){
        ret = f(n1, n2);
        std::cout << n1 << space << symbols[i] << space << n2 << " = " << ret << std::endl;
        std::cout << verify(ret, benchmarks[i]) << std::endl;
        ++i;
    }
    return 0;
}