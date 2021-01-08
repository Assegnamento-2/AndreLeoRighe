#ifndef TRAINC
#define TRAINC
#include "Train.h"

Train::Train(vector<int> &vect) //costruttore di Train: riceve come parametro un int corrispondente alla riga nel timetables del treno da creare. Serve a inizializzare le variabili nelle calssi derivate
	: name{vect[0]}, start_station{vect[1]}, type{vect[2]}, start_time{vect[3]}
{
	if (start_station == 0)
		current_pos = 0;
}
// Train::Train()		NON CREDO SERVA
// 	: name{-1}, start_station{-1}, type{-1}, start_time{-1} { std::cout << "default constructor\n"; }
//~Train() {}
void Train::setSpeed(double speed) //setta la velocità richiesta, se superiore al limite setta come velocità la velocità massima
{
	speed = (double)speed / 60;
	if (speed > max_speed)
		current_speed = max_speed;
	else
		current_speed = speed;
}
void Train::setSpeedLimit() //setta il limite di velocità a 80km/h nella zona vicino alla stazione
{
	current_speed = (double)80 / 60;
}
double Train::getPosition() //ritorna la posizione del treno
{
	return current_pos;
}
void Train::updatePosition() //modifica la posizione del treno dopo un minuto
{
	current_pos += current_speed;
}
#endif