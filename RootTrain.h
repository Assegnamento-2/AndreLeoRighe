//Jacopo Righetto

#ifndef ROOTTRAINH
#define ROOTTRAINH

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class RootTrain
{
public:
	virtual void setSpeed(double speed) = 0;
	virtual void setSpeedLimit() = 0;
	virtual void updatePosition() = 0;
};
#endif
