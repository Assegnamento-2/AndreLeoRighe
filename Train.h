#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

class Train
{
public:
    virtual void setSpeed(int current_speed) = 0;
    virtual void setSpeedLimit() = 0;
    virtual void getPosition() = 0;
    int speed;
};
// class Station
// {
// public:
//     virtual void
// }