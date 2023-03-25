// In this method we sort the element without swapping. Here, we first take the element compare it with left of right elemene
// According to ascending or descending order. and then shift the other elements and put that element in its right position.
#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size)
{
    int temp = 0, i, j = 1, k = 0, index;
    while (k < size - 1)
    {
        temp = arr[j];
        for (i = j - 1; i >= 0; i--)
        {
            if (temp < arr[i])
            {
                arr[i + 1] = arr[i];
            }
            else
                break;
        }
        
            arr[i + 1] = temp;
        j++;
        k++;
    }

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {7, 8, 1, 2, 5, 9, 6}, size = 7;
    insertion_sort(arr, size);
}