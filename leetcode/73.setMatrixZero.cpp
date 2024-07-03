#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    vector<int> r(matrix.size(), 1);
    vector<int> c(matrix[0].size(), 1);

    for (int i = 0; i < r.size(); i++)
        cout << r[i] << "  ";

    cout << "\nc's value \n";

    for (int i = 0; i < c.size(); i++)
        cout << c[i] << "  ";

    cout << "setting up the values \n";
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                r[i] = 0;
                c[j] = 0;
            }
        }
    }
    cout << "after 1 for \n";
    for (int i = 0; i < matrix.size(); i++)
    {
        if (r[i] == 0)
            ;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            matrix[i][j] = 0;
        }
    }
    cout << "after 2nd for loop \n";
    for (int i = 0; i < matrix.size(); i++)
    {
        if (c[i] == 0)
        for (int j = 0; j < matrix[i].size(); j++)
        {
            matrix[j][i] = 0;
        }
    }
}

void print(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << "  ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> v = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(v);
    cout << "printing the values \n";
    print(v);
    return 0;
}