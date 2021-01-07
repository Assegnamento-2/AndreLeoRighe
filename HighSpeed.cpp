
#include "Train.cpp"

class HighSpeed : public Train
{
public:
	HighSpeed()
	{
		std::cout << " HighSpeed.cpp constructor ";
	}
	void Print()
	{
		cout << "\nHIH";
	}
};
