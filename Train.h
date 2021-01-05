#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Train
{
public:
	virtual void setSpeed(int current_speed) = 0;
	virtual void setSpeedLimit() = 0;
    virtual void getPosition() = 0;
    virtual void setName(int n) = 0;
	virtual void setStart(int s) = 0;
	//virtual void getTime() = 0;
	int speed; //potrebbero andare in private?
    int name;
    int start_time;
	virtual ~Train();
};
