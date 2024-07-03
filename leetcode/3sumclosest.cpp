#include <bits/stdc++.h>
using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int closestSum = INT_MAX; // Initialize closestSum with a large value
    int minDiff = INT_MAX; // Initialize minDiff with a large value

    for (int i = 0; i < nums.size() - 2; i++) {
        int j = i + 1, k = nums.size() - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            int diff = abs(target - sum); // Calculate the absolute difference

            if (diff < minDiff) { // Update closestSum and minDiff if the current sum is closer to the target
                closestSum = sum;
                minDiff = diff;
            }

            if (sum > target)
                k--;
            else if (sum < target)
                j++;
            else // If sum == target, return target immediately
                return target;
        }
    }
    return closestSum;
}

int main()
{
    vector<int> x = {0,1,2};
    int y = 3;
    cout << " val -> " << threeSumClosest(x, y);
}