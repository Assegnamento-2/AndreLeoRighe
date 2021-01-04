#include "Train.h"

class Regional : public Train
{
public:
    void setSpeed(int current_speed) { speed = current_speed; }
    void setSpeedLimit() { speed = 80; }
    void getPosition() {}

    Regional(vector<int> vect)
    {
        setName(data[0]);
        setStart(data[1]);
        setSpeed(300);
        //setTimes?
    }
};