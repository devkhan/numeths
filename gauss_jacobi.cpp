#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;


int main(int argc, char** argv)
{
	int vars, equations;

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

	coef_mat.resize(equations, vars+1);
	x.resize(vars);
	x.zeros();
	xi.resize(vars);
	xi.zeros();

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

	b.print("\nAnswer vector:\n");
	x.print("\nSolution vector:\n");

	int count=0;
	while(++count < 50)
	{
		for (int i = 0 ; i < x.n_elem ; ++i)
		{
			double tmp=0;
			for (int j = 0; j < coef_mat.n_cols ; ++j)
			{
				if (i!=j)
				{
					tmp = tmp + -1*coef_mat(i, j)*x(j);
				}
			}
			tmp += b(i);
			xi(i) = tmp/coef_mat(i, i);
		}
		x=xi;
		//x.print("\nSolution vector at iteration " + to_string(count) + " :\n");
	}

	x.print("\nSolution vector:\n");

	return 0;
}