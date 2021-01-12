//Jacopo Righetto

#ifndef REGIONALC
#define REGIONALC

#include "Train.cpp"
class Regional : public Train
{
public:
    Regional(vector<int> &vect) //costruttore di Regional:  riceve come parametro un vettore di int corrispondente alla riga nel timetables del treno da creare.
        : Train(vect)           //inizializza le variabili tramite il costruttore di Train
    {
        max_speed = (double)160 / 60;
    }
};

#endif
