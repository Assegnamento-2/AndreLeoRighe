#include "Train.h"


class Regional : public Train
{
public:
    
	void setSpeed(int current_speed)    {   speed = current_speed;  }
    void setSpeedLimit()    {   speed = 80; }
    void getPosition(){}
	void setName(int n) { name = n;   };
	void setStart(int s) { start_time = s;   };

	Regional(vector<int> vect){
        setName(vect[0]);
        setStart(vect[1]);
        setSpeed(160);
        //setTimes?
    }
};
