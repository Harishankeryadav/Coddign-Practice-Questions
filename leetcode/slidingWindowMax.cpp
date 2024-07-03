#include <bits/stdc++.h>
#include <queue>
#include <algorithm>
using namespace std;

// vector<int> maxSlidingWindow(vector<int> &nums, int k)
// {
//     int i = 0;
//     vector<int> v;
//     while (i < nums.size() - k + 1)
//     {
//         int x = INT_MIN;
//         int a = 0;
//         while (int j = i && j < i + k)
//         {
//             x = max(x, nums[j]);
//             cout << x << "<-x    a-> " << a << "   j->" << j << endl;
//             j++;
//             a++;
//         }
//         cout << "after while ";
//         v.push_back(x);
//         cout << "x max-> " << x << " i ->" << i << endl;
//         cout << endl;
//         i++;
//     }

//     return v;
// }

// optimizing by using queue.

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> v;
    deque<int> q;
    int i = 0, j = 0, mx = INT32_MIN;

    for (; i < nums.size() - k + 1; i++)
    {
        if (!q.empty() && q.front() == i - k)
            q.pop_front();

        while (!q.empty() && nums[q.back()] < nums[i])
            q.pop_back();

        q.push_back(i);
        if (i >= k - 1)
            v.push_back(nums[q.front()]);
    }
    return v;
}

int main()
{
    vector<int> v = {1};
    vector<int> x = maxSlidingWindow(v, 1);
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << " ";
    return 0;
}