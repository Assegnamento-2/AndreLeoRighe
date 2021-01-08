#ifndef STATIONC
#define STATIONC

#include "Station.h"

Station::Station(vector<string> vect)
:name{vect[0]}, type{stoi(vect[1])}, distance{stoi(vect[2])}
{
}
#endif