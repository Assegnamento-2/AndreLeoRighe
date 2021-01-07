#include "Train.cpp"
class Regional : public Train
{
public:
    Regional(vector<int> &vect) //costruttore di Train: riceve come parametro un int corrispondente alla riga nel timetables del treno da creare
        : Train(vect)           //inizializza le vaariabili tramite il costruttore di Train
    {
        max_speed = (double)160 / 60;
    }
};