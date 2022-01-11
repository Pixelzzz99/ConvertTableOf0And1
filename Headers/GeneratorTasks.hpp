#pragma once
#include <vector>

class GeneratorTasks
{
private:
    const double eps = 1e-8;
    
    std::vector<std::vector<int>> matrix;
    int n, m;

    std::vector<std::vector<int>> generateMatrix(int, int);
public:
    GeneratorTasks(int);
    ~GeneratorTasks() = default;
    int getN();
    int getM();
    std::vector<std::vector<int>> getMatrix();
};
