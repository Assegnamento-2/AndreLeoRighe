// #include "Train.cpp"
// #include "Train.h"

#include "Railway.cpp"

int main()
{
    Railway prova1;
    // Train s;
    // Regional k;
    // int i = 0;

    // cout<<prova1.trenivect[1].max_speed;
    vector<int> trenouno = prova1.all_trains[1];
    cout << prova1.all_stations.size() << endl;
    for (int i = 0; i < prova1.all_stations.size(); i++) //ALL TRAINS E ALL STATIONS OK! :)
    {
        for (auto k : prova1.all_stations[i])
            cout << k << " ";
        cout << endl;
    }
}