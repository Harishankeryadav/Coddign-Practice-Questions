#include <iostream>
#include <vector>
using namespace std;

int n = 4;
int visited[4][4] = {0};
int grid[4][4] = {{0, 1, 1, 1}, {0, 0, 1, 0}, {1, 0, 1, 1}, {0, 0, 0, 0}};

int dir_x[] = {1, -1, 0, 0};
int dir_y[] = {0, 0, 1, -1};

bool isPossible(int row, int col)
{
    return row >= 0 && row < n && col >= 0 && col < n && visited[row][col] == 0 && grid[row][col] == 0;
}

vector<pair<int, int>> path;

void fun(int row, int col)
{
    // base case
    if (row == n - 1 && col == n - 1)
    {
        cout << "solution :- " << endl;
        for (auto it : path)
        {
            cout << "{ " << it.first << ", " << it.second << "},";
        }
        cout << endl;
        return;
    }

    // some basic calculation
    for (int i = 0; i < 4; i++)
    {
        int new_row = row + dir_x[i];
        int new_col = col + dir_y[i];

        if (isPossible(new_row, new_col))
        {
            visited[new_row][new_col] = 1;
            path.push_back({new_row, new_col});

            fun(new_row, new_col);
            visited[new_row][new_col] = 0;
            path.pop_back();
        }
    }
}

int main()
{

    fun(0, 0);
    path.push_back({0, 0});
    return 0;
}