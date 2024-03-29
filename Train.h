//Jacopo Righetto

#ifndef TRAINH
#define TRAINH
#include "RootTrain.h"
class Train : public RootTrain
{
public:
    Train(vector<int> &vect);
    Train &operator=(const Train &original); //assegnamento di copia
    void setSpeed(double speed);
    void setSpeedLimit();
    void updatePosition();
    int name; //per il const probabilmente serve il move constructor
    int start_station;
    int start_time;     //può essere modificato in caso di treni con partenza ravvicinata
    int type;           //specifica il tipo di treno(regionale, veloce o superveloce)
    bool moved = false; //in run(railway.cpp) serve per verificare se il treno è già stato mosso nel minuto
    bool is_parked = false;
    bool has_arrived = false;
    vector<int> eta;        //vettore che contiene gli Estimated Time of Arrival
    double current_pos = 0; //se il treno parte dal capolinea?
    double current_speed = 0;
    double max_speed;
    int wait = 0;
    int delay = 0;
};
#endif
