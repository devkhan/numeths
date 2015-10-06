//
// Created by deves on 9/27/2015.
//

#ifndef NUMETHS_STEP_H
#define NUMETHS_STEP_H


namespace numeths
{
	class Iteration
	{
		public:

			double Root;
			double Residual;
			double Error;

			Iteration(double Root, double Residual, double Error);
	};
}


#endif //NUMETHS_STEP_H
