#ifndef SUPER
#define SUPER
#include "Train.cpp"
class SuperSpeed : public Train
{
public:
	SuperSpeed(vector<int> &vect) //costruttore di SuperSpeed: riceve come parametro un vettore di int corrispondente alla riga nel timetables del treno da creare.
		: Train(vect)			  //inizializza le vaariabili tramite il costruttore di Train
	{
		max_speed = (double) 300 / 60;
	}
};
#endif