//
// Created by deves on 9/29/2015.
//

#include "RootFindingMethod.h"

#ifndef NUMETHS_REGULAFALSIMETHOD_H
#define NUMETHS_REGULAFALSIMETHOD_H

namespace numeths
{
	class RegulaFalsiMethod : public RootFindingMethod
	{
		private:

			double A, B, c;

		public:
			RegulaFalsiMethod(std::function<double(double)> fx, double, double);

			bool Solve();

			bool ShouldContinue();

			double Root();

			void CalculateError();
	};
}

#endif //NUMETHS_REGULAFALSIMETHOD_H
