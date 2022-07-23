/*
* Exercise 1.1
*
* Write a program to solve the selection problem
* Let k = N / 2
* Draw a table showing the running time of your program for various values of N
*/

/*
* Selection problem
*
* Suppose you have a group of N numbers and would like to determine the kth largest
*/

/*
* Assumptions
*
* 1. This group of N numbers are stored in a vector of size N
* 2. The type of numbers is unsigned int
* 3. The index returned in all cases (odd and even), in a sorted vector, would be: N / 2
* 4. The numbers in all vectors are unsorted
* 5. The element integers will be generated using random number generation
* 6. These integers will be bound between 0 and 99 (inclusive), and duplicates will be allowed
* 7. For performance reasons, the maximum value of N (size of any vector) is capped at 100
* 8. The values of N tested are at the range 1..99 (inclusive)
* 9. The running time account for is between the vector population and printing fo the result
*/

/*
* Selection algorithm
*
* 1. Sort each group (vector) using bubble sort
* 2. The kth largest is the element at index N / 2
*/

#define NDEBUG

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <vector>
#include <string>
#include <iostream>

#include "header.h"

void swap(unsigned int &left, unsigned int &right){
    unsigned int temp = right;
    right = left;
    left = temp;
}

void sort(std::vector<unsigned int> &vec){
    for (std::vector<unsigned int>::size_type i = 0; i < vec.size(); ++i)
        for (std::vector<unsigned int>::size_type j = 0; j < vec.size() - i - 1; ++j)
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
}

void populate(std::vector<unsigned int> &vec, std::vector<unsigned int>::size_type size){
    if(size > MAX_GROUP_SIZE) size == MAX_GROUP_SIZE;
    for(std::vector<unsigned int>::size_type idx = 0; idx < size; ++idx) vec.push_back(std::rand() % MAX_GROUP_SIZE); 
}

void print(const std::string &str, const std::vector<unsigned int> &vec){
    std::cout << str << " : ";
    for(const unsigned int i : vec) std::cout << i << " ";
    std::cout << std::endl;
}

unsigned int find(const std::vector<unsigned int> &vec, const std::vector<unsigned int>::size_type k){
    return vec[k];
}

int main(){
    std::srand(std::time(NULL));
    std::cout << std::fixed << std::setprecision(3) << std::left;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "| \t N \t | \t Running Time \t |" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    for(std::vector<unsigned int>::size_type N = 1; N <= MAX_COLLECTION_SIZE; ++N){
        std::vector<unsigned int> group;
        populate(group, N);
        #ifndef NDEBUG
        print("BEFORE SORT", group);
        #endif
        std::chrono::time_point start = std::chrono::steady_clock::now();
        sort(group);
        unsigned int kth_largest = find(group, N / 2);
        std::chrono::time_point end = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "| \t" << N << "\t | \t" << diff.count() * 1000000 << " ns \t |" << std::endl;
        #ifndef NDEBUG
        print("AFTER SORT", group);
        #endif
        #ifndef NDEBUG
        std::cout << "KTH LARGEST : " << kth_largest << std::endl << std::endl;
        #endif
    }
    std::cout << "------------------------------------------" << std::endl;
    return 0;
}