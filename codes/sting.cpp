// string revesing and cin.getline(string_name, string_length, delimiter) using.

#include <iostream>
using namespace std;

int srting_len(char arr[])
{
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++)
        count++;
    return count;
}

void string_rev(char arr[], int len)
{
    int i = 0, j = len - 1;
    char temp;
    while (i < j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++, j--;
    }
    cout << arr <<"\n";
}

void print_prefix(char arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << arr[j];
        }
        cout << " \n";
    }
}

int main()
{
    char arr[100];
    int len;
    cout << "Enter the string ";
    cin.get(arr, 100);
    len = srting_len(arr);
    cout << "The reversed string is = ";
    string_rev(arr, len);
    cout << "The prefixes of the given string is =\n";
    print_prefix(arr, len);
    return 0;
}