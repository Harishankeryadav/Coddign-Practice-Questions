// shorting in assending order -> from small number to large.
#include <iostream>
using namespace std;
int main()
{
    int n, temp = 0;
    cout << "Enter the length of array ";
    cin >> n;
    int s[n];
    cout << "Enter the array ";
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] > s[i + 1])
            {
                temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
    return 0;
}