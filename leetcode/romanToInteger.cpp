#include<iostream>
#include<string>
using namespace std;

// char I  ='1';
// char V = '5';
// char X = '10';
// char L = '50';
// char C = '100';
// char D = '500';
// char M = '1000';

int main(){

string s = "MCMXCIV";

// void romanNumber(s){
    // string temp = s;
    int sum = 0;

    for(int i = 0; i < s.length(); i++){
        char y = s[i];
        switch(y){
            case 'I':
                sum = sum + 1;
                break;
            case 'V':
                sum = sum + 5;
                break;
            case 'X':
                sum = sum  + 10;
                break;
            case 'L':
                sum = sum + 50;
                break;
            case 'C':
                sum = sum + 100;
                break;
            case 'D':
                sum = sum  + 500;
                break;
            case 'M':
                sum = sum + 1000;
                break;        
        }
    }
    cout << sum <<" \n"<<endl;
// }
return 0;
}