#include "Railway.h"

using namespace std;

class Train : public Railway
{
public:

	virtual void setSpeed(int current_speed) = 0;
	virtual void setSpeedLimit() = 0;
    virtual void getPosition() = 0;
    virtual void setName(int n) = 0;
	virtual void setStart(int s) = 0;
	//virtual void getTime() = 0;
	virtual ~Train();
};
