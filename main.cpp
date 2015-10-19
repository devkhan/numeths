#include <iostream>
#include <functional>
#include "RegulaFalsiMethod.h"
#include "NewtonRaphsonMethod.h"

using namespace std;
using namespace numeths;

// Hack - Used in place of getch();
char stoppage;

double fx(double x)
{
	return 3*x*x*x + 45*x*x - 23*x + 3;
}

double f_x(double x)
{
    return 9*x*x + 90*x - 23;
}

int main()
{
	std::function<double(double)> f = fx;
    std::function<double(double)> dfx = f_x;
    NewtonRaphsonMethod bisectionMethod(f, dfx, -15.0);
	bisectionMethod.Solve();
    cout << "Root = " << bisectionMethod.Root() << endl;
	cout << "Error = " << bisectionMethod.CalculateError() << endl;
	cin >> stoppage;
    return 0;
}