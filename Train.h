#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

class Train
{
public:
    virtual void setSpeed(int current_speed) = 0;
    virtual void setSpeedLimit(int s) = 0;
    virtual void getPosition() = 0;
    virtual void setName(int n) = 0;
	virtual void setStart(int s) = 0;
	virtual void print() = 0;
	virtual void getTime() = 0;
	int speed;
    int name;
    int start_time;
};

