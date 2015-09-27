#include <iostream>
#include <functional>
#include "BisectionMethod.h"

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
    BisectionMethod bisectionMethod(f, -16.0, -15.0);
	bisectionMethod.Solve();
    cout << "Root = " << bisectionMethod.Root() << endl;
    return 0;
}