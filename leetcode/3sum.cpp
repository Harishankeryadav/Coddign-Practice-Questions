#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])  
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    v.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])  
                        j++;
                    while (j < k && nums[k] == nums[k - 1])  
                        k--;
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return v;
    }

int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> x = threeSum(v);

    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < x[i].size(); j++)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}