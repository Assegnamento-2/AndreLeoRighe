#ifndef STATIONC
#define STATIONC

#include "Station.h"

Station::Station(vector<string> &vect) : name{vect[0]}, type{stoi(vect[1])}, distance{stod(vect[2])}, station_number{stoi(vect[3])}, previous_distance{stod(vect[4])}
{
}
void Station::manage(vector<Train> &vect, const int time)
{

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i].current_pos < distance - 5) //se è nella zona senza limiti di velocità
        {
            vect[i].setSpeed(vect[i].max_speed);                                                                         //viene settata alla velocità massima per il treno
            if (i != 0 && vect[i - 1].current_pos < distance - 5 && vect[i - 1].current_pos - vect[i].current_pos <= 10) //se il treno precedente non è ancora arrivato al parcheggio e la distanza fra i due è <= 10km (e se non è il primo treno gestito, che per come è ordinato il vettore, non puô avere treni che lo rallentano)
            {
                vect[i].setSpeed(vect[i - 1].current_speed); //setta la velocità del treno dietro uguale a quello che lo precede NON CREDO SERVA CONTROLLARE GLI ALTRI
                                                             // NON CREDO SERVA CONTROLLARE GLI ALTRI
            }
        }
        else if (vect[i].current_pos >= distance - 5 && vect[i].current_pos < distance && !vect[i].is_parked) //quando arriva a 5km(e non è già nel parcheggio)
        {
            if (free_binaries > 0) //se ci sono binari liberi ne occupa uno e parte verso la stazione
            {
                free_binaries--;
                vect[i].setSpeedLimit();
            }
            else if (free_binaries == 0)
            {
                vect[i].wait = 0;
                vect[i].is_parked = true;
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
        else if (vect[i].current_pos >= distance && vect[i].current_pos < distance + (80.00 / 60.00)) //se il treno è  nella stazione
        {
            if (vect[i].wait == 0)
            {
                cout << "Il treno " << vect[i].name << " è arrivato alla stazione " << name << " alle " << time;
                if (time > vect[i].eta[station_number])
                    cout << ", con un ritardo di " << time - vect[i].eta[station_number] << " minuti";
                if (time == vect[i].eta[station_number])
                    cout << ", perfettamente in orario!";
                if (time < vect[i].eta[station_number])
                    cout << ", in anticipo di " << vect[i].eta[station_number] - time << " minuti";
                cout << endl;
            }
            if (vect[i].wait < 5) //se sono passati meno di 5 minuti, continua ad aspettare
            {
                vect[i].setSpeed(0);
                vect[i].wait++;
            }
            else if (vect[i].current_pos == distance && vect[i].wait == 5) //se sono passati 5 minuti può partire
            {
                vect[i].wait = 0;
                vect[i].setSpeedLimit();
                free_binaries++;
            }
        }
        vect[i].updatePosition();
        vect[i].moved = true;
    }
}
void Station::start(vector<Train> &vect, const int time)
{

    for (int i = 0; i < vect.size(); i++)
    {
        if (i != 0 && (vect[i].start_time - vect[i - 1].start_time) < 6)
        {
            vect[i].start_time = 6 + vect[i - 1].start_time;
        }
        else if (vect[i].start_time == time) //&& (vect[i].start_time - vect[i - 1].start_time) > 6)
        {
            vect[i].setSpeedLimit();
            cout << "Il treno " << vect[i].name << " è partito dalla stazione " << name << " alle " << time << endl;
        }
        vect[i].updatePosition();
        vect[i].moved = true;
    }
}
#endif
