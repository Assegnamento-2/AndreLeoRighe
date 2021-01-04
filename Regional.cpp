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
    }
    void getPosition()
    {
    }
};
int main(){
	ifstream input("timetables.txt");
	int i;
	vector<int> data;
	while (input)
	{
		input >> i;
		data.push_back(i);
	}
}