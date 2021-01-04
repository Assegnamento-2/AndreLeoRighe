#include "Regional.cpp"

int main(){
	ifstream input("timetables.txt");
	int i;
	vector<int> data;
	while (input)
	{
		input >> i;
		data.push_back(i);
	}
	//terzo numero indica il tipo di treno
	if(data[2]==1)
		Regional r = new Regional(data);
	if(data[2]==2)
		HighSpeed hs = new HighSpeed(data);
	if(data[2]==3)
		SuperHighSpeed shs = new SuperHighSpeed(data);
}