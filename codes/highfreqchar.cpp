// finding the highest occuring character in the given character.

#include <iostream>
#include <cstring>
using namespace std;

void chr_frq(char arr[], int len)
{
    int num = 0, arr1[256] = {NULL}, i = 0, j = 0;
    char x;
    for (i = 0; i <= len - 1; i++)
    {
        num = arr[i];
        arr1[num]++;
    }
    x = arr[0];
    j = arr1[x];

    for (i = 0; i <= len - 2; i++)
    {
        num = arr[i + 1];
        if (j < arr1[num])
        {
            j = arr1[num];
            x = arr[i + 1];
        }
    }
    cout << x;
}
int main()
{
    int len;
    char arr[50];
    cout << "Enter the string ";
    cin.getline(arr, 50);
    len = strlen(arr);
    chr_frq(arr, len);
    return 0;
}