//
// Created by deves on 10/8/2015.
//

#include "NewtonRaphsonMethod.h"

namespace numeths
{

	NewtonRaphsonMethod::NewtonRaphsonMethod(std::function<double (double)> fx,
	                                         std::function<double (double)> f_x) :
			RootFindingMethod(fx), f_x(f_x)
	{

	}
}