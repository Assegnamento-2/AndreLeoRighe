#include "Train.h"


class Regional : public Train
{
public:
    void setSpeed(int current_speed)
    {
        speed = current_speed;
    }
    void setSpeedLimit()
    {
        speed = 80;
        getTime();
    }
    void getPosition()
    {
    }
};