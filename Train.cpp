#include "Train.h"

Train::Train(vector<int>& vect) //costruttore di Train: riceve come parametro un int corrispondente alla riga nel timetables del treno da creare
	: name{vect[0]}, start_station{vect[1]}, type{vect[2]}, start_time{vect[3]}
{
	//setta la velocità massima in km/min
	if (type == 1)
		max_speed = 160 / 60;
	if (type == 2)
		max_speed = 240 / 60;
	if (type == 3)
		max_speed = 300 / 60;
}
Train::Train()
	: name{-1}, start_station{-1}, type{-1}, start_time{-1} { std::cout << "default constructor"; }
	{}
//Train::~Train() {}
void Train::setSpeed(double speed) override //setta la velocità richiesta, se superiore al limite setta come velocità la velocità massima
{
	if (speed > max_speed)
		current_speed = max_speed;
	current_speed = speed;
}
void Train::setSpeedLimit() override //setta il limite di velocità a 80km/h nella zona vicino alla stazione
{
	current_speed = 80 / 60;
}
double Train::getPosition() override //ritorna la posizione del treno
{
	return current_pos;
}
void Train::updatePosition() override //modifica la posizione del treno dopo un minuto
{
	current_pos += current_speed;
}
