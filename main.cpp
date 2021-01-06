#include "Regional.cpp"

int main()
{
    ifstream input;
    input.open("timetables.txt");

    vector<vector<int>> all_trains; //vettore di vettori -> ogni vettore = un treno

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
        all_trains.push_back(arr);
    }
    input.close();


    input.open("line_description.txt");

    vector<vector<string>> all_stations; //vettore di vettori -> ogni vettore = una stazione

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
        all_stations.push_back(arr); //associo ad un elemento dell'array di STAZIONI il vettore del singolo treno
    }
    input.close();

    Regional firstone(all_trains[0]);



    // for (int i = 0; i < all_trains.size(); i++) //ALL TRAINS E ALL STATIONS OK! :)
    // {
    //     for (auto k : all_trains[i])
    //         cout << k << " ";
    //     cout << endl;
    // }


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

    // for(auto elem : all_trains)
    //     checkTimes(elem);
};
//  void checkTimes(vector<int> times)
//     {
//         if (times[2] == 1)
//             checkTimesRegional(times);
//         if (times[2] == 2)
//             checkTimesHSpeed(times);
//         if (times[2] == 3)
//             checkTimesSHSpeed(times);

//     }