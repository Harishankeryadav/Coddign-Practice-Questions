#include <iostream>
#include <vector>
using namespace std;

int n = 4;
vector<string> s = {"....", "....", "....", "...."};

int visited_col[4], visited_d1[20], visited_d2[20];

bool isPossible(int row, int col)
{
    return visited_col[col] == 0 && visited_d1[row + col] == 0 && visited_d2[n + row - col] == 0;
}

void fun(int row)
{
    // base case
    if (row == n)
    {
        cout << "solution : " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << s[i] << endl;
        }
        cout << endl;
        return;
    }

    // some calculative task
    for (int col = 0; col < n; col++)
    {
        if (isPossible(row, col))
        {
            s[row][col] = 'Q';
            visited_col[col] = 1;
            visited_d1[row + col] = 1;
            visited_d2[n + row - col] = 1;

            cout << "possible row " << row +1<< " col:- " << col+1 << endl;
            for (int i = 0; i < n; i++)
            {
                cout << s[i] << endl;
            }
            cout << endl;

            // undo the done task
            fun(row + 1);

            s[row][col] = '.';
            visited_col[col] = 0;
            visited_d1[row + col] = 0;
            visited_d2[n + row - col] = 0;
            cout << "backtrack row " << row + 1 << " col:- " << col +1 << endl;
            for (int i = 0; i < n; i++)
            {
                cout << s[i] << endl;
            }
            cout << endl;
        }
    }
}

// int n = 8;

// vector<string> s = {"........", "........", "........", "........", "........", "........", "........", "........"};

// int visited[8] = {0}, visited_d1[20] = {0}, visited_d2[20] = {0};

// bool isPossible(int row, int col)
// {
//     return visited[col] == 0 && visited_d1[row + col] == 0 && visited_d2[n + row - col - 1] == 0;
// }

// void nQueen(int row)
// {
//     // base case
//     if (row == n)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             cout << s[i] << endl;
//         }
//         cout << endl;
//         return;
//     }

//     // small calculation

//     for (int i = 0; i < n; i++)
//     {
//         if (isPossible(row, i))
//         {
//             s[row][i] = 'Q';
//             visited[i] = 1;
//             visited_d1[row + i] = 1;
//             visited_d2[n + row - i - 1] = 1;

//             nQueen(row + 1);
//             s[row][i] = '.';
//             visited[i] = 0;
//             visited_d1[row + i] = 0;
//             visited_d2[n + row - i - 1] = 0;
//         }
//     }
// }

int main()
{

    // cout << "enter the size of box ";
    // cin >> n;
    fun(0);

    // nQueen(0);
    return 0;
}
