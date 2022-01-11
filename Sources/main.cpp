#include <iostream>
#include "FirstVersion.hpp"
#include "SecondVersion.hpp"
#include "GeneratorTasks.hpp"
#include "Tests.hpp"

int main()
{
    std::vector<std::vector<int>> matrix = {
        {0, 0, 1, 1, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 0, 1}};
    GeneratorTasks *task = new GeneratorTasks(40);
    int n = task->getN();
    int m = task->getM();
    std::vector<std::vector<int>> matrix1 = task->getMatrix();
    // Show matrix
    /*std::cout<<n<<" "<<m<<std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix1[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
    FirstAlgorithm *firstAlgorithm = new FirstAlgorithm(n, m, matrix1);
    SecondAlgorithm *secondAlgorithm = new SecondAlgorithm(n, m, matrix1);
    std::vector<int> result = firstAlgorithm->solve();
    //Show result
    /*std::cout << "Result: ";
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
    }*/
    Tests *tests = new Tests();
    tests->Run();
    return 0;
}
