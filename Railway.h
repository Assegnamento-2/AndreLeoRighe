// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <string>
// #include <fstream>
// #include <sstream>


// using namespace std;
#ifndef RAILWAY
#define RAILWAY
#include "Train.h"
 class Train;
class Railway
{
public:
	Railway();
	vector<vector<int>> all_trains;		 //vettore di vettori -> ogni vettore = un treno
	vector<vector<string>> all_stations; //vettore di vettori -> ogni vettore = una stazione
	void getTimetable();
	void getLineDescription();
	void checkTimetables();
};
#endif