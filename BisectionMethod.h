//
// Created by deves on 9/11/2015.
//

#ifndef NUMETHS_BISECTIONMETHOD_H
#define NUMETHS_BISECTIONMETHOD_H

#include "RootFindingMethod.h"

namespace numeths
{
    class BisectionMethod : public RootFindingMethod
    {

        private:
            int A, B;
            int c;

        public:

            BisectionMethod(std::function<double(double)>);
    };
}

#endif //NUMETHS_BISECTIONMETHOD_H
