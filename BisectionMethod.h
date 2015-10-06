//
// Created by deves on 9/11/2015.
//

#ifndef NUMETHS_BISECTIONMETHOD_H
#define NUMETHS_BISECTIONMETHOD_H

#include "RootFindingMethod.h"

namespace numeths
{
    class BisectionMethod : public RootFindingMethod
    {

        private:
            double A, B;
            double c;

        public:

            BisectionMethod(std::function<double(double)>, double, double);

		    bool Solve();

		    bool ShouldContinue();

		    double Root();

		    double CalculateError();
    };
}

#endif //NUMETHS_BISECTIONMETHOD_H
