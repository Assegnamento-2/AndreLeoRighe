// #include "Train.cpp"
// #include "Train.h"

#include "Railway.cpp"

int main()
{
    Railway ferrovia;
    ferrovia.run();

    //vector<int> trenouno = ferrovia.all_trains[1];
    //cout << ferrovia.all_stations.size() << endl;
    for (int i = 0; i < ferrovia.train_vect.size(); i++) //ALL TRAINS E ALL STATIONS OK! :)
    {
        if (ferrovia.train_vect[i].type == 1)
            cout << "R ";
        if (ferrovia.train_vect[i].type == 2)
            cout << "V ";
        if(ferrovia.train_vect[i].type == 3)
            cout << "S ";

        cout << ferrovia.train_vect[i].name << ": ";
        for (int k = 0; k < ferrovia.train_vect[i].eta.size(); k++)
            cout << ferrovia.train_vect[i].eta[k] << ' ';
        cout << endl;
    }
    for (int i = 0; i < ferrovia.station_vect.size(); i++)
    {
        cout << ferrovia.station_vect[i].name << ' ' << ferrovia.station_vect[i].distance;
        if (ferrovia.station_vect[i].type%2 == 0)
            cout << " P";
        cout << endl;
    }
}