#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main(int argc, char** argv)
{
	int vars, equations;

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

	for (unsigned i = 0; i < coef_mat.n_rows ; ++i)
	{
		cout << "Enter coefficients of equation " << i+1 << " : ";
		for (unsigned j = 0; j < coef_mat.n_cols ; ++ j)
		{
			cin >> coef_mat(i, j);
		}
	}

	coef_mat.print("\nEquation matrix:\n");

	b = coef_mat.col(coef_mat.n_cols-1);
	coef_mat.shed_col(coef_mat.n_cols-1);
	l.eye();
	u = coef_mat;

	coef_mat.print("\nCoefficient matrix:\n");

	b.print("\nAnswer vector:\n");
	l.print("\nLower triangular matrix before elimination:\n");
	u.print("\nUpper triangular matrix before elimination:\n");

	for (int i = 0; i < coef_mat.n_rows-1; ++i)
	{
		
		for (int j = i+1; j < coef_mat.n_rows; ++j)
		{
			double ratio = u(j, i)/u(i, i);
			u.row(j) = u.row(j) - ratio*u.row(i);
			l(j, i) = ratio;
		}
	}

	l.print("\nLower triangular matrix after elimination:\n");
	u.print("\nUpper triangular matrix after elimination:\n");

	y = (l.i())*b;

	y.print("\n y vector:\n");

	x = (u.i())*y;

	x.print("\n x vector:\n");
	return 0;
}