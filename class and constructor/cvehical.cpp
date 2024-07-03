#include <iostream>
using namespace std;

class vehical
{
public:
    int gear;
    int wheeler;
    char colour;

    vehical()
    {
        cout << "constructor of vehiul ";
    }
    vehical(char colour, int gear = 0, int wheeler = 0)
    {
        this->gear = gear;
        this->wheeler = wheeler;
        this->colour = colour;
    }

    // void print()
    // {
    //     cout << "colour : " << colour << endl;
    //     cout << "wheeler : " << wheeler << endl;
    //     cout << "gear : " << gear << endl;
    // }
    ~vehical()
    {
    }
};