// printing the given matrix row and column wise.
#include <iostream>
using namespace std;

int main()
{
    int arr[10][10], i = 0, j = 0, m = 3, n = 2;
    cout << " Enter the matrix ";
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "printing the array row wise \n";
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "printing the array column wise \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}