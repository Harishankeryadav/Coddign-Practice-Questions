// merging of 2 sorted array in 3rd array in sorted form.

#include <iostream>
using namespace std;
int main()
{
    int n = 5, n1 = 6, k = 0, i = 0, j = 0;
    // cout << "Enter the size of 1st and 2nd array ";
    // cin >> n >> n1;
    int a[n] = {2, 5, 9, 15, 25}, s[n1] = {3, 4, 6, 8, 11, 12}, d[n + n1];

    // cout << "Enter the element of the arrays\n";
    // for (i = 0; i < n; i++)
    //     cin >> a[n];
    // cout << "2nd array element \n";
    // for (j = 0; j < n1; j++)
    //     cin >> s[n1];
    while (i < n && j < n1)
    {
        if (a[i] <= s[j])
        {
            d[k] = a[i];
            i++;
        }
        else
        {
            d[k] = s[j];
            j++;
        }
        k++;
    }
    cout <<i<<" "<<j<<endl;
   while(i < n){
        d[k] = a[i];
        i++,k++;
    }
     while(j < n1){
        d[k] = s[j];
        j++,k++;
    }

    for (int i = 0; i < n + n1; i++)
        cout << "index " << i << " element " << d[i] << "    ";
    return 0;
}