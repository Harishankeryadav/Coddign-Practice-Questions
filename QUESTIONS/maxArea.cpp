// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int maxArea(vector<int> &height)
// {
//     int a = 0, na = 0, x = 0;
//     int j = height.size();
//     cout << j << " heoght " << endl;

//     while (j > 0)
//     {
//         // cout << "j loop \n";
//         int i = 1;
//         while (i < j)
//         {
//             int l1 = height[i];
//             int l2 = height[j];
//             x = min(l1, l2);
//             na = (j - i) * x;
//             a = max(a, na);
//             i++;
//             // cout <<"i loop \n";
//         }
//         j--;
//     }
//     return a;
// }

// int reverse(int x)
// {

//     int ans = 0;
//     while (x != 0)
//     {

//         int digit = x % 10;
//         if ((ans > INT32_MAX / 10) || (ans < INT32_MIN / 10))
//         {
//             return 0;
//         }
//         ans = (ans * 10) + digit;
//         x = x / 10;
//     }
//     return ans;
// }

// void rotate(vector<vector<int>> &matrix)
// {
//     int i = 0;
//     int n = matrix.size();
//     vector<vector<int>> v(n, vector<int>(n));
//     int column = 0;

//     while (column < matrix.size())
//     {
//         // cout << "while c\n";
//         int row = matrix.size() - 1;
//         // cout << "row-> " << row << endl;
//         int j = 0;
//         while (row >= 0)
//         {
//             // cout << "while r val->" << matrix[row][column] << endl;
//             // cout << "r-> " << row << " c -> " << column << endl;
//             // cout << "i-> " << i << " j -> " << j << endl;

//             v[i][j] = matrix[row][column];
//             row--;
//             j++;
//         }
//         i++;
//         column++;
//         cout << endl;
//     }

//     // for (i = 0; i < v.size(); i++)
//     // {
//     //     for (int j = 0; j < v[i].size(); j++)
//     //     {
//     //         cout << v[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }
// }

// int main()
// {
//     // vector<int> x = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//     // int a = maxArea(x);
//     // int x = 2534236469;
//     // int a = reverse(x);
//     // cout << a;
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}};
//     int row = matrix.size();
//     int c = matrix[1].size();
//     // cout << "r-> " << row << " c -> " << c;
//     for (int i = 0; i < matrix.size(); i++)
//     {
//         for (int j = 0; j < matrix[i].size(); j++)
//         {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
//     rotate(matrix);
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rev(string s)
{
    int x = 0;
    cout << "s-> " << s << endl;

    // for (int i = s.size() - 1; i >= 0; i--)
    // {
    //     char n = s[i];
    //     int asc = n - '0';
    //     x = x * 10 + asc;
    // }
    int a = 0;
    int n = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        n = s[i];
        long int asc = n - '0';
        if (n == 45)
            a++;
        if (n >= 48 && n <= 57)
        {
            x = x * 10 + (n - '0');
        }
    }
    if ((n < 48 && n != 45) || (n > 57 && n != 45))
    {
        cout << 0<<" n -> "<<n <<endl;
        return;
    }
    cout << "x-> " << x << endl;
    int num = 0, num1 = 0;
    while (x > 0)
    {
        num = x % 10;
        x /= 10;
        num1 = num1 * 10 + num;
    }
    if (a == 1)
        cout << "num1-> " << -num1;
    else
        cout << "num1-> " << num1;
}

int main()
{
    string s = "-42";
    rev(s);
    return 0;
}