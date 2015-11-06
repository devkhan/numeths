/**
 * C++ code for LU Decomposition Method
 * @author : Devesh Khandelwal
 */

#include <iostream>
#include <armadillo>
#include <cmath>

// Used because the double value may not be exactly zero.
// So, this is to remove almost-singular errors.
#define SINGULARITY_MARGIN 0.00001

using namespace std;
using namespace arma;

/**
 * main function. Inputs a system of equations and outputs the solution
 * to that system, if exists. Uses LU decomposition method.
 * 
 * @param  argc Number of command line arguments.
 * @param  argv Command line arguments.
 * @return      Exit Status.
 * 
 */
int main(int argc, char** argv)
{
	int vars, equations;

	// Default system if nothing is provided.
	mat coef_mat = {
		{1, 2, 3},
		{4, 5, 6},
		{1, 0, 1}
	};

	mat l(size(coef_mat)), u(size(coef_mat));
	colvec b, x, y;


	cout << "Enter number of unknowns: ";
	cin >> vars;

	cout << "Enter number of equations: ";
	cin >> equations;

	coef_mat.resize(equations, vars+1);

	// Input equation coefficients. Complete augmented matrix.
	for (unsigned i = 0; i < coef_mat.n_rows ; ++i)
	{
		cout << "Enter coefficients of equation " << i+1 << " : ";
		for (unsigned j = 0; j < coef_mat.n_cols ; ++ j)
		{
			cin >> coef_mat(i, j);
		}
	}

	// coef_mat.print("\nEquation matrix:\n");

	// Check singularity.
	if (abs(det(coef_mat.submat(0, 0, coef_mat.n_rows-1, coef_mat.n_cols-2)))<
		SINGULARITY_MARGIN)
	{
		cout << "Error: Coeffecient matrix is singular. No solution exists.";
		return EXIT_FAILURE;
	}

	// Initialize the b vector with values of last column of coefficients matrix.
	b = coef_mat.col(coef_mat.n_cols-1);

	// Reducing the size of the coefficients matrix by shedding the last column.
	coef_mat.shed_col(coef_mat.n_cols-1);

	// 	set elements along main diagonal to one and off-diagonal elements to zero.
	// 	Identity matrix
	l.eye();
	u = coef_mat;

	// coef_mat.print("\nCoefficient matrix:\n");

	// b.print("\nAnswer vector:\n");
	// l.print("\nLower triangular matrix before elimination:\n");
	// u.print("\nUpper triangular matrix before elimination:\n");

	for (int i = 0; i < coef_mat.n_rows-1; ++i)
	{
		
		for (int j = i+1; j < coef_mat.n_rows; ++j)
		{
			double ratio = u(j, i)/u(i, i);

			// Upper triangular matrix(U) by applyring elementary row operations.
			u.row(j) = u.row(j) - ratio*u.row(i);

			// Getting Lower triangular matrix(L) from Identity matrix
			l(j, i) = ratio;
		}
	}

	// l.print("\nLower triangular matrix after elimination:\n");
	// u.print("\nUpper triangular matrix after elimination:\n");

	// 'b' is B vector for 'y' // AX=B
	y = (l.i())*b;

	// y.print("\n y vector:\n");

	// 'y' is B vector for 'x'
	x = (u.i())*y;

	x.print("\nSolution vector:\n");
	return 0;
}