#include <iostream>
#include "RootFindingMethod.h"

using namespace std;
using namespace numeths;

// Hack - Used in place of getch();
char stoppage;

double function(double x)
{
	return 3*x*x*x + 45*x*x - 23*x + 3;
}

int main()
{
    RootFindingMethod rootFindingMethod;
    rootFindingMethod.setIterationCount(10);
    cout << "Iteration Count: " << rootFindingMethod.getIterationCount() << endl;
	cin >> stoppage;
    return 0;
}