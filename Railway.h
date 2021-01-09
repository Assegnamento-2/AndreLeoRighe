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
	static bool compareTrains(vector<int>& uno, vector<int>& due); //serve per ordinare i treni quando viene letto il timetable
	static bool compareStations(vector<string>& uno, vector<string>& due); //serve per ordinare le stazioni quando viene letto il line_description


	vector<vector<int>> all_trains;		 //vettore di vettori -> ogni vettore = un treno
	vector<vector<string>> all_stations; //vettore di vettori -> ogni vettore = una stazione
	vector<Station> station_vect;
	vector<Train> train_vect;
};
