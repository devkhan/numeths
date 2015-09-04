/**
 * Program to find root of a polynomial using Newton-Raphson method.
 *
 * @author Devesh Khandelwal
 * @created 04-09-2015
 * @modified 04-09-2015
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>

// Error tolerance of polynomial.
#define EPSILON 9.16978e-005

using namespace std;

// Number of iterations.
long iterations = 0;

// Last two iterations.
double pn = 0, pn1 = 0, pn2 = 0, error = 0;

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
 * Calcuates the approximated root in the given interval.
 * 
 * @param  a Interval start point
 * @param  b Interval end point
 * @return   x-intercept value of the secant in the given interval
 */
double x_intercept(double a, double b, double f_a, double f_b)
{
	return b - (f_b*((b-a)/(f_b-f_a)));
}

/*void calculate_error()
{
	// Check if 
	if (++iterations > 3)
	{
		error = (pn - pn1) / (pn1 - pn2);
		error = (abs(error)/abs(error-1))*abs(pn-pn1);
	}
}
*/

/**

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
		cout<<"Approximated root: "<<root(coefficients, arguments.size(), a, b)<<endl;
		cout<<"Iterations: "<<iterations<<endl;
		return 0;
	}
}