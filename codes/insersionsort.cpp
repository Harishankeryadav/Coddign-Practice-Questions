// sorting a single array without swaping.

#include <iostream>
using namespace std;

int main()
{
    int n, temp = 0, num = 0, i, j;
    cout << "Enter the size of array: ";
    cin >> n;
    int s[n];
    for (i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (i = 1; i < n; i++)
    {
        num = s[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (num < s[j])
            {
                s[j + 1] = s[j];
            }
            else
                break;
        }
        s[j + 1] = num;
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
    return 0;
}