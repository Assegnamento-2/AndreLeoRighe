#include "Regional.cpp"
#include "HighSpeed.cpp"
#include "SuperSpeed.cpp"
class Railway
{
public:
	Railway();
	vector<vector<int>> all_trains;		 //vettore di vettori -> ogni vettore = un treno
	vector<vector<string>> all_stations; //vettore di vettori -> ogni vettore = una stazione
	void getTimetable();
	void getLineDescription();
	void checkTimetables(vector<int>& vect);

	vector<Train> trenivect;
};

