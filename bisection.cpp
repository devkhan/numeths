#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#define EPSILON 0.000000000001

using namespace std;

double function(double *coeffs, int size, double x)
{
	double sum=0;
	for (int i = 0; i < size; ++i)
	{
		sum += coeffs[i]*pow(x, i);
	}
	return sum;
}

double bisection(double *coeffs, int size, double a, double b)
{
	if (abs(function(coeffs, size, (a+b)/2))<EPSILON)
	{
		return (a+b)/2;
	}
	else
	{
		if (function(coeffs, size, (a+b)/2)*function(coeffs, size, a) < 0)
			bisection(coeffs, size, a, (a+b)/2);
		else
			bisection(coeffs, size, (a+b)/2, b);
	}
}

int main(int argc, char const *argv[])
{
	string current_exec_name = argv[0]; // Name of the current exec program, not used.
	string degree;						// No of coefficients not used.
	float a, b;
	vector<string> coef;
	double *coeffs;
	coeffs = new double[argc-1];

	// Taking coefficientsfrom command line argument into double array.
	if (argc > 1)
	{
		degree = argv[1];	// Not used.
		coef.assign(argv + 1, argv + argc);
	}
	for(int i=0; i<coef.size() ;i++)
	{
		coeffs[i] = stod(coef[i], 0);
	}

	// Taking the interval limits.
	cout<<"Enter interval: ";
	cin>>a>>b;

	// Displaying equation.
	cout<<"Equation: ";
	for(int i=0; i<coef.size() ; i++)
		cout<<((coeffs[coef.size()-1-i]>0)?" + ":" - ")<<abs(coeffs[coef.size()-1-i])<<"x^"<<coef.size()-1-i;
	cout<<"\nInterval: ["<<a<<" , "<<b<<"]"<<endl;

	if (function(coeffs, coef.size(), a)*function(coeffs, coef.size(), b) > 0)
	{
		cerr<<"Interval does not contain any root!!!"<<endl<<"Aborting...";
		return 1;
	}
	else
	{
		cout<<"Approximated root: "<<bisection(coeffs, coef.size(), a, b);
		return 0;
	}
}