// check the given number lies on what index
#include <iostream>
using namespace std;

int check_number(int arr[], int s, int size, int key)
{
    if (s == size)
        return -1;
    if (arr[s] == key)
        return s;
    int num = check_number(arr, s + 1, size, key);
    return num;
}

int main()
{
    int arr[] = {1, 2, 5, 4, 5}, size = 5, key = 1;
    cout << check_number(arr, 0, size, key);
}