// gfg-> tuf-> array -> easy

#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> v;
    int j = 0, i = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (v.empty() || v.back() != arr1[i] && arr1[i] > v.back())
                v.push_back(arr1[i]);
            i++;
        }

        else if (arr2[j] <= arr1[i])
        {
            if (v.empty() || v.back() != arr1[i] && arr1[i] > v.back())
                v.push_back(arr1[i]);
            j++;
        }
        else
        {
            if (v.empty() || v.back() != arr1[i] && arr1[i] > v.back())
                v.push_back(arr1[i]);
            i++, j++;
        }
    }

    for (; i < n; i++)
    {
        if (v.empty() || v.back() != arr1[i] && arr1[i] > v.back())
            v.push_back(arr1[i]);
    }

    for (; j < m; j++)
    {
        if (v.empty() || v.back() != arr2[j] && arr1[i] > v.back())
            v.push_back(arr2[j]);
    }

    return v;
}

int main()
{
    int v[] = {1, 2, 3, 0, 4, 5};
    int v1[] = {1, 2, 3};

    vector<int> vec = findUnion(v, v1, 6, 3);
    for (auto it : vec)
        cout << it << " ";
    return 0;
}