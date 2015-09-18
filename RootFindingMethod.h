/**
 * Base class for all root finding methods.
 *
 */

#ifndef NUMETHS_ROOTFINDINGMETHOD_H
#define NUMETHS_ROOTFINDINGMETHOD_H


namespace numeths
{
    class RootFindingMethod
    {
        protected:

            int IterationCount;
		    double Tolerance;


	    public:

	        int getIterationCount();

	        void setIterationCount(int);

		    double getTolerance();

		    void setTolerance(double);
    };
}

#endif //NUMETHS_ROOTFINDINGMETHOD_H
