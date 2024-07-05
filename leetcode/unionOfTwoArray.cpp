// gfg-> tuf-> easy-> array

#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    // Your code here
    // return vector with correct order of elements
    vector<int> v;
    int j = 0, i = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            v.push_back(arr1[i]);
            if (arr1[i] == arr2[j])
                j++;
            i++;
        }

        if (arr2[j] <= arr1[i])
        {
            v.push_back(arr2[j]);
            if (arr2[j] == arr1[i])
                i++;
            j++;
        }
        cout <<"i " <<i <<" j " << j <<endl;
    }

    for (; i < n; i++)
    {
        k = v.size() - 1;
        if (v[k] != arr1[i])
            v.push_back(arr1[i]);
    }

    for (; j < m; j++)
    {
        k = v.size() - 1;
        if (v[k] != arr2[j])
            v.push_back(arr2[j]);
    }

    return v;
}

int main()
{
    int v[] = {1, 2, 3, 4, 5};
    int v1[] = {1, 2, 3 };

    vector<int> vec = findUnion(v, v1, 5, 3);
    for (auto it : vec)
        cout << it << " ";
    return 0;
}