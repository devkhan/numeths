#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

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

	for (unsigned i = 0; i < aug_mat.n_rows ; ++i)
	{
		cout << "Enter equation " << i+1 << " : ";
		for (unsigned j = 0; j < aug_mat.n_cols ; ++ j)
		{
			cin >> aug_mat(i, j);
		}
	}


	aug_mat.print("\nAugmented matrix before pivoting:\n");

	for (int i = 0; i < aug_mat.n_cols-1; ++i)
	{
		uword r;
		aug_mat.col(i).max(r);
		cout<<r<<i<<endl;
		aug_mat.swap_rows(r, i);
	}

	aug_mat.print("\nAugmented matrix after pivoting:\n");

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

	vec b = aug_mat.col(aug_mat.n_cols-1)/aug_mat.diag();

	b.print("\nSolutions:\n");

	return 0;
}