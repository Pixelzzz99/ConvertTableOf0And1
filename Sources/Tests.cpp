#include <ctime>
#include "Tests.hpp"
#include "FirstVersion.hpp"
#include "SecondVersion.hpp"

Tests::Tests()
{}

Tests::~Tests()
{
    delete this->generatorTasks;
}

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
    bool result = Test_Simple();
    //result = Test_Big();
    //this->setGeneratorTasks(200);
    //result = Test_First_Algorithm();
    //result = Test_Second_Algorithm();
    this->setGeneratorTasks(100);
    result = Test_Second_Algorithm();
    if(!result){
        std::cout<<"Tests Failed"<<std::endl;
        return false;
    }
    std::cout<<"Tests Passed"<<std::endl;
    return true;
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

    delete first_version;
    delete second_version;
    delete task;

    if(first_result.size() != 2 && second_result.size() != 2)
    {
        return this->testFailed(test_name);
    }

    return this->testPassed(test_name);
}

bool Tests::Test_Big()
{
    std::string test_name = "Test_Big";
    GeneratorTasks* task = new GeneratorTasks(500);
    int n = task->getN();
    int m = task->getM();
    std::vector<std::vector<int>> matrix = task->getMatrix();
    FirstAlgorithm* first_version = new FirstAlgorithm(n, m, matrix);
    SecondAlgorithm* second_version = new SecondAlgorithm(n, m, matrix);
    unsigned int start_time = clock();
    std::vector<int> first_result = first_version->solve();
    unsigned int end_time = clock();
    std::cout<<"First Algorithm Time: "<<(end_time - start_time)/double(CLOCKS_PER_SEC)<<std::endl;
    start_time = clock();
    std::vector<int> second_result = second_version->solve();
    end_time = clock();
    std::cout<<"Second Algorithm Time: "<<(end_time - start_time)/double(CLOCKS_PER_SEC)<<std::endl;

    delete first_version;
    delete second_version;
    delete task;

    if(first_result.size() > second_result.size())
    {
        return this->testFailed(test_name);
    }
    return this->testPassed(test_name);
}

void Tests::setGeneratorTasks(int number)
{
    if (this->generatorTasks != nullptr)
    {
        delete this->generatorTasks;
    }
    this->generatorTasks = new GeneratorTasks(number);
}

bool Tests::Test_First_Algorithm(){
    std::string test_name = "Test_First_Algorithm";
    int n = this->generatorTasks->getN();
    int m = this->generatorTasks->getM();
    std::vector<std::vector<int>> matrix = this->generatorTasks->getMatrix();
    FirstAlgorithm* first_version = new FirstAlgorithm(n, m, matrix);
    unsigned int start_time = clock();
    std::vector<int> first_result = first_version->solve();
    unsigned int end_time = clock();
    std::cout<<"First Algorithm Time: "<<(end_time - start_time)/double(CLOCKS_PER_SEC)<<std::endl;
    delete first_version;
    std::cout << "First Algorithm Result: " << first_result.size() << std::endl;
    if(first_result.size() > 3)
    {
        return this->testFailed(test_name);
    }
    return this->testPassed(test_name);
}

bool Tests::Test_Second_Algorithm(){
    std::string test_name = "Test_Second_Algorithm";
    int n = this->generatorTasks->getN();
    int m = this->generatorTasks->getM();
    std::vector<std::vector<int>> matrix = this->generatorTasks->getMatrix();
    SecondAlgorithm* second_version = new SecondAlgorithm(n, m, matrix);
    unsigned int start_time = clock();
    std::vector<int> second_result = second_version->solve();
    unsigned int end_time = clock();
    std::cout<<"Second Algorithm Time: "<<(end_time - start_time)/double(CLOCKS_PER_SEC)<<std::endl;
    delete second_version;
    std::cout << "Second Algorithm Result: " << second_result.size() << std::endl;
    if(second_result.size() != 3)
    {
        return this->testFailed(test_name);
    }
    return this->testPassed(test_name);
}




