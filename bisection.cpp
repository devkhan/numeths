/**
 * Program to find root of a polynomial using Bisection method.
 *
 * @author Devesh Khandelwal
 * @created 21-08-2015
 * @modified 27-08-2015
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
double bisection(double *coefficients, int size, double a, double b)
{
	cout<<"\nIteration: "<<++iterations<<", Error: "<<(a+b)/2-a<<endl;
	if (abs(polynomial(coefficients, size, (a+b)/2))<EPSILON)
	{
		return (a+b)/2;
	}
	else
	{
		if (polynomial(coefficients, size, (a+b)/2)*polynomial(coefficients, size, a) < 0)
			bisection(coefficients, size, a, (a+b)/2);
		else
			bisection(coefficients, size, (a+b)/2, b);
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
	float a, b;
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
	cout<<"Enter interval: ";
	cin>>a>>b;

	// Displaying equation.
	cout<<"Equation: ";
	for(int i=0; i<arguments.size() ; i++)
		cout<<((coefficients[arguments.size()-1-i]>0)?" + ":" - ")<<abs(coefficients[arguments.size()-1-i])<<"x^"<<arguments.size()-1-i;

	cout<<"\nInterval: ["<<a<<" , "<<b<<"]"<<endl;

	if (polynomial(coefficients, arguments.size(), a)*polynomial(coefficients, arguments.size(), b) > 0)
	{
		cerr<<"Interval does not contain any root!!!"<<endl<<"Aborting...";
		return 1;
	}
	else
	{
		cout<<"Calculating roots..."<<endl;
		cout<<"Approximated root: "<<bisection(coefficients, arguments.size(), a, b)<<endl;
		cout<<"Iterations: "<<iterations<<endl;
		return 0;
	}
}