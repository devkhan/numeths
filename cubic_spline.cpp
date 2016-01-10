#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main(int argc, char const *argv[])
{
	
	colvec x = {
		300,
		400,
		500,
		600,
		700,
		800,
		900,
		1000,
		1100
	};

	x.print();
	colvec a = {
		24,
		35,
		46,
		58,
		67,
		83,
		97,
		111,
		125
	};
	a = a/1000;

	a.print();
	colvec h, b, c, d;

	h = {
		100, 100, 100, 100, 100, 100, 100, 100
	};

	c.resize(x.n_elem);

	mat matrix = randu<mat>(a.n_elem, a.n_elem);

cout<<"Loop start"<<endl;

	matrix.print("\n Matrix: \n");
	for (int i = 1; i < matrix.n_rows; ++i)
	{
		for (int j = 1; j < matrix.n_cols; ++j)
		{
			if (i==1)
			{
				matrix(1, 1) = 3*h(i-1) + 2*h(i) + h(i-1)*h(i-1)/h(i);
				matrix(1, 2) = h(i) - h(i-1)*h(i-1)/h(i);
				c(1) = 3*(a(2)-a(1))/h(1) - 3*(a(1)-a(0))/h(0);
			}
			else
			{
				matrix(i-1, j-1) = h(i-2) - (h(i-1)*h(i-1))/h(i-2);
				matrix(i-1, j) = 3*h(i-1) + 2*h(i-2) + h(i-1)*h(i-1)/h(i-2);
				c(i-1) = 3*(a(i)-a(i-1))/h(i-1) - 3*(a(i)-a(i-2))/h(i-2);
			}
			cout<<i<<j<<endl;
		}
	}

	matrix.print("\n Matrix: \n");
	return 0;
}