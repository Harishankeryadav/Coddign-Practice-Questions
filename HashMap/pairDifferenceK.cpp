#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
            if (map.find(abs(nums[i] - k)) != map.end())
            {
                // cout << map[nums[i]] << endl;
                count += map[abs(nums[i] - k)];
            }
            map[nums[i]]++;
        }
        // for (auto it : map)
        // {
        //     cout << "key: " << it.first << " value: " << it.second << endl;
        // }
        return count;
    }
};

int main()
{
    Solution mp;
    vector<int> v = {1, 2, 2, 1};
    cout << mp.countKDifference(v, 2);
}