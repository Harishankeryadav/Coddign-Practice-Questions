// finding unpaired/ unique number in an array.

#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n = 6, i, j, count = 0, temp = 0;
    cout << "Enter the size of array \n";
    cin >> n;
    int a[n];
    // int a[n] = {7, 5, 0, 5, 7, 9};
    cout << "Enter the array : \n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "The unpaired number is ";
    for (i = 0; i < n; i++)
    {
        temp = a[i];
        for (j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }
            else if (a[j] == a[i])
            {
                temp = INT_MIN;
            }
        }
        if (temp != INT_MIN)
            cout << temp << " ";
    }
    return 0;
}