#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

using namespace std;
namespace ublas = boost::numeric::ublas;

ublas::matrix<double> _matrix;

int main ()
{    
	int vars, equations;

	cout << "Enter number of unknowns: ";
	cin >> vars;

	cout << "Enter number of equations: ";
	cin >> equations;

	_matrix.resize(equations, vars+1, false);

	for (unsigned i = 0; i < _matrix.size1 (); ++ i)
		for (unsigned j = 0; j < _matrix.size2 (); ++ j)
		{
			cout << "Enter a" << i+1 << j+1 << " : ";
			cin >> _matrix (i, j);
		}
	
	cout << "matrix: " << endl;
	cout << _matrix ;

	for (int col = 0; col < _matrix.size2()-1 ; ++col)
	{
		
		for (int row = row; row < _matrix.size1() ; ++row)
		{
			int ratio = _matrix(row, col) / _matrix(col, col);
			for (int lower_col = col; lower_col < _matrix.size2(); ++lower_col)
			{
				_matrix(row, lower_col) = _matrix(row, lower_col) - ratio*_matrix(col, lower_col);
			}
		}
	}

	cout << "Lower triangle zero matrix: " << endl;
	cout << _matrix ;
	
}
