

#include "Train.cpp"

class Regional : public Train
{
public:
    Regional()
    {
        std::cout << " Regional.cpp constructor ";
    }
    void Print()
    {
        cout << "\nREG";
    }
};