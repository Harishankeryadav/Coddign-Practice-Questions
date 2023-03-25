// adding/sum two arrays.

#include <iostream>
using namespace std;

void add_two_array(int arr1[], int arr2[], int l1, int l2)
{
    int carry = 0, num = 0, sum = 0, i = l1 - 1, j = l2 - 1;
    while (i >= 0 || j >= 0)
    {
        if (i >= 0 && j >= 0)
        {
            sum = arr1[i] + arr2[j] + carry;
        }
        else if (j >= 0)
            sum = arr1[j] + carry;
        else
            sum = arr1[i] + carry;
        carry = 0;

        if (sum >= 10)
        {
            num = sum % 10;
            carry = sum / 10;
            arr1[i] = num;
        }
        else
            arr1[i] = sum;

        i--, j--;
    }
    cout << "Printing the sum of both array \n";
    for (i = 0; i < l1; i++)
        cout << arr1[i] << " ";
}
int main()
{
    int l1, l2, i, j;
    cout << "Enter the length of both arrays ";
    cin >> l1 >> l2;
    int arr1[l1], arr2[l2];
    cout << "Enter the first array ";
    for (i = 0; i < l1; i++)
        cin >> arr1[i];
    cout << "Enter the second array ";
    for (i = 0; i < l2; i++)
        cin >> arr2[i];
    if (l1 >= l2)
        add_two_array(arr1, arr2, l1, l2);
    else
        add_two_array(arr2, arr1, l2, l1);
    return 0;
}