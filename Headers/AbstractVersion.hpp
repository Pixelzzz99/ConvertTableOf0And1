#pragma once 
#include <vector>
#include <algorithm>

class AbstractStrategy{
    protected:
    std::vector<std::vector<int>> matrix;
    int n, m;
    int count_iterations;

    public:

    void set_n(int n);
    void set_m(int m);
    void set_matrix(std::vector<std::vector<int>> matrix);
    virtual ~AbstractStrategy(){}
    virtual std::vector<int> solve() = 0;
    double get_approximation(double time);
};
