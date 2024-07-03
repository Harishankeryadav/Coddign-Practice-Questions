#include<iostream>
#include"complex.cpp"
using namespace std;

int main(){
    complex a(5,6);
    complex b(7,8);

    cout<<"check num ";
    int num;
    cin >> num;
    if(num == 1){
    a.add(b);}
    if (num == 2){
        a.multiply(b);
    }
}