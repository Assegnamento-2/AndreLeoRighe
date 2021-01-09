// #include "Train.cpp"
// #include "Train.h"

#include "Railway.cpp"

int main()
{
    Railway prova1;
    // Train s;
    // Regional k;

    vector<int> trenouno = prova1.all_trains[1];
    //cout << prova1.all_stations.size() << endl;
    for (int i = 0; i < prova1.train_vect.size(); i++) //ALL TRAINS E ALL STATIONS OK! :)
    {
        cout << prova1.train_vect[i].name << ' ';
        for (int k = 0; k < prova1.train_vect[i].eta.size(); k++)
            cout << prova1.train_vect[i].eta[k] << ' ';
        cout << endl;
    }
    // for (int i = 0; i < prova1.all_stations.size(); i++)
    // {
    //     for (int k = 0; k < prova1.all_stations[i].size(); k++)
    //     {
    //         cout << prova1.all_stations[i][k] << ' ';
    //     }
    //     cout << endl;
    // }
}