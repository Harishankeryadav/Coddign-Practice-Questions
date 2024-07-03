#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subArraySum(vector<int> v, int sum)
{
    int i = 0;
    int j = 0;
    int total = 0;

    while (i < v.size())
    {
        if (total == sum)
        {
            cout << v[j] << "  " << v[i - 1];
            total += v[i];
            i++;
        }
        // if (total == sum) {
        //     cout  << v[j] << " and " << v[i - 1] << ": ";
        //     // for (int k = j; k < i; k++) {
        //     //     cout << v[k] << " ";
        //     // }
        //     // cout << endl;
        //     total -= v[j];
        //     j++;
        // }
        else if (total < sum)
        {
            total += v[i];
            i++;
        }
        else
        {
            total -= v[j];
            j++;
        }
    }
}

int main()
{
    vector<int> v = {5, 2, 9, 1, 5};
    subArraySum(v, 16);
}