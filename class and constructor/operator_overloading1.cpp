#include <iostream>
#include "operator_overloading.cpp"
using namespace std;

int main()
{
    fraction f1(3, 5);
    fraction f2(4, 6);

    fraction f3 = f1 + f2;
    f3.display();
}