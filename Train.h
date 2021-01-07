// #include "Railway.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

class Train //: public Railway
{
public:
	Train();
	Train(vector<int> &vect);
	virtual void setSpeed(double speed) ;//= 0;
	virtual void setSpeedLimit() ;//= 0;
	virtual double getPosition();// = 0;
	virtual void updatePosition() ;//= 0;

	const int name;
	const int start_station;
	const int start_time;
	const int type;
	double current_pos;
	double current_speed;
	double max_speed;
	// 	virtual ~Train();
};
// class Regional : public Train
// {
// 	public:
// 	Regional();
// };
// class HighSpeed : public Train
// {
// 	public:
// 	HighSpeed();
// };
