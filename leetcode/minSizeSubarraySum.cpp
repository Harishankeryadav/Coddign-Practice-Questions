#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int j = 0;
    int count = 0;
    while (j < nums.size())
    {
        int sum = 0, i = j;
        while (sum <= target)
        {
            sum = sum + nums[i];
            if (sum == target)
            {
                count++;
                break;
            }
            i++;
        }
        j++;
    }
    return count++;
}

int main()
{
    vector<int> x = {12,28,83,4,25,26,25,2,25,25,25,12};
    int y = 213;
    cout << minSubArrayLen(y, x);
    return 0;
}