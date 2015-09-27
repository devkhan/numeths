//
// Created by deves on 9/11/2015.
//

#include "BisectionMethod.h"


namespace numeths
{

	BisectionMethod::BisectionMethod(std::function<double(double)> fx, double A, double B) : A(A),
	                                                                                       B(B)
			, RootFindingMethod(fx)
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
			_iterations.push_back(*(new Iteration(c, Evaluate(c))));
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

}