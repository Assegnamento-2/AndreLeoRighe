#include "Train.cpp"
class HighSpeed : public Train
{
public:
	HighSpeed(vector<int> &vect) //costruttore di Train: riceve come parametro un int corrispondente alla riga nel timetables del treno da creare
		: Train(vect)			 //inizializza le vaariabili tramite il costruttore di Train
	{
		max_speed = (double)240 / 60;
	}
};