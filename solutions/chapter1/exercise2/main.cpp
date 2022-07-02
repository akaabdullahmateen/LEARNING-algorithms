/*
* Exercise 1.2
*
* Write a program to solve the word puzzle problem
*/

/*
* Word Puzzle Problem
*
* The input consists of a two-dimensional array of letters and a list of words
* The object is to ﬁnd the words in the puzzle
* These words may be horizontal, vertical, or diagonal in any direction
*/

/*
* Assumptions
*
* 1. Each individual token is an alphabetical character
* 2. There is atleast one valid character in each line
* 3. No invalid characters are allowed (including numbers and punctuations)
* 4. The width of the puzzle is defined by the fisrt line of input
* 5. All lines have the same number of characters
* 7. Only the vocabulary defined in vocabulary.txt is considered, all other possible words are ignored
* 8. Each line end with the newline character "\n"
* 9. Individual character tokens are separated by a single space only
* 10. However, if multiple spaces are used for separation, it is not an error, and program will function as normal
* 11. Input puzzle is read from input.txt only
* 13. There are no spaces at the start and end of each line in puzzle
* 14. Puzzle has square dimensions
*/

/*
* Algorithm
*
* 1. Generate puzzle from input file
* 2. Generate vocabulary list from vocabulary file
* 3. Check all triples (row, column, orientation) for the presense of word from vocabulary
* 4. On detection, print it to the standard output stream
*/

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "puzzle.h"

Puzzle::Puzzle(std::string ifilename, std::string vfilename){
    std::string read;
    const std::string SEPARATOR(" ");
    std::ifstream ifile(ifilename);
    std::string::size_type pos;
    while(getline(ifile, read)){
        if(read.empty()) continue;
        std::vector<char> line;
        while(pos = read.find(SEPARATOR) != std::string::npos){
            line.push_back(read[0]);
            read.erase(0, pos + 1);
        }
        line.push_back(read[0]);
        puzzle.push_back(line);
        read = std::string{};
    }
    ifile.close();
    std::ifstream vfile(vfilename);
    while(getline(vfile, read)){
        if(read.empty()) continue;
        vocabulary.push_back(read);
    }
    vfile.close();
}

void Puzzle::print() const{
    for(const std::vector<char> &line : puzzle){
        for(const char c : line) std::cout << c << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Puzzle::solve() const{ 
    std::vector<std::vector<char>>::size_type imin = 0;
    std::vector<char>::size_type jmin = 0;
    std::vector<std::vector<char>>::size_type imax = puzzle.size();
    std::vector<char>::size_type jmax = puzzle[0].size();

    for(std::vector<std::vector<char>>::size_type i = 0; i < imax; ++i){
        for(std::vector<char>::size_type j = 0; j < jmax; ++j){
            for(std::vector<char>::size_type k = j; k < jmax; ++k){
                std::string word;
                for(std::vector<char>::size_type l = j; l <= k; ++l){
                    word += puzzle[i][l];
                }
                if(std::find(vocabulary.begin(), vocabulary.end(), word) != vocabulary.end()) std::cout << word << std::endl;
            }
            for(std::vector<char>::size_type k = j; k < jmax; ++k){
                std::string word;
                for(std::vector<char>::size_type l = j; l <= k; ++l){
                    if((i + l - j) == imax) break;
                    word += puzzle[i + l - j][l];
                }
                if(std::find(vocabulary.begin(), vocabulary.end(), word) != vocabulary.end()) std::cout << word << std::endl;
            }
            for(std::vector<char>::size_type k = i; k < imax; ++k){
                std::string word;
                for(std::vector<char>::size_type l = i; l <= k; ++l){
                    word += puzzle[l][j];
                }
                if(std::find(vocabulary.begin(), vocabulary.end(), word) != vocabulary.end()) std::cout << word << std::endl;
            }
            for(std::vector<char>::size_type k = j; k < jmax; --k){
                std::string word;
                for(std::vector<char>::size_type l = j; l >= k; --l){
                    if((i - l + j) == imax) break;
                    word += puzzle[i - l + j][l];
                }
                if(std::find(vocabulary.begin(), vocabulary.end(), word) != vocabulary.end()) std::cout << word << std::endl;
            }
            for(std::vector<char>::size_type k = j; k < jmax; --k){
                std::string word;
                for(std::vector<char>::size_type l = j; l >= k; --l){
                    if((i - l + j) == imax) break;
                    word += puzzle[i][l];
                }
                if(std::find(vocabulary.begin(), vocabulary.end(), word) != vocabulary.end()) std::cout << word << std::endl;
            }
            auto limit = ((i < j) ? i : j);
            for(std::vector<char>::size_type k = 0; k <= limit; ++k){
                std::string word;
                for(std::vector<char>::size_type l = 0; l <= k; ++l){
                    word += puzzle[i - l][j - l];
                }
                if(std::find(vocabulary.begin(), vocabulary.end(), word) != vocabulary.end()) std::cout << word << std::endl;
            }
            for(std::vector<char>::size_type k = 0; k < i; ++k){
                std::string word;
                for(std::vector<char>::size_type l = 0; l <= k; ++l){
                    word += puzzle[i - l][j];
                }
                if(std::find(vocabulary.begin(), vocabulary.end(), word) != vocabulary.end()) std::cout << word << std::endl;
            }
            limit = (((i + 1) < (jmax - j)) ? i + 1 : jmax - j);
            for(std::vector<char>::size_type k = 0; k < limit; ++k){
                std::string word;
                for(std::vector<char>::size_type l = 0; l <= k; ++l){
                    word += puzzle[i - l][j + l];
                }
                if(std::find(vocabulary.begin(), vocabulary.end(), word) != vocabulary.end()) std::cout << word << std::endl;
            }
        }
    }
}

int main(){
    Puzzle puzzle;
    puzzle.print();
    puzzle.solve();
    return 0;
}