#include <bits/stdc++.h>
using namespace std;

int divisorSubstrings(int num, int k)
{
    int val = 0;
    int x = 0;
    int num1 = num;
    while (num1 != 0)
    {
        val = val * 10 + num1 % 10;
        num1 /= 10;
    }
    cout << "val " << val << endl; 
    num1 = val;
    while (num1 != 0)
    {
        int i = 0;
        int d = 0;
        while (i < k)
        {
            cout <<i <<"   " << k <<endl;
            d = d * 10 + val % 10;
            val /= 10;
            i++;
        }
        num1 = num1/10;
        val = num1;
        cout << "d " << d <<endl;
        
        if (num % d != 0 ) 
            return -1;
    }

    return k;
}

int main()
{
    int x = 430043;
    int l = 2;
    cout << "ans-> " << divisorSubstrings(x, l);
}