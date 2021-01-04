#include "Regional.cpp"

int main(){
	ifstream input("timetables.txt");
	int i;
	vector<int> data;
	while (input>>i)
	{
		data.push_back(i);
	}
    //for(int num : data)
    //    cout<<num<<endl;

//primo numero = nome treno
//secondo numero = stazione di partenza (0=origine / 1=capolinea)
//terzo numero = tipo di treno (1=regionale)
//quarto -> ... orari
if (data[2] == 1)
	Regional r = new Regional(data);
if (data[2] == 2)
	HighSpeed hs = new HighSpeed(data);
if (data[2] == 3)
	SuperHighSpeed shs = new SuperHighSpeed(data);
}

void checkTimes(vector<int> times){

	for(int i = 4, i++, i<number_ of_stations+4)
		if (time[i]<min_time)
				time[i]=min_time+10;
}


int min_time = 10/80 + (/*distanza tra stazioni-10 / velocità treno*/);