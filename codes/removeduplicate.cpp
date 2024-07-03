// reemoving duplicate character from the string.
#include <iostream>
#include <cstring>
using namespace std;

void remove_duplicate(char arr[], int len)
{
    int i = 0, j = 0, k = 0;
    char temp;
    
        for (i = 1; i <= len - 1; i++)
        { 
            if (arr[i] == arr[i - 1])
            {
                // cout << "in if loop "<< " i and j" <<i <<" "<<j <<"\n"; 
                arr[j] = arr[i];
            }
            else
            { 
                // cout <<" n else loop " <<" i and j" <<i <<" "<<j <<"\n";
                j++;
                arr[j] = arr[i];
            }
        
    }
    arr[j + 1] = '\0';
    cout << "printing the string \n";
    for (j = 0; arr[j] != '\0'; j++)
        cout << arr[j] <<" ";
}
int main()
{
    char arr[50] ;
    int len = 0;
    cout << "Entr the string \n";
    cin >> arr;
    len = strlen(arr);
    remove_duplicate(arr, len);
    return 0;
}