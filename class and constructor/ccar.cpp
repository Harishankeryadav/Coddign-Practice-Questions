#include <iostream>
// #include "cvehical.cpp"
using namespace std;

class car : public cvehical
{
public:
    int speed = 0;
    int distance = 0;
    int time = 0;

    car()
    {
    }
    car(int distance, int time, char colour, int gear, int wheeler) : cvehical(colour, gear, wheeler)
    {
        this->distance = distance;
        this->time = time;
    }
    void car_time()
    {
        this->speed = distance / time;
    }
    void print()
    {
        cout << "colour : " << colour << endl;
        cout << "wheeler : " << wheeler << endl;
        cout << "gear : " << gear << endl;
        cout << "The speed of the car is : " << speed << endl;
    }
};