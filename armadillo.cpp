#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;
int main(int argc, char** argv)
{
mat A = randu<mat>(5,5);
mat B = randu<mat>(5,5);
cout << B.t() << endl;
// cout << A*B << endl;
cout<<"Check."<<endl;
return 0;
}
