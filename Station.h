#ifndef STATIONH
#define STATIONH
#include "RootStation.h"

class Station : public RootStation
{
public:
    Station(vector<string>& vect);
    void manage(vector<Train>& vect, const int time);
    void start(vector<Train>& vect, const int time);
    int free_binaries=2;
    const string name;
    const int type;
    const double distance;
    const double previous_distance;
    const int station_number;
};
#endif