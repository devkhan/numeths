//
// Created by deves on 10/8/2015.
//

#ifndef NUMETHS_NEWTONRAPHSONMETHOD_H
#define NUMETHS_NEWTONRAPHSONMETHOD_H

#include "RootFindingMethod.h"

namespace numeths
{
	class NewtonRaphsonMethod : RootFindingMethod
	{
			std::function<double(double)> f_x;
            double x;

		public:
			NewtonRaphsonMethod(std::function<double(double)> fx, std::function<double(double)> f_x,
                                    double x0);
	};
}

#endif //NUMETHS_NEWTONRAPHSONMETHOD_H
