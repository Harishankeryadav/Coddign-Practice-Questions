#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int missingNumber(vector<int> &nums)
{
    unordered_map<int, int> mp; 
    for (int i = 0; i < nums.size(); i++)
    {
        // if (nums[i] > x)
        //     x = nums[i];
        mp[nums[i]] = 1;
        // cout << nums[i] << "  ";
    }
    // cout << "\nx-> " << x << endl;
    for (int i = 0; i <= nums.size(); i++)
    {
        cout << "i-> " << i   << endl;
        if (mp.find(i) == mp.end())
            return i;
    }

    return -1;
}

int main()
{
    vector<int> x = {0,1};
    int xi = missingNumber(x);
    cout << "missing number -> " << xi;
    return 0;
}