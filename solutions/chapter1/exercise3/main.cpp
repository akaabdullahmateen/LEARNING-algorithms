/*
* Exercise 1.3:
*
* Write a function to output an arbitrary double number (which might be negative) using only printDigit for I/O
*/

/* Assumptions
*
* 1. Double number means double-precision floating-point number
* 2. Negative sign will be processed separately
* 3. Function printDigit() will only print one digit at a time using recursion
* 4. Random number will be generated on each program execution to serve as the arbitrary double number
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "header.h"

void printDigit(double number){
    if(number < 0){
        number = -1 * number;
        std::cout << "MINUS" << " ";
    }
    int digit = static_cast<int>(number);
    std::cout << digit << " ";
    if(digit == number){
        std::cout << std::endl;
        return;
    }
    else{
        number *= 10;
        number -= digit * 10;
        printDigit(number);
    }
}

double getRandomNumber(bool negative){
    if(negative) return (-1 * (static_cast<double>(std::rand() % 10000000) / 1000000));
    return (static_cast<double>(std::rand() % 10000000) / 1000000);
}

bool getRandomSign(){
    if(std::rand() % 2) return false;
    return true;
}

void loop(){
    for(unsigned int i = 0; i < 10; ++i){
        double number = getRandomNumber(getRandomSign());
        std::cout << number << std::endl;
        printDigit(number);
        std::cout << std::endl;
    }
}

int main(){
    std::srand(std::time(NULL));
    loop();
    return 0;
}