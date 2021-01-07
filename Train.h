#ifndef TRAINH
#define TRAINH
#include "Root.h"
class Train : public Root
{
public:
    //Train();
    Train(vector<int> &vect);
    void setSpeed(double speed);
    void setSpeedLimit();
    double getPosition();
    void updatePosition();
    const int name;
    const int start_station;
    const int start_time;
    const int type;
    double current_pos;
    double current_speed;
    double max_speed;
};
#endif