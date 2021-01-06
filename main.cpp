#include "Railway.cpp"

int main()
{
    Railway prova1;
    prova1.getLineDescription("line_description.txt");
    for (int i = 0; i < prova1.all_stations.size(); i++) //ALL TRAINS E ALL STATIONS OK! :)
    {
        for (auto k : prova1.all_stations[i])
            cout << k << "/";
        cout << endl;
    }
}