// // remove character from given string.

// #include <iostream>
// #include <cstring>
// using namespace std;

// void remove_char(char arr[], char ch, int len)
// {
//     for (int i = 0; i <= len - 1; i++)
//     {
//         if (arr[i] == ch)
//         {
//             for (int j = i; arr[j] != '\0'; j++)
//             {
//                 arr[j] = arr[j + 1];
//             }
//         }
//     }
//     cout << "The string after removing wanted character is \n"
//          << arr;
// }

// int main()
// {
//     char arr[100], ch;
//     int len;
//     cout << "Enter the string ";
//     cin.get(arr, 100);
//     cout << "Enter the char to remove from string = ";
//     cin >> ch;
//     len = strlen(arr);
//     remove_char(arr, ch, len);
//     return 0;
// }

// another and better aproach!
#include <iostream>
#include <cstring>
using namespace std;

void remove_character(char arr[], char ch, int len)
{
    int i = 0, j = 0;
    for (i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == ch)
        {
            continue;
        }

        else
        {
            arr[j] = arr[i];
            j++;
        }
    }
    arr[j] = '\0';
    cout << "The string after removing wanted character is \n"
         << arr;
}
int main()
{
    int len = 0;
    char arr[100], ch;
    cout << "Enter the string ";
    cin.get(arr, 100);
    cout << "Enter the character ";
    cin >> ch;
    len = strlen(arr);
    remove_character(arr, ch, len);
    return 0;
}