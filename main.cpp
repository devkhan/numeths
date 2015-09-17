#include <iostream>
#include "RootFindingMethod.h"

using namespace std;
using namespace numeths;

int main()
{
    RootFindingMethod rootFindingMethod;
    rootFindingMethod.setIterationCount(10);
    cout << "Iteration Count: " << rootFindingMethod.getIterationCount() << endl;
    return 0;
}