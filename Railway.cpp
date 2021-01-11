#include "Railway.h"

Railway::Railway()
{
    getLineDescription();
    getTimetable();

    checkTimetables();
    run();
}
bool Railway::compareStations(vector<string> &uno, vector<string> &due) //serve per ordinare le stazioni quando viene letto il line_description
{
    return stoi(uno[2]) < stoi(due[2]);
}
bool Railway::compareTrainsStart(vector<int> &uno, vector<int> &due) //serve per ordinare i treni quando viene letto il timetable
{
    if (uno[3] == due[3]) //a parità di orario, il treno più veloce parte prima
        return uno[2] > due[2];
    return uno[3] < due[3];
}
bool Railway::compareTrainsPos(Train &uno, Train &due) //serve per ordinare i treni durante la gestione della giornata
{
    if (uno.current_pos == due.current_pos) //a parità di posizione, il treno che attende da più tempo verrà gestito prima
        return uno.wait > due.wait;
    return uno.current_pos > due.current_pos;
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
            arr.push_back(-1);
        }
        all_trains.push_back(arr);
    }
    input.close();
    for (int i = 0; i < all_trains.size(); i++)
    {
        if (all_trains[i][0] < 0) //se il nome del treno è un numero negativo, lo sostituisce con il suo opposto
        {
            all_trains[i][0] *= -1;
        }
        if (all_trains[i][1] != 1) //controlla la stazione di partenza sia accettabile, altrimenti assegna la stazione di origine
        {
            all_trains[i][1] = 0;
        }
        if (all_trains[i][2] != 1 && all_trains[i][2] != 2) //controlla che il tipo di treno sia accettabile, altrimenti gli assegna il ruolo di treno superveloce
        {
            all_trains[i][2] = 3;
        }
        if (all_trains[i][3] < 0) //controlla che l'orario di partenza sia accettabile, altrimenti lo setta a 0
        {
            all_trains[i][3] = 0;
        }
    }
    sort(all_trains.begin(), all_trains.end(), compareTrainsStart);

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
        all_stations.push_back(arr); //associo ad un elemento del vettore di STAZIONI il vettore del singolo treno
    }
    input.close();
    for (int i = 1; i < all_stations.size(); i++)
    {
        if (stoi(all_stations[i][1]) != 1) //controlla che il tipo di stazione sia accettabile, altrimenti le assegna il ruolo di stazione principale
        {
            all_stations[i][1] = "0";
        }
        sort(all_stations.begin(), all_stations.end(), compareStations); //ordina le stazioni

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
    all_stations[all_stations.size() - 1][1] = "0"; //setta la stazione capolinea come principale

    for (int i = 0; i < all_stations.size(); i++) //crea le stazioni e le inserisce nel vettore di stazioni
    {
        vector<string> vect = all_stations[i];
        vect.push_back(to_string(i));
        if (i > 0) //aggiunge il parametro della distanza della stazione precedente rispetto all'origine(utile per la gestione della tratta)
        {
            vect.push_back(all_stations[i - 1][2]);
        }
        else //nel caso della prima stazione inserisce come distanza della stazione precedente rispetto all'origine -1
            vect.push_back("-1");
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
    for (int i = 0; i < station_vect.size(); i++) //riempie il vettore delle stazioni principali
    {
        if (station_vect[i].type == 0)
        {
            principal_stations.push_back(station_vect[i]);
        }
    }
}
void Railway::checkTimetables()
{
    for (int num_treno = 0; num_treno < train_vect.size(); num_treno++)
    {
        if (train_vect[num_treno].type != 1) //se il treno è veloce o superveloce viene accorciato il vettore dei tempi di arrivo previsti, dato che si dovrà fermare in meno stazioni
            train_vect[num_treno].eta.resize(principal_stations.size());

        double estimated_time = train_vect[num_treno].start_time;

        if (train_vect[num_treno].start_station == 0) //se il treno parte dalla stazione di origine
        {
            if (train_vect[num_treno].type == 1) //se il treno è regionale e si ferma a ogni stazione
                for (int num_staz = 1; num_staz < station_vect.size(); num_staz++)
                {
                    estimated_time += (double)(station_vect[num_staz].distance - station_vect[num_staz - 1].distance - 10) / train_vect[num_treno].max_speed + (double)((10 * 60) / 80) + 5;
                    //(distanza fra stazioni - 10km(limite velocità)) / velocità max treno + trmpo per percorrere i 10 km a 80 km/h + 5 min attesa in stazione
                    if (num_staz == 1)
                        estimated_time -= 5; //nel caso della prima stazione vengono tolti i 5 minuti di attesa
                    setETA(num_treno, num_staz, ceil(estimated_time));
                    estimated_time = train_vect[num_treno].eta[num_staz];
                }

            else //se il treno è veloce o superveloce e si ferma solo nelle stazioni  principali
            {
                for (int num_staz = 1; num_staz < principal_stations.size(); num_staz++)
                {
                    estimated_time += (double)(principal_stations[num_staz].distance - principal_stations[num_staz - 1].distance - 10) / train_vect[num_treno].max_speed + (double)(10 * 60) / 80 + 5;
                    //(distanza fra stazioni - 10km(limite velocità)) / velocità max treno + trmpo per percorrere i 10 km a 80 km/h + 5 min attesa in stazione
                    if (num_staz == 1)
                        estimated_time -= 5; //nel caso della prima stazione vengono tolti i 5 minuti di attesa
                    setETA(num_treno, num_staz, ceil(estimated_time));
                    estimated_time = train_vect[num_treno].eta[num_staz];
                }
            }
        }
        else //se il treno non parte dalla stazione di origine
        {
            if (train_vect[num_treno].type == 1) //se il treno è regionale e si ferma a ogni stazione
                for (int num_staz = station_vect.size() - 1; num_staz > 0; num_staz--)
                {
                    estimated_time += (double)(station_vect[num_staz].distance - station_vect[num_staz - 1].distance - 10) / train_vect[num_treno].max_speed + (double)((10 * 60) / 80) + 5;
                    //(distanza fra stazioni - 10km(limite velocità)) / velocità max treno + trmpo per percorrere i 10 km a 80 km/h + 5 min attesa in stazione
                    if (num_staz == station_vect.size() - 1)
                        estimated_time -= 5; //nel caso della prima stazione vengono tolti i 5 minuti di attesa
                    setETA(num_treno, num_staz, ceil(estimated_time));
                    estimated_time = train_vect[num_treno].eta[station_vect.size() - num_staz];
                }

            else //se il treno è veloce o superveloce e si ferma solo nelle stazioni  principali
            {
                for (int num_staz = principal_stations.size() - 1; num_staz > 0; num_staz--)
                {
                    estimated_time += (double)(principal_stations[num_staz].distance - principal_stations[num_staz - 1].distance - 10) / train_vect[num_treno].max_speed + (double)(10 * 60) / 80 + 5;
                    //(distanza fra stazioni - 10km(limite velocità)) / velocità max treno + trmpo per percorrere i 10 km a 80 km/h + 5 min attesa in stazione
                    if (num_staz == principal_stations.size() - 1)
                        estimated_time -= 5; //nel caso della prima stazione vengono tolti i 5 minuti di attesa
                    setETA(num_treno, num_staz, ceil(estimated_time));
                    estimated_time = train_vect[num_treno].eta[principal_stations.size() - num_staz];
                }
            }
        }
    }
}
void Railway::setETA(int treno, int stazione, int checked_eta) //modifica l'ETA
{
    if (train_vect[treno].start_station == 0)
    {
        if (train_vect[treno].eta[stazione] < 0) //se non era presente viene settato con i tempi minimi previsti + un margine di 10 minuti
            train_vect[treno].eta[stazione] = checked_eta + 10;

        else if (train_vect[treno].eta[stazione] < checked_eta) //se l'ETA era presente ma non compatibile con i limiti di velocità, viene modificato con i tempi di percorrenza più brevi compatibili con tali limiti
            train_vect[treno].eta[stazione] = checked_eta;
    }
    else
    {
        if (train_vect[treno].type == 1)
        {
            if (train_vect[treno].eta[station_vect.size() - stazione] < 0) //se non era presente viene settato con i tempi minimi previsti + un margine di 10 minuti
                train_vect[treno].eta[station_vect.size() - stazione] = checked_eta + 10;

            else if (train_vect[treno].eta[station_vect.size() - stazione] < checked_eta) //se l'ETA era presente ma non compatibile con i limiti di velocità, viene modificato con i tempi di percorrenza più brevi compatibili con tali limiti
                train_vect[treno].eta[station_vect.size() - stazione] = checked_eta;
        }
        else
        {
            if (train_vect[treno].eta[principal_stations.size() - stazione] < 0) //se non era presente viene settato con i tempi minimi previsti + un margine di 10 minuti
                train_vect[treno].eta[principal_stations.size() - stazione] = checked_eta + 10;

            else if (train_vect[treno].eta[principal_stations.size() - stazione] < checked_eta) //se l'ETA era presente ma non compatibile con i limiti di velocità, viene modificato con i tempi di percorrenza più brevi compatibili con tali limiti
                train_vect[treno].eta[principal_stations.size() - stazione] = checked_eta;
        }
    }
}
void Railway::run()
{
    int arrived_trains = 0;
    bool stop = false;
    for (int time = 0; !stop; time++)
    {
        //sort(train_vect.begin(), train_vect.end(), compareTrainsPos); //ordina i treni per posizione(decrescente) ed eventualmente tempo di attesa FUNZIONA??
        //for (auto train : train_vect)
        for (int train = 0; train < train_vect.size(); train++) //setta il moved di tutti i treni a falso. si può fare nel for successivo?
            train_vect[train].moved = false;
        // for (int num_staz = 1; num_staz < station_vect.size(); num_staz++)
        bool is_not_first_station = false;
        //for (auto station : station_vect)
        for (int station = 0; station < station_vect.size(); station++)
        {
            if (is_not_first_station)
            {
                vector<Train> train_manage;
                for (auto train : train_vect)
                {
                    if (train.current_pos <= station_vect[station].distance + 5 && !train.moved)
                    {
                        train_manage.push_back(train);
                    }
                    if (train.current_pos >= station_vect.back().distance) //se un treno è arrivato all'ultima stazione, aumenta il contatore dei treni arrivati
                    {
                        arrived_trains++;
                    }
                }
                if (!train_manage.empty()) //se il vettore di treni che la stazione deve gestire non è vuoto
                {
                    station_vect[station].manage(train_manage, time);       //viene chiamata la funzione per la gestione dei treni
                    for (int train = 0; train < train_vect.size(); train++) //copia eventuali modifiche ai treni di train_start nei corrispettivi treni di train_vect
                        for (auto updated : train_manage)
                            if (train_vect[train].name == updated.name)
                            {
                                train_vect[train] = updated;
                            }
                }
            }
            else
            {
                vector<Train> train_start;
                for (auto train : train_vect)
                {
                    if (train.current_pos <= 5)
                    {
                        train_start.push_back(train);
                    }
                }
                if (!train_start.empty()) //se il vettore di treni che la stazione deve gestire non è vuoto
                {
                    station_vect[station].start(train_start, time);
                    for (int train = 0; train < train_vect.size(); train++) //copia eventuali modifiche ai treni di train_start nei corrispettivi treni di train_vect
                        for (auto updated : train_start)
                            if (train_vect[train].name == updated.name)
                            {
                                train_vect[train] = updated;
                            }
                }
                is_not_first_station = true;
            }
        }
        // if (arrived_trains == train_vect.size()-1)//se tutti i treni sono arrivati ferma il ciclo
        if (time >= 500)
            stop = true;
    }
}

// railway r; -> crea un treno di tipo regional

// regional.move()
// trainvect[2].max_speed

// for (auto train : train_vect)
//     train.updatePosition();
