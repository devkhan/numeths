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
 * Calculates the derivative of the polynomial.
 * 
 * @param  coefficients Array of coefficients
 * @param  size         Order of equation
 * @param  x            Value to calculate, independent variable
 * @return              Polynomial's derivative value, dependent variable
 */
double derivative(double *coefficients, int size, double x)
{
	double sum=0;
	for (int i = 1; i < size; ++i)
	{
		sum += coefficients[i]*i*pow(x,i-1);
	}
	return sum;
}

/**
 * Find root using an initial approximation.
 * 
 * @param  coefficients Array of coefficients
 * @param  size         Order of equation
 * @param  x            Initial approximation
 * @return              Approximated root
 */
double newton_raphson(double *coefficients, int size, double x)
{
	if (polynomial(coefficients, size, x)<EPSILON)
	{
		return x;
	}
	else
		return newton_raphson(coefficients, size, x - polynomial(coefficients, size, x)/derivative(coefficients, size, x));
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
	float x;
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
	cout<<"Enter initial approximation: ";
	cin>>x;

	// Displaying equation.
	cout<<"Equation: ";
	for(int i=0; i<arguments.size() ; i++)
		cout<<((coefficients[arguments.size()-1-i]>0)?" + ":" - ")<<abs(coefficients[arguments.size()-1-i])<<"x^"<<arguments.size()-1-i;

	//cout<<"\nInterval: ["<<a<<" , "<<b<<"]"<<endl;
	{
		cout<<"Calculating roots..."<<endl;
		cout<<"Approximated root: "<<newton_raphson(coefficients, arguments.size(), x)<<endl;
		// cout<<"Iterations: "<<iterations<<endl;
		return 0;
	}
}