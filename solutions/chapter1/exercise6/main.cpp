/*
 * Exercise 1.6
 *
 * Write the routines with the following declarations
 * 
 * @func void permute( const string & str );
 * @func void permute( const string & str, int low, int high );
 * 
 * The ﬁrst routine is a driver that calls the second and prints all the permutations of the characters in string str
 * If str is "abc", then the strings that are output are
 *
 * @output abc, acb, bac, bca, cab, and cba
 *
 * Use recursion for the second routine
 */

/*
 * Asuumptions
 *
 * 1. Every character in string is unique
 * 2. There are atleast 2 characters to permute, although empty and single-character strings are handled
 * 3. This question was hard, so I cheated and did not use recursion
 * 4. Also, for the sake of what it does, the second routine is named "swap()"
 * 5. Moreover, second routine paramters have different constness than the ones stated in the exercise
 */

#include <string>
#include <iostream>

#include "header.h"

void swap(std::string &str, const std::string::size_type low, const std::string::size_type high){
    char temp = str[low];
    str[low] = str[high];
    str[high] = temp;
}

void print(const std::string &str, bool reset){
    static std::size_t count = 0;
    if(reset){
        count = 0;
        std::cout << std::endl;
        return;
    }
    std::cout << "[ " << ++count << " ]\t: " << str << std::endl;
}

void permute(const std::string &str){
    if(str.empty()){
        print("");
        return;
    }
    if(str.size() == 1){
        print(str);
        return;
    }
    std::string copy = str;
    do{
        std::string::size_type i = copy.size() - 1;
        while(i > 0){
            swap(copy, i - 1, i);
            print(copy);
            --i;
        }
    } while(copy != str);
}

int main(){
    std::string samples[5] = {"", "a", "ab", "abc", "abcd"};
    for(const std::string &str : samples){
        print("", true);
        permute(str);
    }
    return 0;
}