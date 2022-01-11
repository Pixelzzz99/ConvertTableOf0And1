#pragma once
#include "AbstractVersion.hpp"

class SecondAlgorithm : public AbstractStrategy
{
    public:
    SecondAlgorithm(int, int, std::vector<std::vector<int>>);
    ~SecondAlgorithm() = default;
    std::vector<int> solve() override;
};