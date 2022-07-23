#include <cstdlib>
#include <ctime>

#include "matrix.h"

int main()
{
    std::srand(std::time(NULL));
    std::size_t rows = 3;
    std::size_t columns = 3;
    Matrix<int> matrix(rows, columns);
    matrix.print();
    matrix.randomize();
    matrix.print();
    return 0;
}