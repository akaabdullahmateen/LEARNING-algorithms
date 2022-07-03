/*
 * Exercise 1.5
 *
 * Write a recursive function that returns the number of 1 in the binary representation of N
 * Use the fact that this is equal to the number of 1 in the representation of N / 2, plus 1, if N is odd.
 */

/*
 * Assumptions
 *
 * All N are small enough to fit into integer (taken as 16 bit width)
 * All N are strictly positive (unsigned int)
 */

#include <iostream>

#include "header.h"

std::size_t countOnes(unsigned int N){
    if(!N) return N;
    return countOnes(N >> 1) + (N % 2);
}

int main(){
    unsigned int N;
    std::cout << ">> ";
    while(std::cin >> N){
        std::cout << countOnes(N) << std::endl;
        std::cout << ">> ";
    }
    std::cout << "\b\b\b   \b\b  \b \n";    
    return 0;
}