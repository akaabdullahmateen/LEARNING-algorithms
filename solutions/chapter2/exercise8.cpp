#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define N 5

std::size_t randInt(std::size_t min, std::size_t max)
{
    return std::rand() % (max - min + 1) + min;
}

bool contains(const std::vector<std::size_t> &a, const std::size_t x)
{
    for(const std::size_t i : a)
        if(x == i)
            return true;
    return false;
}

template<typename Container>
void print(const Container &a)
{
    std::cout << "[ ";
    for(auto i : a)
        std::cout << i << ", ";
    std::cout << "\b\b ]" << std::endl;
}

template<typename Container>
void swap(Container &a, typename Container::size_type i, typename Container::size_type j)
{
    auto temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void algo1()
{
    std::vector<std::size_t> a;
    for(std::vector<std::size_t>::size_type i = 0; i < N; ++i)
    {
        std::size_t random;
        do
            random = randInt(1, N);
        while(contains(a, random));
        a.push_back(random);
    }    
    print(a);
}

void algo2()
{
    std::vector<std::size_t> a;
    std::size_t used[N] = {0};
    for(std::vector<std::size_t>::size_type i = 0; i < N; ++i)
    {
        std::size_t random;
        while(true)
        {
            random = randInt(1, N);
            if(used[random - 1])
                continue;
            used[random - 1] = 1;
            break;
        }
        a.push_back(random);
    }    
    print(a);
}

void algo3()
{
    std::vector<std::size_t> a;
    for(std::vector<std::size_t>::size_type i = 0; i < N; ++i)
        a.push_back(i + 1);
    for(std::vector<std::size_t>::size_type i = 0; i < N; ++i)
        swap(a, i, randInt(0, i));
    print(a);
}

int main()
{
    std::srand(std::time(NULL));
    algo1();
    algo2();
    algo3();
    return 0;
}