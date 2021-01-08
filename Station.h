#ifndef STATIONH
#define STATIONH
#include "RootStation.h"

class Station : public RootStation
{
public:
    Station(vector<string> vect);
    
    //vector<Train> elenco;
    const string name;
    const int type;
    const int distance;
};
#endif