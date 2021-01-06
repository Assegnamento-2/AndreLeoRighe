#include "Train.h"
    
 class Train{
public:
    Train(int index)//costruttore di Train: riceve come parametro un int corrispondente al nome del treno da creare
	:start_time{9}
	{	
		name = all_trains[index][0];
		start_station = all_trains[index][1];
		type = all_trains[index][2];
	}
    void setSpeed(int current_speed) {}
	void setSpeedLimit() {}
    void getPosition() {}
    void setName(int n) {}
	void setStart(int s) {}
    int max_speed;
    int name;
	int start_station;
    const int start_time;
	int type;
	double current_pos;
	double current_speed;
}