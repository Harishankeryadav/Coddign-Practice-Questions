#include <iostream>
using namespace std;

void second_largest(int a[], int n)
{
    int l = 0, s = 0, t = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > l)
        {
            t = s;
            s = l;
            l = a[i];
        }
        else if (a[i] > s && a[i] != l)
        {
            t = s;
            s = a[i];
        }
        else if (a[i] > t && a[i] != l && a[i] != s)
        {
            t = a[i];
        }
    }
    cout << "largest number is " << l << ", second largest is " << s << " and Third largest is " << t;
}

int main()
{
    //int a[5] = {1, 3, 9, 7, 9};
    int a[50], len;
    cout << "Enter the length of array = ";
    cin >> len;
    cout << "Enter the  array \n";
    for  (int i = 0; i < len; i++)
    cin >> a[i];
    second_largest(a, len);
    return 0;
}