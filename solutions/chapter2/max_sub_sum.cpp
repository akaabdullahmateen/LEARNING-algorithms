#include <vector>
#include <iostream>

int maxSubSum1(const std::vector<int> &v)
{
    int maxSum = 0;
    for(std::size_t begin = 0; begin < v.size(); ++begin)
        for(std::size_t end = begin; end < v.size(); ++end)
        {
            int thisSum = 0;
            for(std::size_t idx = begin; idx <= end; idx++)
                thisSum += v[idx];
            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    return maxSum;
}

int maxSubSum2(const std::vector<int> &v)
{
    return 0;
}

int maxSubSum3(const std::vector<int> &v)
{
    return 0;
}

int maxSubSum4(const std::vector<int> &v)
{
    return 0;
}

int main()
{
    const std::vector<int> v {-2, 11, -4, 13, -5, -2};
    std::cout << "ALGORITHM 1 : " << maxSubSum1(v) << std::endl;
    std::cout << "ALGORITHM 2 : " << maxSubSum2(v) << std::endl;
    std::cout << "ALGORITHM 3 : " << maxSubSum3(v) << std::endl;
    std::cout << "ALGORITHM 4 : " << maxSubSum4(v) << std::endl;
    return 0;
}