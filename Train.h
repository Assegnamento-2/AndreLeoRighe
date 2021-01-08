#ifndef TRAINH
#define TRAINH
#include "RootTrain.h"
class Train : public RootTrain
{
public:
    Train(vector<int> &vect);
    void setSpeed(double speed);
    void setSpeedLimit();
    double getPosition();
    void updatePosition();
    const int name;
    const int start_station;
    const int start_time;
    const int type;
    vector<int> eta;        //vettore che contiene gli Estimated Time of Arrival
    double current_pos = 0; //se il treno parte dal capolinea?
    double current_speed = 0;
    double max_speed;
};
#endif