#ifndef TRAIN1
#define TRAIN1
#include "T.h"

class Train:public T{
public:
Train()
{
	std::cout << "Train.cpp constructor" << std::endl;
}
void Print()
{
	cout << "\nTRAIN";
}
};

#endif
