#include<iostream>
#include "fraction.cpp"
using namespace  std;

int main(){
    fraction f1(2,4);
    fraction f2(4,5);

    f1.add(f2);

    f1.display();
    f2.display();
    return 0 ;
}