#include <iostream>
using namespace std;

class complex
{
private:
    int real;
    int complex1;

public:
    complex(int real, int complex2)
    {
        this->real = real;
        this->complex1 = complex2;
    }
    void print(){
        cout << real << " + i" << complex1<<endl;
    }
    void mul(){
        cout << real<<" i"<<complex1;
    }

    void add(complex const &o2)
    {
        real = real + o2.real;
        complex1 = complex1 + o2.complex1;
        print();
    }

    void multiply(complex const &o1){
        real = real * o1.real;
        complex1 = complex1*o1.complex1;
        mul();
    }
};