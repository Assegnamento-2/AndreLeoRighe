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
    virtual void setSpeedLimit(int s) = 0;
    virtual void getPosition() = 0;
    virtual void setName(int n) = 0;
	virtual void setStart(int s) = 0;
	virtual void print() { cout << 1; }
	void getTime();
    int speed;
    int name;
    int start_time;
};
class B: public Train
{
    virtual void setSpeed(int current_speed) {}
    virtual void setSpeedLimit(int s) {}
    virtual void getPosition() {}
    virtual void setName(int name) {}
	virtual void setStart(int s) {}
	virtual void print() { cout << 2; }
	void getTime(){}
};

int main()
{
	B i;
	Train& t = i;
	t.print();
}
// class Station
// {
// public:
//     virtual void
// }