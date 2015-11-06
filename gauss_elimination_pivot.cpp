/**
 * Gaussian Elimination using pivoting.
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
 * main function. Inputs a system of equations and outputs the solution to that
 * system, if exists. Uses pivoting.
 * @param  argc Number of command line arguments.
 * @param  argv Command line arguments.
 * @return      Exit Status.
 */
int main(int argc, char** argv)
{
	int vars, equations;

	mat aug_mat = {
		{1, 2, 3, 1},
		{4, 5, 6, 1},
		{1, 0, 1, 1}
	};

	cout << "Enter number of unknowns: ";
	cin >> vars;

	cout << "Enter number of equations: ";
	cin >> equations;

	aug_mat.resize(equations, vars+1);
	
	// Input equation coefficients. Complete augmented matrix.
	for (unsigned i = 0; i < aug_mat.n_rows ; ++i)
	{
		cout << "Enter equation " << i+1 << " : ";
		for (unsigned j = 0; j < aug_mat.n_cols ; ++ j)
		{
			cin >> aug_mat(i, j);
		}
	}

	// Check singularity.
	if (abs(det(aug_mat.submat(0, 0, aug_mat.n_rows-1, aug_mat.n_cols-2)))<
		SINGULARITY_MARGIN)
	{
		cout << "Error: Coeffecient matrix is singular. No solution exists.";
		return EXIT_FAILURE;
	}

	// aug_mat.print("\nAugmented matrix before pivoting:\n");

	for (int i = 0; i < aug_mat.n_cols-1; ++i)
	{
		uword r;
		aug_mat.col(i).max(r);
		aug_mat.swap_rows(r, i);
	}

	// aug_mat.print("\nAugmented matrix after pivoting:\n");

	// aug_mat.print("\nAugmented matrix before elimination:\n");

	for (int i = 0; i < aug_mat.n_rows-1; ++i)
	{
		
		for (int j = i+1; j < aug_mat.n_rows; ++j)
		{
			double ratio = aug_mat(j, i)/aug_mat(i, i);
			aug_mat.row(j) = aug_mat.row(j) - ratio*aug_mat.row(i);
		}
	}

	// aug_mat.print("\nAugmented matrix after lower elimination:\n");

	for (int i = aug_mat.n_rows-1; i > 0; --i)
	{
		for (int j = i-1; j >= 0; --j)
		{
			double ratio = aug_mat(j, i)/aug_mat(i, i);
			aug_mat.row(j) = aug_mat.row(j) - ratio*aug_mat.row(i);
		}
	}

	// aug_mat.print("\nAugmented matrix after upper elimination:\n");

	vec b = aug_mat.col(aug_mat.n_cols-1)/aug_mat.diag();

	b.print("\nSolutions:\n");

	return 0;
}