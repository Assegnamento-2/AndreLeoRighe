#ifndef STATIONC
#define STATIONC

#include "Station.h"

Station::Station(vector<string> &vect) : name{vect[0]}, type{stoi(vect[1])}, distance{stod(vect[2])}, previous_distance{stod(vect[3])}
{
}
void Station::manage(vector<Train> &vect)
{   
    
    // int park1;
    // while (free_binaries > 0 && parking.size() != 0) //se ci sono binari liberi 
    // {
    //     parking[0].setSpeedLimit();
    //     free_binaries--;
    //     park1=parking[0].name;
    //     parking.erase(parking.begin());      
    // }

    for (int i = 0; i < vect.size(); i++)
    {
        if(vect[i].is_parked || free_binaries > 0)
        {
            vect[i].setSpeedLimit();
			vect[i].is_parked = false;
			free_binaries--;
		}
		else if(vect[i].is_parked || free_binaries ==0 )
        {
            vect[i].wait++;
        }
        
        
        if (vect[i].current_pos >= distance - 5) //quando arriva a 5km
        {
            if (free_binaries > 0) //se ci sono binari liberi
            {
                free_binaries--;
                vect[i].setSpeedLimit();
            }
            else
        }
        if (vect[i].current_pos == distance)
        {
            if (vect[i].wait < 5)
            {
                vect[i].setSpeed(0);
                vect[i].wait++;
            }
            if (vect[i].current_pos == distance && vect[i].wait == 5)
            {
                vect[i].wait = 0;
                vect[i].setSpeedLimit();
            }
        }
        vect[i].updatePosition();
    }
}

#endif
