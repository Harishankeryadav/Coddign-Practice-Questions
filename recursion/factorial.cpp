#include<iostream>
using namespace std;

int factorial(int num){
    if(num == 1 || num == 0)
        return 1;
    int fact = num * factorial(num - 1);
    return fact;
}

int main(){
    int num;
    cout <<"Enter the number \n";
    cin >> num;
    cout << factorial(num);
}