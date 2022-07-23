#ifndef HEADER_H
#define HEADER_H

#include <vector>

int max3(int n1, int n2, int n3);
int maxSubSum1(const std::vector<int> &v);
int maxSubSum2(const std::vector<int> &v);
int maxSubSum3(const std::vector<int> &v);
int maxSubSum4(const std::vector<int> &v);
int maxSumRec(const std::vector<int> &v, std::vector<int>::size_type left, std::vector<int>::size_type right);

#endif