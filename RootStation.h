#ifndef ROOTSTATIONH
#define ROOTSTATIONH

#include "Regional.cpp"
#include "HighSpeed.cpp"
#include "SuperSpeed.cpp"

class RootStation
{
    virtual void manage(vector<Train>& vect) = 0;
};

#endif