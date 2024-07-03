#include <bits/stdc++.h>
using namespace std;

    int maxSubArray(vector<int>& nums) {
        int maxEl = INT_MIN, sum = 0;
        if (nums.empty())
            return -1;
        for (int i = 0; i < nums.size(); i++) {
            if (sum < 0) {
                sum = 0;
            }
            sum += nums[i];
            // cout << "max " << max << " sum " << sum << endl;
            maxEl = max(sum, maxEl);
        }
        return maxEl;
    }
