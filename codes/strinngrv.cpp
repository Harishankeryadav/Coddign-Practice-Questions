// string reversing.
#include <iostream>
using namespace std;

int string_len(char s[])
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
        count++;
    return count;
}

int main()
{
    int n;
    char s[100], temp;
    cout << "enter the string \n";
    cin.getline(s, 100);
    cout << "The reverse of the given string is\n";
    n = string_len(s) - 1;
    for (int i = 0; i <= (n - 1) / 2; i++)
    {
        temp = s[i];
        s[i] = s[n - i];
        s[n - i] = temp;
    }
    cout << s;
    return 0;
}