#include "Principal.cpp"
#include "Local.cpp"
class Railway
{
public:
	Railway();
	void getTimetable();
	void getLineDescription();
	void checkTimetables();
	void setETA(int treno, int stazione, int checked_eta);
	
	vector<vector<int>> all_trains;		 //vettore di vettori -> ogni vettore = un treno
	vector<vector<string>> all_stations; //vettore di vettori -> ogni vettore = una stazione
	vector<Station> station_vect;
	vector<Train> train_vect;
};
