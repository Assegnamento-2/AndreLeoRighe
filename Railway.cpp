#include "Railway.h"

Railway::Railway() {}

void Railway::getTimetable(string file_name)
{
    ifstream input;
    input.open(file_name);

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
}
void Railway::getLineDescription(string file_name)
{
    ifstream input;
    input.open(file_name);
    bool is_first = true;
    while (input)
    {
        vector<string> arr;
        string input_line;
        getline(input, input_line);
        stringstream row;
        row.str(input_line);
        string num;
        while (row >> num) //DA FARE: SE IL NOME STAZIONE È COMPOSTO DA PIÙ PAROLE VA MESSO NELLA STESSA CELLA DEL VETTORE
        {
            arr.push_back(num);
        }
        if (is_first)
        {
            arr.push_back("0");
            arr.push_back("0");
            is_first = false;
        }
        all_stations.push_back(arr); //associo ad un elemento dell'array di STAZIONI il vettore del singolo treno
    }
    input.close();
     for (int i = 1; i < all_stations.size()-1; i++) //perché size è 1 in più????
    {
       if (stoi(all_stations[i][1]) != 1) //controlla che il tipo di stazione sia accettabile, altrimenti le assegna il ruolo di stazione principale
       {
            all_stations[i][1] = "0";
            cout<<i;
        }
        if ((stoi(all_stations[i][2])-stoi(all_stations[i-1][2]))<20) //cerca ed elimina opportunamente eventuali stazioni distanti meno di 20km fra loro
        {
            all_stations.erase(all_stations.begin()+i);
        }
    }
};
//Regional firstone(all_trains[0]);

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
//  void checkTimes(vector<int> times)
//     {
//         if (times[2] == 1)
//             checkTimesRegional(times);
//         if (times[2] == 2)
//             checkTimesHSpeed(times);
//         if (times[2] == 3)
//             checkTimesSHSpeed(times);

//     }