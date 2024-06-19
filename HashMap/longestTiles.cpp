// // we are given some tiles[parallelopiped] and we have to glue two equal side of tile such that the spear cut from
// //  those tiles are biggest

// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;

// void biggestSphear(vector<int> &v, int size)
// {
//     map<pair<int, int>, pair<int, int>> hm; // pair<value, value>, pair<value, index>

//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < 2; j++)
//         {
//         }
//     }
// }

// int main()
// {
//     /*
//     input: 6
//     {{5, 5, 5},{3, 2, 4},{1, 4, 1 },{2, 1, 3},{3, 2, 4},{3, 3, 4 }}
//     output: 1 1

//     input:7
//     {{10, 7, 8 },{5, 10, 3},{4, 2, 6 },{5, 5, 5},{10, 2, 8},{4, 2, 1},{7, 7, 7}}
//     output: 2
//             1 5
//     */

//     vector<vector<int>> v = {{5, 5, 5},{3, 2, 4},{1, 4, 1 },{2, 1, 3},{3, 2, 4},{3, 3, 4 }};

// }

#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
#include <utility>
using namespace std;

// Function to create p of elements and their indices in a 2D vector
vector<pair<pair<int, int>, pair<int,int>>> createp(const vector<vector<int>> &v)
{
    vector<pair<pair<int, int>, pair<int,int>>> p;
       map<int, int> hm;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         p.push_back(make_pair(v[i][j], make_pair(i, j)));
    //     }
    // }
    for (int i = 0; i < v.size(); i++)
    {
        // p.push_back(make_pair(make_pair(v[i][0], v[i][1]), v[i][2]));
        // p.push_back(make_pair(make_pair(v[i][0], v[i][2]), v[i][1]));
        // p.push_back(make_pair(make_pair(v[i][1], v[i][2]), v[i][0]));

        // if(!hm[make_pair(v[i][0], v[i][1])])
        hm[{v[i][0], v[i][1]}] = {v[i][2], i};
    }

    return p;
}

int main()
{
    // Create a 2D vector
    vector<vector<int>> v = {{5, 5, 5}, {3, 2, 4}, {1, 4, 1}, {2, 1, 3}, {3, 2, 4}, {3, 3, 4}};

    // Create p of elements and their indices
    vector<pair<pair<int, int>, pair<int,int>>>p = createp(v);

    // Print the p
    for (const auto &pair : p)
    {
        // cout << "Element: " << pair.first << " Index: (" << pair.second.first << ", " << pair.second.second << ")\n";
    }

    return 0;
}
