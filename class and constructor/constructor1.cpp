#include<iostream>
#include"constructor.cpp"
using namespace std;

int main(){
    char name[] = {"harry"};
    constructor c1(20,name);

    constructor c2(c1);
    c2.display();
    c1.display();
}