// finding the number by using binnary search method.
// Entered array must be sorted.

#include <iostream>
using namespace std;

int binnary(int array[], int n, int num)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (array[mid] == num)
            return mid;

        else if (array[mid] < num)
            start = mid + 1;

        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int n, num;
    cout << "Enter the length of array \n";
    cin >> n;
    cout << "Enter the number want to find \n";
    cin >> num;
    int s[n];
    cout << "Enter the array \n";
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> s[i];
    }
    cout << "The index num is : " << binnary(s, n, num);
    return 0;
}