#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;
int main(int argc, char** argv)
{
mat A = randu<mat>(2,2);
mat B = randu<mat>(2,2);
cout << A << endl;
cout << B << endl;
cout << eye(2,2)*eye(2,2) << endl;
cout<<"Check."<<endl;
return 0;
}
