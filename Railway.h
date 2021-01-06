// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <string>
// #include <fstream>
// #include <sstream>


// using namespace std;

#include "Train.h"

class Railway
{
public:
	Railway();
	vector<vector<int>> all_trains;		 //vettore di vettori -> ogni vettore = un treno
	vector<vector<string>> all_stations; //vettore di vettori -> ogni vettore = una stazione
	int leoleo;
	void getTimetable();
	void getLineDescription();
	void checkTimetables();
};