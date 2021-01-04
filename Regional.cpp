#include "Train.h"


class Regional : public Train
{
public:
<<<<<<< HEAD
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
=======
    void setSpeed(int current_speed)    {   speed = current_speed;  }
    void setSpeedLimit()    {   speed = 80;    }
    void getPosition(){}

    Regional(vector<int> vect){
        setName(data[0]);
        setStart(data[1]);
        setSpeed(160);
        //setTimes?
    }
};
>>>>>>> d106a117d184d6788caa60a1d7afc603428fea8a
