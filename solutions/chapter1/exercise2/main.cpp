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
*/

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Puzzle{

private:
    std::vector<std::vector<char>> puzzle;
    std::vector<std::string> vocabulary;
    std::string::size_type max;
    std::vector<char>::size_type length;

public:
    Puzzle(std::string ifilename = "input.txt", std::string vfilename = "vocabulary.txt"){
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
            length = line.size();
            puzzle.push_back(line);
            read = std::string{};
        }
        ifile.close();
        max = 0;
        std::ifstream vfile(vfilename);
        while(getline(vfile, read)){
            if(read.empty()) continue;
            if(read.size() > max) max = read.size();
            vocabulary.push_back(read);
        }
        vfile.close();
    }

    void print() const{
        for(const std::vector<char> &line : puzzle){
            for(const char c : line) std::cout << c << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void solve() const{
        std::string word("that");
        for(const std::vector<char> &line : puzzle){
            for(std::vector<char>::size_type i = 0; i < max; ++i){
                std::string word;
                for(std::vector<char>::size_type j = 0; j <= i; ++j){
                    word += line[j];
                }
                if(std::find(vocabulary.begin(), vocabulary.end(), word) != vocabulary.end()) std::cout << word << std::endl;
            }
        }
    }
};

int main(){
    Puzzle puzzle;
    puzzle.print();
    puzzle.solve();
    return 0;
}