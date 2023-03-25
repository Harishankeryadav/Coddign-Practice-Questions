//arranging zero's at one side.

#include <iostream>
using namespace std;

void push_zero(int s[], int n)
{

    int i, j, temp = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (s[i] < s[j])
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
}

int main()
{
    int n;
    cout << "enter the length of arrey ";
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    push_zero(s, n);
    return 0;
}