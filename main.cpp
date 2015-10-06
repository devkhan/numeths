#include <iostream>
#include <functional>
#include "RegulaFalsiMethod.h"

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
    RegulaFalsiMethod bisectionMethod(f, -16.0, -15.0);
	bisectionMethod.Solve();
    cout << "Root = " << bisectionMethod.Root() << endl;
	cout << "Error = " << bisectionMethod.CalculateError() << endl;
	cin >> stoppage;
    return 0;
}