#ifndef EXERCISE1_1_H
#define EXERCISE1_1_H

#define MAX_COLLECTION_SIZE 1000
#define MAX_GROUP_SIZE 1000

void swap(unsigned int &left, unsigned int &right);
void sort(std::vector<unsigned int> &vec);
void populate(std::vector<unsigned int> &vec, std::vector<unsigned int>::size_type size);
void print(const std::string &str, const std::vector<unsigned int> &vec);
unsigned int find(const std::vector<unsigned int> &vec, const std::vector<unsigned int>::size_type k);

#endif