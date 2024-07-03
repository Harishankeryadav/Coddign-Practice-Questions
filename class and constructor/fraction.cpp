#include <iostream>
#include <math.h>
using namespace std;

class fraction
{
private:
    int numerator;
    int denominator;

public:
    fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void display()
    {
        cout << numerator << " / " << denominator << endl;
    }

    void simplify()
    {
        int gcd = 1;
        int x = min(numerator, denominator);
        for (int i = 1; i <= x; i++)
        {
            if ((this->numerator % i == 0 )&& (this->denominator % i == 0))
            {
                gcd = i;
            }
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    void add(fraction const &f2)
    {
        this->numerator = this->numerator * f2.denominator + f2.numerator * denominator;
        this->denominator = this->denominator * f2.denominator;

        simplify();
    }
};