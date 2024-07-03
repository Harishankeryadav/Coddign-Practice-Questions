// We are given an array from which we have to find the next smallest element from remaning array.
#include <iostream>
#include <stack>
using namespace std;

void Print(int arr[], int n)
{
    cout << "Print \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void second_smallest(int arr[], int n)
{
    stack<int> s;
    s.push(-1);
    int ans[n];
    for (int i = n - 1; i >= 0; i--)
    {
        cout << "fro loop ";
        int current = arr[i];
        while (s.top() >= current)
        {
            cout << "while  ";
            s.pop();
        }
        ans[i] = s.top();
        cout << "push   ";
        s.push(current);
    }
    Print(ans, n);
}

int main()
{
    int arr[4] = {2, 1, 4, 3};
    second_smallest(arr, 4);
}