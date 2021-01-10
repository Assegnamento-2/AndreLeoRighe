#ifndef STATIONH
#define STATIONH
#include "RootStation.h"

class Station : public RootStation
{
public:
    Station(vector<string>& vect);
    void manage(vector<Train>& vect);
    int free_binaries;
    vector<Train> parking;
    const string name;
    const int type;
    const double distance;
    const double previous_distance;
};
#endif