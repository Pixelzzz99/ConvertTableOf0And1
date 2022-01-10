#include <iostream>
#include "FirstVersion.hpp"
#include "SecondVersion.hpp"

int main()
{
    std::vector<std::vector<int>> matrix = {
        {0, 0, 1, 1, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 0, 1}
    };
    FirstAlgorithm *firstAlgorithm = new FirstAlgorithm(4, 5, matrix);
    SecondAlgorithm *secondAlgorithm = new SecondAlgorithm(4, 5, matrix);
    std::vector<int> result = secondAlgorithm->solve();

    if (result.empty())
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << result.size() << std::endl;
        for (int x : result)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}