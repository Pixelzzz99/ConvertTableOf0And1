#include <cmath>
#include <cstdlib>
#include "GeneratorTasks.hpp"

GeneratorTasks::GeneratorTasks(int test)
{
    this->n = (int)sqrt(test + eps);
    this->m = test / n;
    this->matrix = generateMatrix(n, m);
}

std::vector<std::vector<int>> GeneratorTasks::generateMatrix(int n, int m)
{
    std::vector<std::vector<int>> matrix(n + 1);
    for (int i = 0; i < n; i++)
    {
        matrix[i].resize(m + 1);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }
    return matrix;
}

int GeneratorTasks::getN()
{
    return this->n;
}

int GeneratorTasks::getM()
{
    return this->m;
}

std::vector<std::vector<int>> GeneratorTasks::getMatrix()
{
    return this->matrix;
}

