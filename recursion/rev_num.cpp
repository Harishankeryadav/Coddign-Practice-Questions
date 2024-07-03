#include <iostream>
using namespace std;

int reverse(int arr[], int size)
{
    if(size < 0){
        return -1;
    }
    cout << arr[size] << " ";
    reverse(arr, size -1);
    return 0;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    reverse(arr,7);
    return 0;
}