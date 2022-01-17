#pragma once
#include <iostream>
#include <string>
#include "GeneratorTasks.hpp"

class Tests
{
private:
    GeneratorTasks* generatorTasks;
    bool testPassed(std::string);
    bool testFailed(std::string);
public:
    Tests();
    ~Tests();
    bool Run();
    bool Test_Simple();
    bool Test_Big();
    bool Test_First_Algorithm();
    bool Test_Second_Algorithm();
    bool Test_First_Second_excel_table();
    bool Tests_with_add_to_csv_file();
    bool Tests_Second_Algorithm_with_add_to_csv_file();
    void setGeneratorTasks(int);

};
