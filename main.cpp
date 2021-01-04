#include "Regional.cpp"

int main()
{
    int number_of_trains = 0;
    ifstream iput("timetables.txt");
    while (!iput.eof())
    {
        string s;
        getline(iput, s);
        number_of_trains++;
    }
    iput.close();
    ifstream input("timetables.txt");

    vector<vector<int>> all_trains[number_of_trains];
    int buffer = 0;

    while (input)
    {
        vector<int> arr;
        string input_line;
        getline(input, input_line);
        stringstream row;
        row.str(input_line);
        int num;
        while (row >> num)
        {
            arr.push_back(num);
        }
        all_trains->push_back(arr); //associo ad un elemento dell'array di TRENI il vettore del singolo treno
        buffer++;
    }

    //for(int num : data)
    //    cout<<num<<endl;

    //primo numero = nome treno
    //secondo numero = stazione di partenza (0=origine / 1=capolinea)
    //terzo numero = tipo di treno (1=regionale)
    //quarto -> ... orari
    //if (data[2] == 1)
    //    Regional r = new Regional(data);
    // if (data[2] == 2)
    // 	HighSpeed hs = new HighSpeed(data);
    // if (data[2] == 3)
    // 	SuperHighSpeed shs = new SuperHighSpeed(data);

    //void checkTimes(vector<int> times)
    //{
    //    int min_time = 10 / 80 + (/*distanza tra stazioni-10 / velocità treno*/);
    //    for (int i = 4; i < (number_of_stations + 4); i++)
    //        if (times[i] < min_time)
    //            times[i] = min_time + 10;

    //    //delete[] all_train;
    //}
};