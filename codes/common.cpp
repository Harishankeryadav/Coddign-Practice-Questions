// common element in 2 arrays.
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, n1, i, j;
    cout << "Enter the num element on first array ";
    cin >> n;
    cout << "Enter the number of element on second array ";
    cin >> n1;
    int a[n], s[n1];
    cout << "Enter the element of first array ";
    for (i = 1; i <= n; i++)
        cin >> a[i];
    cout << "Enter the element of second array ";
    for (i = 1; i <= n1; i++)
        cin >> s[i];
    cout << "The common elements of both arrays are: ";
    if (n > n1)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (a[i] == s[j])
                {
                    s[j] = INT_MIN;
                    cout << a[i] << " ";
                    break;
                }
            }
        }
    }
    else
    {
        for (i = 1; i <= n1; i++)
        {
            for (j = 1; j <= n1; j++)
            {
                if (s[i] == a[j])
                {
                    a[j] = INT_MIN;
                    cout << s[i] << " ";
                    break;
                }
            }
        }
    }
    return 0;
}