#include "FirstVersion.hpp"

FirstAlgorithm::FirstAlgorithm(int n, int m, std::vector<std::vector<int>> matrix)
{
    this->n = n;
    this->m = m;
    this->matrix = matrix;
}

std::vector<int> FirstAlgorithm::solve()
{
    std::vector<int> result;
    if (this->n < this->m)
    {
        result = this->solve1();
    }
    else
    {
        result = this->solve2();
    }
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

std::vector<int> FirstAlgorithm::solve2()
{
    int INF = 1e9;
    std::vector<std::vector<int>> dp(this->n + 1);
    std::vector<std::vector<int>> from(this->n + 1);
    std::vector<int> MASK(this->n);
    for (int i = 0; i < this->n; i++)
    {
        int res = 0;
        for (int j = 0; j < this->m; j++)
        {
            if (matrix[i][j]) res += (1 << j);
        }
        MASK[i] = res;
    }

    for (int i = 0; i <= this->n; i++)
    {
        dp[i].resize(1 << this->m);
        from[i].resize(1 << this->m);
        for (int mask = 0; mask < (1 << this->m); mask++)
        {
            dp[i][mask] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= this->n; i++)
    {
        for (int mask = 0; mask < (1 << this->m); mask++)
        {
            dp[i][mask] = dp[i - 1][mask];
            from[i][mask] = mask;
        }
        for (int mask = 0; mask < (1 << this->m); mask++)
        {
            if (dp[i - 1][mask] != INF)
            {
                int newMask = (mask | MASK[i - 1]);
                if (dp[i][newMask] > dp[i - 1][mask] + 1)
                {
                    dp[i][newMask] = dp[i - 1][mask] + 1;
                    from[i][newMask] = mask;
                }
            }
        }
    }
    std::vector<int> result;
    int mask = (1 << this->m) - 1;
    int id = this->n;
    if(dp[n][mask] != INF)
    {
        while(id > 0)
        {
            if(from[id][mask] != mask)
            {
                result.push_back(id);
            }
            mask = from[id][mask];
            id--;
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}
