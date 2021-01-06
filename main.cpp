#include "Railway.cpp"

int main()
{
    Railway prova1;
    //prova1.getLineDescription();
    cout<<prova1.all_stations.size();
    for (int i = 0; i < prova1.all_trains.size(); i++) //ALL TRAINS E ALL STATIONS OK! :)
    {
        for (auto k : prova1.all_trains[i])
            cout << k << "/";
        cout << endl;
    }
}