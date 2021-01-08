#include "Railway.h"

Railway::Railway()
{
    getTimetable();
    getLineDescription();

    // for (int i = 0; i < all_trains.size() - 1; i++)
    // {
    //     vector<int> vect = all_trains[i];
    //     checkTimetables(vect);
    //     if (vect[2] == 1)
    //     {
    //         Regional treno(vect);
    //         trenivect.push_back(treno);
    //     }
    //     if (vect[2] == 2)
    //     {
    //         HighSpeed treno(vect);
    //         trenivect.push_back(treno);
    //     }
    //     if (vect[2] == 3)
    //     {
    //         SuperSpeed treno(vect);
    //         trenivect.push_back(treno);
    //     }
    // }
}

void Railway::getTimetable()
{
    ifstream input;
    input.open("timetables.txt");

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
    for (int i = 0; i < all_trains.size() - 1; i++) //perché size è 1 in più????
    {
        if (all_trains[i][1] != 1) //controlla la stazione di partenza sia accettabile, altrimenti assegna la stazione di origine
        {
            all_trains[i][1] = 0;
        }
        if (all_trains[i][2] != 1 || all_trains[i][2] != 2) //controlla che il tipo di treno sia accettabile, altrimenti gli assegna il ruolo di treno superveloce
        {
            all_trains[i][2] = 3;
        }
    }
}
void Railway::getLineDescription()
{
    ifstream input;
    input.open("line_description.txt");
    bool is_first = true;
    while (input)
    {
        vector<string> arr;
        string input_line;
        getline(input, input_line);
        if (!input_line.empty())
        {
            cout<<input_line;
            stringstream row;
            row.str(input_line);
            string num;
            while (row >> num) //DA FARE: SE IL NOME STAZIONE È COMPOSTO DA PIÙ PAROLE VA MESSO NELLA STESSA CELLA DEL VETTORE
            {
                arr.push_back(num);
            }
            if (is_first) //nel caso della prima stazione aggiunge tipologia e distanza
            {
                arr.push_back("0");
                arr.push_back("0");
                is_first = false;
            }
            all_stations.push_back(arr); //associo ad un elemento dell'array di STAZIONI il vettore del singolo treno
        }
        else break;
    }
    input.close();
    // for (int i = 1; i < all_stations.size(); i++)
    // {
    //     // if (!(int w = stoi(all_stations[i][2])))
    //     // {
    //     //     all_stations.erase(all_stations.begin() + i);
    //     //     cout<<i <<endl;
    //     // }

    //     if (stoi(all_stations[i][1]) != 1) //controlla che il tipo di stazione sia accettabile, altrimenti le assegna il ruolo di stazione principale
    //     {
    //         all_stations[i][1] = "0";
    //     }
    //     if ((stoi(all_stations[i][2]) - stoi(all_stations[i - 1][2])) < 20) //cerca ed elimina opportunamente eventuali stazioni distanti meno di 20km fra loro
    //     {
    //         all_stations.erase(all_stations.begin() + i);
    //         i--;
    //     }
    // }
    // if ((all_stations.size() - 1) < 2)
    // {
    //     cout << "Non sono presenti abbastanza stazioni valide";
    //     exit(EXIT_FAILURE);
    // }
}
void Railway::checkTimetables(vector<int> &vect)
{
}
