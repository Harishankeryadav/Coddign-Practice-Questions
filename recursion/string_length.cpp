// finding the length of the given array or string.
#include <iostream>
using namespace std;

void removeX(char arr[])
{
    if (arr[0] == '\0')
        return;
    if (arr[0] != 'x')
    {
        removeX(arr + 1);
    }

    else
    {
        int i = 1;
        for (; arr[i] != '\0'; i++)
            arr[i - 1] = arr[i];

        arr[i - 1] = arr[i];
        removeX(arr);
    }
}
int length(char arr[])
{
    static int x = 0;
    if (arr[0] == '\0')
        return 0;
    x = length(arr + 1);
    return 1 + x;
}

int main()
{
    char arr[100];
    cout << "Enter the string ";
    // cin.getline(arr, 100);
    cin >> arr;
    cout << "\nLength of the given string is : " << length(arr)<<endl;
    removeX(arr);
    cout<< length(arr)<<endl;
    cout << arr;
}