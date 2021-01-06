#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Railway
{
    public:
		Railway();
		void getTimetable(string file_name);
		void getLineDescription(string file_name);

};