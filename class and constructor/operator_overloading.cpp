//operator overloading(==, +, *), And using static and const function.
#include<iostream>
using namespace std;

class fraction{
        const int numerator;
        const int denominator;
    public:

        fraction (int numerator, int denominator){
            this->numerator = numerator;
            this-> denominator=denominator;
        }

        void display(){
            cout << f3.numerator<<" "<<f3.denominator;
        }
        fraction operator+(fraction f1)const{
            fraction f3 = f1 + f2;
            return f3;
        }

};