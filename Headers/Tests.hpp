#pragma once
#include <iostream>
#include <string>

class Tests
{
private:
    bool testPassed(std::string);
    bool testFailed(std::string);
public:
    Tests();
    ~Tests()=default;
    bool Run();
    bool Test_Simple();
    bool Test_First_Algorithm();
    bool Test_Second_Algorithm();
    bool Test_First_Second_excel_table();
};
