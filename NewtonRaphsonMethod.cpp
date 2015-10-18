//
// Created by deves on 10/8/2015.
//

#include "NewtonRaphsonMethod.h"
#include "BisectionMethod.h"

namespace numeths
{

	NewtonRaphsonMethod::NewtonRaphsonMethod(std::function<double(double)> fx, std::function<double(double)> f_x,
                            double x0) :
			RootFindingMethod(fx), f_x(f_x)
	{
        this->setTolerance(0.0000000001);
        this->setIterationCount(50);
        this->MODE = ITERATION;
	}


    bool BisectionMethod::Solve()
    {
        do
        {
            c = (A+B)/2;
            _iterations.push_back(*(new Iteration(c, Evaluate(c), CalculateError())));
            (Evaluate(c)*Evaluate(A)<0) ? B = c : A = c;
        }while (ShouldContinue());
        return true;
    }

    bool BisectionMethod::ShouldContinue()
    {
        switch (MODE)
        {
            case TOLERANCE:
                if (_iterations[_iterations.size()-1].Residual < Tolerance)
                {
                    return false;
                }
                else
                {
                    return true;
                }

            case ITERATION:
                if (_iterations.size() == IterationCount)
                {
                    return false;
                }
                else
                {
                    return true;
                }
        }
    }

    double BisectionMethod::Root()
    {
        return (A + B) / 2;
    }

    double BisectionMethod::CalculateError()
    {
        return (B-A)/2;
    }
}