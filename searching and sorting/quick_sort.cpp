// take the first element and place it in its actual place after that arrange the small element on its left and big element
// on the right side of that element. and then sort the both sides.
#include <iostream>
using namespace std;

void quick_sort(int arr[], int end, int x)
{
    int i = 0, j = x + 1, temp = 0;
    for (int k = 0; k < x; k++)
    {
        if (arr[i] > arr[x])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++, j++;
        }
        else
            i++, j++;
    }

    for (int i = 0; i < end; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {7, 6, 3, 5, 1, 9, 8}, size = 7;
    int start = 0, temp = 0, x = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[0] >= arr[i])
        {
            cout << arr[i] << " ";
            x++;
        }
    }
    cout <<endl<< x << endl;
    temp = arr[0];
    arr[0] = arr[x];
    arr[x] = temp;
    quick_sort(arr, size, x);
}