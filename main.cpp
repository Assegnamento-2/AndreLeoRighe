#include "Railway.h"

int main()
{
    Railway prova1;
    vector<int> trenouno=prova1.all_trains[1];
    //Train uno(trenouno);
    cout<<prova1.all_trains.size();
    for (int i = 0; i < prova1.all_trains.size(); i++) //ALL TRAINS E ALL STATIONS OK! :)
    {
        for (auto k : prova1.all_trains[i])
            cout << k << "/";
        cout << endl;
    }
}