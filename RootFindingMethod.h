/**
 * Base class for all root finding methods.
 *
 */

#include <functional>
#include <vector>
#include "Iteration.h"

#ifndef NUMETHS_ROOTFINDINGMETHOD_H
#define NUMETHS_ROOTFINDINGMETHOD_H


namespace numeths
{
    class RootFindingMethod
    {

	    protected:
		    enum TerminateMode
		    {
			    ITERATION,
			    TOLERANCE
		    };

		    std::function<double(double)> f;
            int IterationCount;
		    double Tolerance;
		    TerminateMode MODE;
		    std::vector<Iteration> _iterations;


	    public:

		    RootFindingMethod(std::function<double(double)>);

		    ~RootFindingMethod() { };

	        int getIterationCount();

	        void setIterationCount(int);

		    double getTolerance();

		    void setTolerance(double);

		    virtual bool Solve() = 0;

		    virtual bool ShouldContinue() = 0;

		    double Evaluate(double x);

		    virtual double Root() = 0;
    };
}

#endif //NUMETHS_ROOTFINDINGMETHOD_H
