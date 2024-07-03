// merging 2 sorted array in another array[sorted].
#include <iostream>
using namespace std;

void merg_sort(int arr[], int size, int arr1[], int size1)
{
    int k = 0, a[size + size1], i = 0, j = 0;

    while (k < size + size1)
    {   if(i == size || j == size1)
    break;
        if (arr[i] < arr1[j])
        {
            a[k] = arr[i];
            i++;
        }
        else if (arr1[j] < arr[i])
        {
            a[k] = arr1[j];
            j++;
        }
        k++;
    }
    while(i < size){
        a[k] = arr[i];
        i++, k++;
    }
    while(j < size1){
        a[k] = arr1[j];
        j++, k++;
    }
    

    for (int i = 0; i < size + size1; i++)
        cout << a[i] << " ";
}

int main()
{
    int arr[] = {1, 9, 10, 12}, arr1[] = {2, 6, 15, 20, 40}, size = 4, size1 = 5;
    merg_sort(arr, size, arr1, size1);
}