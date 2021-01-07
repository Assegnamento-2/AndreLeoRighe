#ifndef TRAIN
#define TRAIN

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class T //: public Railway
{
public:
	T();
	T(vector<int> &vect);
	virtual void setSpeed(double speed) = 0;
	virtual void setSpeedLimit() = 0;
	virtual double getPosition() = 0;
	virtual void updatePosition() = 0;
	//virtual ~T();
};

//class Regional : public Train
//{
//	public:
//	Regional();
//};
// class HighSpeed : public Train
// {
// 	public:
// 	HighSpeed();
// };
#endif