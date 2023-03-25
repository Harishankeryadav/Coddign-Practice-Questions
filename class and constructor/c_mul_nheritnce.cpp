#include <iostream>
#include "cvehical.cpp"
#include "ccar.cpp"
using namespace std;

int main()
{
    int gear, wheeler, distance, time;
    char colour = 'b';
    cout << "enter these data gear, wheeler, distance, time";
    cin >> gear >> wheeler >> distance >> time;
    car c(distance, time, colour, gear, wheeler);
    //vehical v(colour, gear, wheeler);
    c.print();
    // v.print();
}