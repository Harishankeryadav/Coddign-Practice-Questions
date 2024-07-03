// sum of two number from array.
// array must be sorted.
#include <iostream>
using namespace std;

int main()
{
    int n, i, j, sum, temp = 0;
    cout << "Enter the total number \n";
    cin >> n;
    int s[n];
    cout << "Sum equal to ";
    cin >> sum;
    cout << "Enter the digits ";
    for (i = 1; i <= n; i++)
        cin >> s[i];
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (s[i] + s[j] == sum)
                cout << "(" << s[i] << " " << s[j] << ") ";
        }
    }
    return 0;
}