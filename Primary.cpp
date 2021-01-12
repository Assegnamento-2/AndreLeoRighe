#ifndef PrimaryC
#define PrimaryC

#include "Station.cpp"

class Primary : public Station
{
public:
    Primary(vector<string> vect)
        : Station(vect)
    {
    }
};

#endif