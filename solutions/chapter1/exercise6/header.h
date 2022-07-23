#ifndef HEADER_H
#define HEADER_H

#include <string>

void swap(std::string &str, const std::string::size_type low, const std::string::size_type high);
void print(const std::string &str, bool reset = false);
void permute(const std::string &str);

#endif