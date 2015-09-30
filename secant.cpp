/**
 * Program to find root of a polynomial using Bisection method.
 *
 * @author Devesh Khandelwal
 * @created 28-09-2015
 * @modified 28-09-2015
 */

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

// Error tolerance of polynomial.
#define EPSILON 0.000000000001

using namespace std;

// Number of iterations.
long iterations = 0;

/**
 * Calculates the polynomial value.
 * 
 * @param  coefficients Array of coefficients
 * @param  size         Order of equation
 * @param  x            Value to calculate, independent variable
 * @return              Polynomial value, dependent variable
 */
double polynomial(double *coefficients, int size, double x)
{
	double sum=0;
	for (int i = 0; i < size; ++i)
	{
		sum += coefficients[i]*pow(x, i);
	}
	return sum;
}

/**
 * Find root in a given interval.
 * 
 * @param  coefficients Array of coefficients
 * @param  size         Order of equation
 * @param  a            Interval start
 * @param  b            Interval end
 * @return              Root of polynomial, if found
 */
double secant(double *coefficients, int size, double x0, double x1)
{
	iterations++;
	if (abs(polynomial(coefficients, size, x1))<EPSILON)
	{
		return x1;
	}
	else
	{
		return secant(coefficients, size, x1, x1 - (polynomial(coefficients, size, x1)*(x1-x0))/(polynomial(coefficients, size, x1)-polynomial(coefficients, size, x0)));
	}
}

/**
 * main function. Takes coefficients of a polynomial equation as command line arguments in increasinig polynomial degree.
 * @param  argc Number of arguments
 * @param  argv Arguments
 * @return      Status code.
 */
int main(int argc, char const *argv[])
{

	string degree;						// No of coefficients not used.
	double x0, x1;
	vector<string> arguments;
	double *coefficients;
	coefficients = new double[argc-1];

	// Taking coefficientsfrom command line argument into double array.
	if (argc > 1)
	{
		degree = argv[1];	// Not used.
		arguments.assign(argv + 1, argv + argc);
	}
	for(int i=0; i<arguments.size() ;i++)
	{
		coefficients[i] = stod(arguments[i], 0);
	}

	// Taking the interval limits.
	cout<<"Enter x0 and x1: ";
	cin>>x0>>x1;

	// Displaying equation.
	cout<<"Equation: ";
	for(int i=0; i<arguments.size() ; i++)
		cout<<((coefficients[arguments.size()-1-i]>0)?" + ":" - ")<<abs(coefficients[arguments.size()-1-i])<<"x^"<<arguments.size()-1-i;

	{
		cout<<endl;
		cout<<"Calculating roots..."<<endl;
		cout<<"Approximated root: "<<secant(coefficients, arguments.size(), x0, x1)<<endl;
		cout<<"Iterations: "<<iterations<<endl;
		return 0;
	}
}