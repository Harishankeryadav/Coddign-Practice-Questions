#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int i = 0;
    while (i < nums.size())
    {
        if (mp.find(nums[i]) != mp.end())
        {
            int diff = i - mp[nums[i]];
            cout << "diff-> " << diff << "   i-> " << i << "     mp[nums[i]]-> " << mp[nums[i]] << endl;
            if (diff <= k)
                return true;
        }
        cout << " nums[i]-> " << nums[i] << endl;
        cout << endl;
        mp[nums[i]] = i;
        i++;
    }
    return false;
}

int main()
{

    vector<int> x = {1,0,1,1};
    cout << "ans " << containsNearbyDuplicate(x, 1);
}