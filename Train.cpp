//Jacopo Righetto

#ifndef TRAINC
#define TRAINC
#include "Train.h"

Train::Train(vector<int> &vect) //costruttore di Train: riceve come parametro un vettore di int corrispondente alla riga nel timetables del treno da creare. Serve a inizializzare le variabili nelle calssi derivate
	: name{vect[0]}, type{vect[2]}, start_time{vect[3]}
{
	if (start_station == 0)
		current_pos = 0;
	else
	{
		start_station=1;
		current_pos = vect[3];
	}
	for (int i = 3; i < vect.size(); i++)
	{
		eta.push_back(vect[i]);
	}
}
Train &Train::operator=(const Train &original) //assegnamento di copia

{
	name = original.name;
	start_time = original.start_time;
	type = original.type;
	start_station = original.start_station;
	moved = original.moved; //in run(railway.cpp) serve per verificare se il treno è già stato mosso nel minuto
	is_parked = original.is_parked;
	eta = original.eta;					//vettore che contiene gli Estimated Time of Arrival
	current_pos = original.current_pos; //se il treno parte dal capolinea?
	current_speed = original.current_speed;
	max_speed = original.max_speed;
	wait = original.wait;
	delay = original.delay;
	has_arrived = original.has_arrived;
	return *this;
}
void Train::setSpeed(double speed) //setta la velocità richiesta, se superiore al limite setta come velocità la velocità massima
{
	speed = (double)speed;
	if (speed > max_speed)
		current_speed = max_speed;
	else
		current_speed = speed;
}
void Train::setSpeedLimit() //setta il limite di velocità a 80km/h nella zona vicino alla stazione
{
	current_speed = 80.00 / 60.00;
}
void Train::updatePosition() //modifica la posizione del treno dopo un minuto
{
	if (start_station == 0)
		current_pos += current_speed;
	else
		current_pos -= current_speed;
}
#endif
