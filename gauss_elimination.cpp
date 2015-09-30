#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

using namespace std;
namespace ublas = boost::numeric::ublas;

ublas::matrix<double> _matrix;

int main ()
{    
	int size;
	cout << "Enter number of unknowns: ";
	cin >> size;

	_matrix.resize(size, size, false);

	for (unsigned i = 0; i < _matrix.size1 (); ++ i)
		for (unsigned j = 0; j < _matrix.size2 (); ++ j)
		{
			cout << "Enter a" << i+1 << j+1 << " : ";
			cin >> _matrix (i, j);
		}
	
	cout << "matrix: " << endl;
	cout << _matrix ;
	
	_matrix [1] = _matrix[1] + _matrix[0];
	cout << _matrix;
}
