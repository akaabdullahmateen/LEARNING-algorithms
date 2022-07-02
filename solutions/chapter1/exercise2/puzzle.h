#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>
#include <string>

class Puzzle{
private:
    std::vector<std::vector<char>> puzzle;
    std::vector<std::string> vocabulary;

public:
    Puzzle(std::string ifilename = "input.txt", std::string vfilename = "vocabulary.txt");
    void print() const;
    void solve() const;
};

#endif