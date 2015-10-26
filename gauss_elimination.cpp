#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main(int argc, char** argv)
{
	int vars, equations;

	mat aug_mat

	cout << "Enter number of unknowns: ";
	cin >> vars;

	cout << "Enter number of equations: ";
	cin >> equations;

	aug_mat.resize(equations, vars+1);

	for (unsigned i = 0; i < aug_mat.n_rows ; ++i)
		for (unsigned j = 0; j < aug_mat.n_cols-1 ; ++ j)
		{
			cout << "Enter a" << i+1 << j+1 << " : ";
			cin >> aug_mat(i, j);
		}


	aug_mat.print("\nAugmented matrix before elimination:\n");

	for (int i = 0; i < aug_mat.n_rows-1; ++i)
	{
		
		for (int j = i+1; j < aug_mat.n_rows; ++j)
		{
			double ratio = aug_mat(j, i)/aug_mat(i, i);
			aug_mat.row(j) = aug_mat.row(j) - ratio*aug_mat.row(i);
		}
	}

	aug_mat.print("\nAugmented matrix after lower elimination:\n");

	for (int i = aug_mat.n_rows-1; i > 0; --i)
	{
		for (int j = i-1; j >= 0; --j)
		{
			double ratio = aug_mat(j, i)/aug_mat(i, i);
			aug_mat.row(j) = aug_mat.row(j) - ratio*aug_mat.row(i);
		}
	}

	aug_mat.print("\nAugmented matrix after upper elimination:\n");

	vec b = aug_mat.diag();

	b.print("\nSolutions:\n");

	return 0;
}