//
// Created by deves on 9/13/2015.
//

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
        int getIterationCount() const
        {
            return IterationCount;
        }

        void setIterationCount(int IterationCount)
        {
            RootFindingMethod::IterationCount = IterationCount;
        }
    };
}

#endif //NUMETHS_ROOTFINDINGMETHOD_H
