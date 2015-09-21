#include <iostream>
#include <functional>
#include "RootFindingMethod.h"

using namespace std;
using namespace numeths;

// Hack - Used in place of getch();
char stoppage;

double fx(double x)
{
	return 3*x*x*x + 45*x*x - 23*x + 3;
}

int main()
{
	std::function<double(double)> f = fx;
    RootFindingMethod rootFindingMethod(f);
    rootFindingMethod.setIterationCount(10);
    cout << "f(10) = " << rootFindingMethod.Evaluate(10) << endl;
	cin >> stoppage;
    return 0;
}