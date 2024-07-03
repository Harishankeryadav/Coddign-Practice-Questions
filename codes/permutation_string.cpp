// comparing both strings if they are equal or not, their index doesn't matter.
// check string length, number of characters, and their frequencies.
//not working.

#include <iostream>
#include <cstring>
using namespace std;

void permutation_string(char arr1[], char arr2[], int m, int n)
{
    int arr[256] , x = 0, y = 0;
    // cout << "\nbefor both  for loop ";
    for (int i = 0; arr1[i] != '\0'; i++)
    {
        x = arr1[i];
        for (int j = x; j == x; j++)
            arr[x]++;
    }
    // for (int i = 0; i < 256; i++)
    //     cout << arr[i] << " ";
    // cout << "\n";
    for (int i = 0; arr2[i] != '\0'; i++)
    {
        y = arr2[i];
        for (int j = y; j == y; j++)
            arr[y]--;
    }
    // for (int i = 0; i < 256; i++)
    //     cout << arr[i] << " ";
    if (arr == 0)
        cout << " TRUE";
    else
        cout << " FALSE";
}

int main()
{
    int l1, l2;
    char arr1[20] = {'a', 'b', 'a'}, arr2[20] = {'b', 'a', 'a'};
    // cout << "Enter the first string ";
    // cin.getline(arr1, 10);
    // cout << "Enter the secongd string ";
    // cin.getline(arr2, 10);
    l1 = strlen(arr1);
    l2 = strlen(arr2);
    if (l1 == l2)
    {
        // cout << "in if loop";
        permutation_string(arr1, arr2, l1, l2);
    }
    else
    {
        cout << "in else loop. ";
        cout << "string is not permutated string ";
    }
    return 0;
}