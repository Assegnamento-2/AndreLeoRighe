Andrea Calciolari

#ifndef ROOTSTATIONH
#define ROOTSTATIONH

#include "Regional.cpp"
#include "HighSpeed.cpp"
#include "SuperSpeed.cpp"

class RootStation
{
    virtual void manage(vector<Train>& vect, const int time) = 0;
    virtual void start(vector<Train>& vect, const int time) = 0;
};

#endif
