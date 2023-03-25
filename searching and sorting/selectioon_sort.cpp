// in this method we first travell in the given array and fing out the smallest element and put it in its posion.
//  we travel n-1 times
#include <iostream>
using namespace std;

void selection_sort(int arr[], int size)
{
    int temp = 0, j = 0, k = 0, temp1 = 0;

    while (k < size - 1)
    {
            temp = arr[j];
        for (int i = j+1; i < size; i++)
        {
            if (temp > arr[i])
            {
                temp1 = i;
                temp = arr[temp1];
            }
        }
        temp = arr[j];
        arr[j] = arr[temp1];
        arr[temp1] = temp;
        j++;
        k++;
    }
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {7, 8, 1, 2, 5, 9, 6}, size = 7;
    selection_sort(arr, size);
}