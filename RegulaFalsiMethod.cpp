//
// Created by deves on 9/29/2015.
//

#include "RegulaFalsiMethod.h"

namespace numeths
{

	RegulaFalsiMethod::RegulaFalsiMethod(std::function<double(double)> fx, double A, double B) :
			A(A), B(B),	RootFindingMethod(fx)
	{
		this->setTolerance(0.0000000001);
		this->setIterationCount(50);
		this->MODE = ITERATION;
	}


	bool RegulaFalsiMethod::Solve()
	{
		do
		{
			c = ( A*Evaluate(B) - B*Evaluate(A) ) / ( Evaluate(B)-Evaluate(A) );
			_iterations.push_back(*(new Iteration(c, Evaluate(c))));
			(Evaluate(c)*Evaluate(A)<0) ? B = c : A = c;
		} while (ShouldContinue());
		return true;
	}

	bool RegulaFalsiMethod::ShouldContinue()
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

	double RegulaFalsiMethod::Root()
	{
		return ( A*Evaluate(B) - B*Evaluate(A) ) / ( Evaluate(B)-Evaluate(A) );
		;
	}
}