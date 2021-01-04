#include "Train.h"

class HishSpeed: public Train
{
public:
	virtual void setSpeed(int current_speed) 
	{
		speed = current_speed;
	}
	virtual void setSpeedLimit() {}
    virtual void getPosition() {}
    virtual void setName(int n) {}
	virtual void setStart(int s) {}
	//virtual void getTime() = 0;
	int speed;
    int name;
    int start_time;
};

