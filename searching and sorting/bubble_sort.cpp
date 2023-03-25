// sorting the given array as by comparing the element with its next element and swaping them accordingly.
#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size)
{
    int i = 0, temp = 0;
    for (;i < size - 1;)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        i++;
    }
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {6, 5, 8, 3, 7, 4}, size = 6;
    bubble_sort(arr, size);
}