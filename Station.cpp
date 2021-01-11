#ifndef STATIONC
#define STATIONC

#include "Station.h"

Station::Station(vector<string> &vect) : name{vect[0]}, type{stoi(vect[1])}, distance{stod(vect[2])}, previous_distance{stod(vect[3])}
{
}
void Station::manage(vector<Train> &vect)
{

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i].current_pos < distance - 5)
        {
            vect[i].setSpeed(vect[i].max_speed);
            if (vect[i - 1].current_pos < distance - 5 && vect[i - 1].current_pos - vect[i].current_pos <= 10 && i != 0) //se il treno precedente non è ancora arrivato al parcheggio e la distanza fra i due è <= 10km (e se non è il primo treno gestito, che per come è ordinato il vettore, non puô avere treni che lo rallentano)
            {
                vect[i].setSpeed(vect[i - 1].current_speed); //setta la velocità del treno dietro uguale a quello che lo precede NON CREDO SERVA CONTROLLARE GLI ALTRI
                                                             // NON CREDO SERVA CONTROLLARE GLI ALTRI
            }
        }
        else if (vect[i].current_pos >= distance - 5 && !vect[i].is_parked) //quando arriva a 5km(e non è già nel parcheggio)
        {
            if (free_binaries > 0) //se ci sono binari liberi
            {
                free_binaries--;
                vect[i].setSpeedLimit();
            }
            if (free_binaries == 0)
            {
                vect[i].wait = 0;
                vect[i].is_parked == true;
            }
        }
        else if (vect[i].is_parked && free_binaries > 0) //treno nel parcheggio e banchine disponibili il treno vi accede
        {
            vect[i].setSpeedLimit();
            vect[i].is_parked = false;
            vect[i].wait = 0;
            free_binaries--;
        }
        else if (vect[i].is_parked && free_binaries == 0) //treno nel parcheggio e banchine piene il treno resta nel parcheggio
        {
            vect[i].wait++;
        }
        if (vect[i].current_pos == distance) //se il treno è  nella stazione
        {
            if (vect[i].wait < 5) //se sono passati meno di 5 minuti, continua ad aspettare
            {
                vect[i].setSpeed(0);
                vect[i].wait++;
            }
            if (vect[i].current_pos == distance && vect[i].wait == 5) //se sono passati 5 minuti può partire
            {
                vect[i].wait = 0;
                vect[i].setSpeedLimit();
            }
        }
        vect[i].updatePosition();
    }
}

#endif
