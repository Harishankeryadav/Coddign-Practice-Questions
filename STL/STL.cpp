#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {1, 7, 3, 2, 8};

    sort(arr, arr + 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (binary_search(arr, arr + 5, 0))
        cout << "element is present ";
    else
        cout << "element is not present ";
}