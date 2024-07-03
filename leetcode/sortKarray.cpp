/*given k number of array, sort them */
#include <bits/stdc++.h>
using namespace std;

vector<int> arraySum(vector<vector<int>> v)
{ //                   val,  arraynum, index.
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    //     priority_queue<
    //     pair<int, pair<int, int>>,            // Type of elements stored in the priority queue
    //     vector<pair<int, pair<int, int>>>,    // Underlying container type (vector of pairs)
    //     greater<pair<int, pair<int, int>>>    // Comparison function to order elements (min heap)
    // > pq;

    vector<int> res;
    int elem = 0;
    // to put first element of all index in pq
    for (int i = 0; i < v.size(); i++)
    {
        elem += v[i].size();
        if (!v[i].empty())
            pq.emplace(make_pair(v[i][0], make_pair(i, 0)));
    }

    // to push all elem in pq one by one and pop and push into vector
    while (elem > 0 && !pq.empty())
    {
        auto x = pq.top();
        res.push_back(x.first);      // to push the element
        int a = x.second.first;      // to get the array number of element
        int b = x.second.second + 1; // to get the index number of element
        pq.pop();
        if (b < v[a].size())
        {
            pq.emplace(make_pair(v[a][b], make_pair(a, b)));
        }
        elem--;
    }

    return res;
}

int main()
{
    vector<vector<int>> v = {{1, 5, 8, 23, 67}, {2, 6, 45, 78, 90}, {1, 1, 5, 8}};
    vector<int> res = arraySum(v);

    cout << "\nRes ->  ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}