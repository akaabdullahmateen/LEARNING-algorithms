#include <iostream>

#include "header.h"

unsigned int mod(unsigned int exponent, unsigned int base){
    unsigned int pattern[4] = {1, 2, 4, 5};
    return pattern[exponent % 4];
}

int main(){
    std::cout << "2^100 (mod 5) = " << mod(100) << std::endl;
    return 0;
}