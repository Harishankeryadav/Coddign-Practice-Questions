#include <iostream>
using namespace std;

void rotate_array(int arr[], int n, int r)
{
    int i, j, l = 0, temp = 0;  
    while (l < r)
    {
        for (i = 0; i < n; i++)
        {
            temp = arr[0];
            if (i == n - 1)
            {
                arr[n - 1] = temp;
            }
            
            arr[i] = arr[i + 1];
        }
        l++;
    }
    cout << "Array after rotation ";
    for (i = 0; i < n; i++)
        cout << arr[i] <<" ";
}

int main()
{
    int n, r=2;
    // cout << "Enter the  length  of array ";
    // cin >> n;
    //cout << "Enter the number of rotation ";
    //cin >> r;
    int arr[5] = {1, 2, 3, 4, 5} ;

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    rotate_array(arr, 5, r);
    return 0;
}