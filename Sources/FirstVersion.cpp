#include "FirstVersion.hpp"

FirstAlgorithm::FirstAlgorithm(int n, int m, std::vector<std::vector<int>> matrix)
{
    this->n = n;
    this->m = m;
    this->matrix = matrix;
}

std::vector<int> FirstAlgorithm::solve()
{
    std::vector<int> result = this->solve1();;
    return result;
}

std::vector<int> FirstAlgorithm::solve1()
{
    int mnAns = this->n + 1;
    int ansMask = -1;
    for (int mask = 0; mask < (1 << this->n); mask++)
    {
        int cntBitsMask = __builtin_popcount(mask);
        std::vector<bool> used(this->m);
        int cntBits = 0;
        for (int i = 0; i < this->n; i++)
        {
            if (mask & (1 << i))
            {
                for(int j=0; j < m; j++)
                {
                    if(matrix[i][j] && !used[j])
                    {
                        used[j] = true;
                        cntBits++;
                    }
                }
            }
        }
        if (cntBits == this->m && cntBitsMask < mnAns)
        {
            mnAns = cntBitsMask;
            ansMask = mask;
        }
    }

    std::vector<int> result;
    if(ansMask != -1)
    {
        for(int i = 0; i < this->n; i++)
        {
            if(ansMask & (1 << i))
            {
                result.push_back(i + 1);
            }
        }
    }
    return result;
}
