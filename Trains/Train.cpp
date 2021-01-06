#include "Train.h"

Train::Train(int index) //costruttore di Train: riceve come parametro un int corrispondente alla riga nel timetables del treno da creare
	: name{all_trains[index][0]}, start_station{all_trains[index][1]}, type{all_trains[index][2]}, start_time{all_trains[index][3]}
{
	//setta la velocità massima in km/min
	if (type == 1)
		max_speed = 160 / 60;
	if (type == 2)
		max_speed = 240 / 60;
	if (type == 3)
		max_speed = 300 / 60;
}
Train::~Train() {}
void Train::setSpeed(double speed) //setta la velocità richiesta, se superiore al limite setta come velocità la velocità massima
{
	if (speed > max_speed)
		current_speed = max_speed;
	current_speed = speed;
}
void Train::setSpeedLimit() //setta il limite di velocità a 80km/h nella zona vicino alla stazione
{
	current_speed = 80 / 60;
}
double Train::getPosition() //ritorna la posizione del treno
{
	return current_pos;
}
void Train::updatePosition()//modifica la posizione del treno dopo un minuto
{
	current_pos += current_speed;
}
