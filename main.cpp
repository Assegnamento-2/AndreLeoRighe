#include "Regional.cpp"

<<<<<<< HEAD

=======
>>>>>>> d106a117d184d6788caa60a1d7afc603428fea8a
int main(){
	ifstream input("timetables.txt");
	int i;
	vector<int> data;
<<<<<<< HEAD
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
if (data[3] == 1)
	Regional r = new Regional(data);
if (data[3] == 2)
	HighSpeed hs = new HighSpeed(data);
if (data[3] == 3)
	SuperHighSpeed shs = new SuperHighSpeed(data);
=======
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
>>>>>>> d106a117d184d6788caa60a1d7afc603428fea8a
}