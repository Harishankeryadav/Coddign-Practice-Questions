// searhing an element in array.
#include <iostream>
using namespace std;

int main()
{
    int n, num;
    cout << "Enter the  length of array and number\n";
    cin >> n >> num;
    int s[n];
    cout << "enter the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (num == s[i])
        {
            cout << i;
        }
    }
    return 0;
}