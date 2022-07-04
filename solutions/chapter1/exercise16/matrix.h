#ifndef MATRIX_H
#define MATRIX_H

#include <cstdlib>
#include <vector>
#include <iostream>

template<typename Object>
class Matrix
{
public:
    explicit Matrix(const std::size_t rows = 0, const std::size_t columns = 0) : array{rows}
    {
        for(std::vector<Object> &thisRow : array)
        {
            resize(thisRow, columns);
        }
    }

    explicit Matrix(const std::vector<std::vector<Object>> v) : array{v} {}

    explicit Matrix(const std::vector<std::vector<Object>> &&v) : array{std::move(v)} {}

    const std::vector<Object> & operator[](std::size_t row) const
    {
        return array[row];
    }

    std::vector<Object> & operator[](std::size_t row)
    {
        return array[row];
    }

    std::size_t rowCount() const
    {
        return array.size();
    }

    std::size_t columnCount() const
    {
        return rowCount() ? array[0].size() : 0;
    }

    void print() const
    {
        std::cout << "================================" << std::endl;
        std::cout << "[ROWS] \t\t: " << rowCount() << std::endl;
        std::cout << "[COLUMNS] \t: " << columnCount() << std::endl;
        std::cout << "================================" << std::endl;        
        for(const std::vector<Object> &row : array)
        {
            std::cout << "[ \t";
            for(const Object &elem : row)
            {
                std::cout << elem << " \t";
            }
            std::cout << "]" << std::endl;
        }
        std::cout << "================================" << std::endl;
        std::cout << std::endl;

    }

    void randomize()
    {
        for(std::vector<Object> &row : array)
        {
            for(Object &elem : row)
            {
                elem = getRandom(10);
            }
        }
    }

private:
    std::vector<std::vector<Object>> array;

    Object getRandom(Object max)
    {
        return rand() % max;
    }

    void resize(std::vector<Object> &row, std::size_t columns)
    {
        for(std::size_t idx = 0; idx < columns; ++idx)
        {
            row.push_back(Object{});
        }
    }

};

#endif