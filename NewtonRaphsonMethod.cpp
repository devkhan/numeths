//
// Created by deves on 10/8/2015.
//

#include <cmath>
#include "NewtonRaphsonMethod.h"
#include "BisectionMethod.h"

namespace numeths
{

	NewtonRaphsonMethod::NewtonRaphsonMethod(std::function<double(double)> fx, std::function<double(double)> f_x,
                            double x0) :
			RootFindingMethod(fx), f_x(f_x), x(x0)
	{
        this->setTolerance(0.0000000001);
        this->setIterationCount(50);
        this->MODE = ITERATION;
	}


    bool NewtonRaphsonMethod::Solve()
    {
        do
        {
            x = x - Evaluate(x)/EvalurateDerivative(x);
            _iterations.push_back(*(new Iteration(x, Evaluate(x), CalculateError())));
        }while (ShouldContinue());
        return true;
    }

    bool NewtonRaphsonMethod::ShouldContinue()
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

    double NewtonRaphsonMethod::Root()
    {
        return x - Evaluate(x)/EvalurateDerivative(x);
    }

    double NewtonRaphsonMethod::CalculateError()
    {
        return std::abs(Evaluate(x)/EvalurateDerivative(x));
    }

    double NewtonRaphsonMethod::EvalurateDerivative(double x)
    {
        return f_x(x);
    }
}