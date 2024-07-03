#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2)
{
    int temp1 = 0, i = 0, j = 0;
    vector<int> v;

    // Convert num1 to integer
    for (int i = 0; i < num1.size(); i++)
    {
        temp1 = temp1 * 10 + (num1[i] - '0');
    }
    while (i < num2.size())
    {
        
        int x = temp1*num1[i];


    }
}

int main()
{
    string x = "123456789";
    string y = "987654321";
    cout << "output-> " << multiply(x, y); 
}