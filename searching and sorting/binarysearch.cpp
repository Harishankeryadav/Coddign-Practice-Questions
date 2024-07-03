// for binary search the given array must be sorted.
#include <iostream>
using namespace std;

int binary_search(int arr[], int start, int end, int key)
{
    end = end - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            cout << "Value found at index ";
            return mid;
        }
        if (arr[mid] > key)
        {
            end = mid - 1;
        }
        if (arr[mid] < key)
        {
            start = mid + 1;
        }
    }
    cout << "value not found \n";
        return -1;
}
int main()
{
    int arr[] = {4, 23, 45, 64, 65, 86}, size = 6, key = 60, start = 0;
    cout << binary_search(arr, start, size, key);
}