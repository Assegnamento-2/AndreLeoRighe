//Jacopo Righetto

#ifndef HIGHSPEEDC
#define HIGHSPEEDC

#include "Train.cpp"
class HighSpeed : public Train
{
public:
	HighSpeed(vector<int> &vect) //costruttore di HighSpeed: riceve come parametro un vettore di int corrispondente alla riga nel timetables del treno da creare.
		: Train(vect)			 //inizializza le vaariabili tramite il costruttore di Train
	{
		max_speed = (double)240 / 60;
	}
};

#endif
