#ifndef ROOTTRAINH
#define ROOTTRAINH

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class RootTrain
{
public:
	virtual void setSpeed(double speed) = 0;
	virtual void setSpeedLimit() = 0;
	virtual double getPosition() = 0;
	virtual void updatePosition() = 0;
};
#endif