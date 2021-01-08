#ifndef PRINCIPALC
#define PRINCIPALC

#include "Station.cpp"

class Principal : public Station
{
public:
    Principal(vector<string> vect)
        : Station(vect)
    {
    }
};

#endif