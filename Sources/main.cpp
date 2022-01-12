#include <iostream>
#include <cstdlib>
#include "FirstVersion.hpp"
#include "SecondVersion.hpp"
#include "GeneratorTasks.hpp"
#include "Tests.hpp"

int main()
{
    srand(1);
    Tests *tests = new Tests();
    tests->Run();
    return 0;
}
