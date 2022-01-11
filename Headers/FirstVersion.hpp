#pragma once
#include "AbstractVersion.hpp"

class FirstAlgorithm : public AbstractStrategy
{
    private:
    std::vector<int> solve1();

    public:
    FirstAlgorithm(int, int, std::vector<std::vector<int>>);
    ~FirstAlgorithm() = default;
    std::vector<int> solve() override;
};