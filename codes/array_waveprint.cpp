// printing the array in wave form.
#include <iostream >
using namespace std;

void wave_print(int arr[][20], int m, int n)
{
    int r = 0, R = m, c = n, i = 0, j = 0;
    cout << "Printing the wave print loop \n";
    while (R != 0 && c != 0)
    {

        if (r % 2 == 0)
        {
            for (i = r; i == r; i++)
            {
                for (j = 0; j < n; j++)
                    cout << arr[j][i] << " ";
                
            }
        }
        else
            for (j = r; j == r; j++)
            {
                for (i = n - 1; i >= 0; i--)
                {
                    cout << arr[i][j] << " ";
                }
                
            }
        r++;
        R--, c--;
    }
}

int main()
{
    int arr[20][20], m, n;
    cout << "Enter the size of array ";
    cin >> m >> n;
    cout << "Enter the 3D array ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    wave_print(arr, m, n);
    return 0;
}