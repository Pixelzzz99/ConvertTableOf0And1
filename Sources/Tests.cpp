#include "Tests.hpp"
#include "GeneratorTasks.hpp"
#include "FirstVersion.hpp"
#include "SecondVersion.hpp"

Tests::Tests()
{}

bool Tests::testPassed(std::string test_name)
{
    std::cout<<"Test Passed: "<<test_name<<std::endl;
    return true;
}

bool Tests::testFailed(std::string test_name)
{
    std::cout<<"Test Failed: "<<test_name<<std::endl;
    return false;
}


bool Tests::Run(){
    std::cout<<"Running Tests"<<std::endl;
    bool result = False;

    return testPassed("Tests");
}

bool Tests::Test_Simple()
{
    std::string test_name = "Test_Simple";
    GeneratorTasks* task = new GeneratorTasks(40);
    int n = task->getN();
    int m = task->getM();
    std::vector<std::vector<int>> matrix = task->getMatrix();

    FirstAlgorithm* first_version = new FirstAlgorithm(n, m, matrix);
    SecondAlgorithm* second_version = new SecondAlgorithm(n, m, matrix);
    std::vector<int> first_result = first_version->solve();
    std::vector<int> second_result = second_version->solve();

    if(first_result.size() != 2 && second_result.size() != 2)
    {
        return this->testFailed(test_name);
    }

    return this->testPassed(test_name);
}

bool Tests::Test_Big()
{
    std::string test_name = "Test_Big";
    GeneratorTasks* task = new GeneratorTasks(100);
    int n = task->getN();
    int m = task->getM();
    std::vector<std::vector<int>> matrix = task->getMatrix();

    FirstAlgorithm* first_version = new FirstAlgorithm(n, m, matrix);
    SecondAlgorithm* second_version = new SecondAlgorithm(n, m, matrix);
    std::vector<int> first_result = first_version->solve();
    std::vector<int> second_result = second_version->solve();

    if(first_result.size() != 2 && second_result.size() != 2)
    {
        return this->testFailed(test_name);
    }

    return this->testPassed(test_name);
}

