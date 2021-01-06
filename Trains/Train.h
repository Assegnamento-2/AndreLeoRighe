#include "Railway.h"

using namespace std;

class Train : public Railway
{
public:
	Train(int index)//costruttore di Train: riceve come parametro un int corrispondente al nome del treno da creare
	:start_time{9}
	{	
		name = all_trains[index][0];
		start_station = all_trains[index][1];
		type = all_trains[index][2];
	}
	virtual void setSpeed(int current_speed) = 0;
	virtual void setSpeedLimit() = 0;
    virtual void getPosition() = 0;
    virtual void setName(int n) = 0;
	virtual void setStart(int s) = 0;
	//virtual void getTime() = 0;
	int max_speed;
    int name;
	int start_station;
    const int start_time;
	int type;
	double current_pos;
	double current_speed;
	virtual ~Train();
};
