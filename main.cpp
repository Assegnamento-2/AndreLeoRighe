#include "Regional.cpp"

int main()
{
    int number_of_trains = 0;
    ifstream input;
    input.open("timetables.txt");
    while (!input.eof())
    {
        string s;
        getline(input, s);
        number_of_trains++;
    }
    input.close();
    input.open("timetables.txt");

    vector<vector<int>> all_trains[number_of_trains];

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
    }
    input.close();

    int number_of_stations = 0;
    input.open("line_description.txt");
    while (!input.eof())
    {
        string s;
        getline(input, s);
        number_of_stations++;
    }
    input.close();
    input.open("line_description.txt");

    vector<vector<string>> all_stations[number_of_stations];

    while (input)
    {
        vector<string> arr;
        string input_line;
        getline(input, input_line);
        stringstream row;
        row.str(input_line);
        string num;
        while (row >> num)
        {
            arr.push_back(num);
        }
        all_stations->push_back(arr); //associo ad un elemento dell'array di STAZIONI il vettore del singolo treno
    }

    // for (int i = 0; i < number_of_stations; i++)                                     PROVA DI STAMPA NON VA
    // {
    //     for (auto k = all_trains[i].begin(); k != all_stations[i].end(); k++)
    //     {
    //         cout << k << ' ';
    //     }
    // }

    input.close();

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