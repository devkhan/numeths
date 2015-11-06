/**
 * Gauss Seidal Method
 * @author : Devesh Khandelwal
 */

#include <iostream>
#include <armadillo>
#include <cmath>

// Used because the double value may not be exactly zero.
// So, this is to remove almost-singular errors.
#define SINGULARITY_MARGIN 0.00001
#define ITERATION_COUNT 50

using namespace std;
using namespace arma;

/**
 * main function. Inputs a system of equations and outputs the solution
 * to that system, if exists. Uses Gauss-Seidel method.
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
		{1, 2, 3, 1},
		{4, 5, 6, 1},
		{1, 0, 1, 1}
	};

	colvec x, xi, b;

	cout << "Enter number of unknowns: ";
	cin >> vars;

	cout << "Enter number of equations: ";
	cin >> equations;

	// Resize the coef matrix
	coef_mat.resize(equations, vars+1);
	x.resize(vars);
	// Set all elements to zero
	x.zeros();
	xi.resize(vars);	
	xi.zeros();

	// Input equation coefficients. Complete augmented matrix.
	for (unsigned i = 0; i < coef_mat.n_rows ; ++i)
	{
		cout << "Enter coefficients of equation " << i+1 << " : ";
		for (unsigned j = 0; j < coef_mat.n_cols ; ++ j)
		{
			cin >> coef_mat(i, j);
		}
	}

	// Check singularity.
	if (abs(det(coef_mat.submat(0, 0, coef_mat.n_rows-1, coef_mat.n_cols-2)))<
		SINGULARITY_MARGIN)
	{
		cout << "Error: Coeffecient matrix is singular. No solution exists.";
		return EXIT_FAILURE;
	}

	// coef_mat.print("\nEquation matrix:\n");

	// Initialize the b vector with values of last column of coefficients matrix.
	b = coef_mat.col(coef_mat.n_cols-1);

	// Reducing the size of the coefficients matrix by shedding the last column.
	coef_mat.shed_col(coef_mat.n_cols-1);

	// b.print("\nAnswer vector:\n");
	// x.print("\nSolution vector:\n");

	int count=0;
	while(++count < ITERATION_COUNT)
	{
		for (int i = 0 ; i < x.n_elem ; ++i)
		{
			double tmp=0, tmpi=0;
			for (int j = 0; j < i ; ++j)
			{
				if (i!=j)
				{
					tmp = tmp + coef_mat(i, j)*xi(j);
				}
			}
			tmp *= -1;
			for (int j = i; j < coef_mat.n_cols ; ++j)
			{
				if (i!=j)
				{
					tmpi = tmpi + coef_mat(i, j)*x(j);
				}
			}
			tmpi *= -1;
			xi(i) = (tmp + tmpi + b(i))/coef_mat(i, i);
		}
		x=xi;
		//x.print("\nSolution vector at iteration " + to_string(count) + " :\n");
	}

	x.print("\nSolution vector:\n");

	return 0;
}