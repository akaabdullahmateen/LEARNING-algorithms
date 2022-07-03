#ifndef HEADER_H
#define HEADER_H

#include <string>

std::string readfile(std::string filename);
bool contains(std::string str, std::string::size_type pos = 0);
std::string get_filename(std::string str, std::string::size_type pos = 0);
std::string &replace(std::string &original, std::string::size_type pos = 0);

#endif