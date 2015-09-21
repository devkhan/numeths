/**
 * Base class for all root finding methods.
 *
 */

#include <functional>

#ifndef NUMETHS_ROOTFINDINGMETHOD_H
#define NUMETHS_ROOTFINDINGMETHOD_H


namespace numeths
{
    class RootFindingMethod
    {

		    enum TerminateMode
		    {
			    ITERATION,
			    TOLERANCE

		    };
        protected:

		    std::function<double(double)> f;
            int IterationCount;
		    double Tolerance;


	    public:

		    RootFindingMethod(std::function<double(double)> f);

		    ~RootFindingMethod() { };

	        int getIterationCount();

	        void setIterationCount(int);

		    double getTolerance();

		    void setTolerance(double);

		    bool Solve();

		    double Evaluate(double x);
    };
}

#endif //NUMETHS_ROOTFINDINGMETHOD_H
