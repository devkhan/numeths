//
// Created by deves on 9/13/2015.
//

#include "RootFindingMethod.h"

namespace numeths
{
	int RootFindingMethod::getIterationCount()
	{
		return IterationCount;
	}

	void RootFindingMethod::setIterationCount(int IterationCount)
	{
		RootFindingMethod::IterationCount = IterationCount;
	}

	double RootFindingMethod::getTolerance()
	{
		return Tolerance;
	}

	void RootFindingMethod::setTolerance(double Tolerance)
	{
		RootFindingMethod::Tolerance = Tolerance;
	}
}