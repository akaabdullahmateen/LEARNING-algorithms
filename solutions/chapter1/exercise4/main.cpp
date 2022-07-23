/*
 * Exercise 1.4
 *
 * C++ allows statements of the form: #include filename
 * Which reads ﬁlename and inserts its contents in place of the include statement
 * Include statements may be nested; in other words, the ﬁle ﬁlename may itself contain an include statement
 * But, obviously, a ﬁle can’t include itself in any chain
 * Write a program that reads in a ﬁle and outputs the ﬁle as modiﬁed by the include statements
 */

/* Assumptions
 *
 * 1. No file contains an include directive that points to itself
 * 2. There is exactly one space between the #include keyword and the filename
 * 3. All files are well-formed, there are no strange characters used, and all files end with END-OF-FILE
 * 4. Files are considerably small (fewer than 1000 characters)
 * 5. All #include directives are proceeded by a filename
 * 6. The filename only contains alphabetical characters and punctuation
 */


#include <fstream>
#include <string>
#include <iostream>

#include "header.h"

std::string readfile(std::string filename){
    std::string final;
    std::string line;
    std::ifstream file(filename);
    while(getline(file, line)){
        final += (line + "\n");
    }
    final.erase(final.size() - 1, 1);
    return final;
}

bool contains(std::string str, std::string::size_type pos){
    if(str.find("#include", pos) == std::string::npos) return false;
    return true;
}

std::string get_filename(std::string str, std::string::size_type pos){
    std::string::size_type index = str.find("#include", pos);
    index += 8;
    while(std::isspace(str[index])) ++index;
    std::string filename;
    while(std::isalpha(str[index]) || std::ispunct(str[index])) filename += str[index++];
    return filename;
}

std::string &replace(std::string &original, std::string::size_type pos){
    std::string filename = get_filename(original);
    std::string file = readfile(filename);
    std::string::size_type index = original.find("#include", pos);
    original.erase(index, 9);
    index = original.find(filename, index);
    original.erase(index, filename.size());
    original.insert(index, file);
    return original;
}

int main(){
    std::string file = readfile("first.txt");
    while(contains(file)){
        replace(file);
    }
    std::cout << file << std::endl;;
    return 0;
}