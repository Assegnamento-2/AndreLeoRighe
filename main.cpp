#include "Railway.cpp"

int main()
{
    Railway prova1;
    Train uno(2);
    cout<<prova1.all_trains.size();
    for (int i = 0; i < prova1.all_trains.size(); i++) //ALL TRAINS E ALL STATIONS OK! :)
    {
        for (auto k : prova1.all_trains[i])
            cout << k << "/";
        cout << endl;
    }
}