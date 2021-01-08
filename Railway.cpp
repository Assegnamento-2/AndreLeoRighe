#include "Railway.h"

Railway::Railway()
{
    getLineDescription();
    getTimetable();

    for (int i = 0; i < all_trains.size(); i++) //crea i treni e li inserisce nel vettore di treni
    {
        vector<int> vect = all_trains[i];
        if (vect[2] == 1)
        {
            Regional treno(vect);
            train_vect.push_back(treno);
        }
        if (vect[2] == 2)
        {
            HighSpeed treno(vect);
            train_vect.push_back(treno);
        }
        if (vect[2] == 3)
        {
            SuperSpeed treno(vect);
            train_vect.push_back(treno);
        }
    }
    for (int i = 0; i < all_stations.size(); i++) //crea le stazioni e le inserisce nel vettore di stazioni
    {
        vector<string> vect = all_stations[i];
        if (vect[1] == "0")
        {
            Principal stazione(vect);
            station_vect.push_back(stazione);
        }
        if (vect[1] == "1")
        {
            Local stazione(vect);
            station_vect.push_back(stazione);
        }
    }
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
        if (input_line.empty()) //controlla che la riga non sia vuota
            continue;
        stringstream row;
        row.str(input_line);
        int num;
        while (row >> num)
        {
            arr.push_back(num);
            if (arr.size() == (all_stations.size() + 3)) //tronca il vettore se sono presenti troppi orari
            {
                break;
            }
        }
        while (arr.size() < (all_stations.size() + 3)) //aggiunge celle al vettore in modo che ce ne siano tante quanti i dati che deve contenere, anche se mancanti
        {
            arr.push_back(0);
        }
        all_trains.push_back(arr);
    }
    input.close();
    for (int i = 0; i < all_trains.size(); i++)
    {
        if (all_trains[i][1] != 1) //controlla la stazione di partenza sia accettabile, altrimenti assegna la stazione di origine
        {
            all_trains[i][1] = 0;
        }
        if (all_trains[i][2] != 1 && all_trains[i][2] != 2) //controlla che il tipo di treno sia accettabile, altrimenti gli assegna il ruolo di treno superveloce
        {
            all_trains[i][2] = 3;
        }
        if (all_trains[i][3] < 0)
        {
            all_trains[i][3] = 0;
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
        if (input_line.empty()) //controlla che la riga non sia vuota
            continue;
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
        if (arr.size() != 3)
            continue;
        all_stations.push_back(arr); //associo ad un elemento dell'array di STAZIONI il vettore del singolo treno
    }
    input.close();
    for (int i = 1; i < all_stations.size(); i++)
    {
        if (stoi(all_stations[i][1]) != 1) //controlla che il tipo di stazione sia accettabile, altrimenti le assegna il ruolo di stazione principale
        {
            all_stations[i][1] = "0";
        }
        if ((stoi(all_stations[i][2]) - stoi(all_stations[i - 1][2])) < 20) //cerca ed elimina opportunamente eventuali stazioni distanti meno di 20km fra loro
        {
            all_stations.erase(all_stations.begin() + i);
            i--;
        }
    }
    if ((all_stations.size() - 1) < 2)
    {
        cout << "Non sono presenti abbastanza stazioni valide";
        exit(EXIT_FAILURE);
    }
}
void Railway::checkTimetables()
{
    vector<Station> principal_stations;
    for (int i = 0; i < station_vect.size(); i++) //crea un vettore di stazioni
    {
        if (station_vect[i].type == 0)
        {
            principal_stations.push_back(station_vect[i]);
        }
    }

    for (int num_treno = 0; num_treno < train_vect.size(); num_treno++)
    {
        int estimated_time;
        if (train_vect[num_treno].start_station == 0)//se il treno parte dalla stazione di origine
        {
            if (train_vect[num_treno].type == 1) //se il treno è regionale e si ferma a ogni stazione
                for (int num_staz = 1; num_staz < station_vect.size(); num_staz++)
                {
                    estimated_time = (double)((station_vect[num_staz].distance - station_vect[num_staz - 1].distance - 10) / (double)(train_vect[num_treno].max_speed)) + (double)((10 * 60) / 80) + 5; //tempo previsto per andare da una stazione alla successiva
                    //(distanza fra stazioni - 10km(limite velocità)) / velocità max treno + trmpo per percorrere i 10 km a 80 km/h + 5 min attesa in stazione
                    if (num_staz == 1)
                        estimated_time -= 5; //nel caso della prima stazione vengono tolti i 5 minuti di attesa
                }

            else
            {
                for (int num_staz = 1; num_staz < station_vect.size(); num_staz++)
                {
                    estimated_time = (double)((station_vect[num_staz].distance - station_vect[num_staz - 1].distance - 10) / (double)(train_vect[num_treno].max_speed)) + (double)((10 * 60) / 80);
                }
            }
        }
        else//se il treno non parte dalla stazione di origine
        {
            if (train_vect[num_treno].type == 1) //se il treno è regionale e si ferma a ogni stazione
                for (int num_staz = principal_stations.size(); num_staz > 0; num_staz--)
                {
                    estimated_time = (double)((principal_stations[num_staz].distance - principal_stations[num_staz - 1].distance - 10) / (double)(train_vect[num_treno].max_speed)) + (double)((10 * 60) / 80) + 5; //tempo previsto per andare da una stazione alla successiva
                    //(distanza fra stazioni - 10km(limite velocità)) / velocità max treno + trmpo per percorrere i 10 km a 80 km/h + 5 min attesa in stazione
                    if (num_staz == principal_stations.size())
                        estimated_time -= 5; //nel caso della prima stazione vengono tolti i 5 minuti di attesa
                }

            else
            {
                for (int num_staz = principal_stations.size(); num_staz > 0; num_staz--)
                {
                    estimated_time = (double)((principal_stations[num_staz].distance - principal_stations[num_staz - 1].distance - 10) / (double)(train_vect[num_treno].max_speed)) + (double)((10 * 60) / 80);
                }
            }
        }
    }
}