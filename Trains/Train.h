#include "Railway.h"

class Train : public Railway
{
public:
	Train(int index);
	virtual void setSpeed(double speed) = 0;
	virtual void setSpeedLimit() = 0;
	virtual double getPosition() = 0;
	virtual void updatePosition() = 0;

	const int name;
	const int start_station;
	const int start_time;
	const int type;
	double current_pos;
	double current_speed;
	double max_speed;
	virtual ~Train();
};
