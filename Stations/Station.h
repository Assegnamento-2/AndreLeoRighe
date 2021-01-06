#include "Railway.h"
#include "Train.h"

class Station : public Railway
{
public:
    Station(int index);
    
    vector<Train> elenco;
    const string name;
    const int type;
    const string distance;
};