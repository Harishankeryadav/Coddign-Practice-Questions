// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array
//  nums = [0,1,2,4,5,6,7] might become:
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums)
{
    int mid = 0;
    int l = 0;
    int r = nums.size();
    // int ans = INT16_MAX;

    while(r - l > -1){
        mid = (l + r) / 2;
        // ans = nums[mid];

        if(nums[mid] < nums[r] && nums[mid] << nums[l]){
            return nums[l+1];
        }

        else if(nums[r] > nums[mid]){
            r = mid;
        }
        else{
            l = mid + 1;
        }

    }

return -1;
}

int main()
{

    // Example 1:
    // vector<int> nums = {3, 4, 5, 1, 2};
    // Output: 1, Explanation: The original array was [1,2,3,4,5] rotated 3 times.

    vector<int> nums = {4,5,6,7,0,1,2};
    // Output: 0, Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

    // vector<int> nums = {11,13,15,17};
    // Output: 11, Explanation: The original array was [11,13,15,17] and it was rotated 4 times.

    cout << findMin(nums);
    return 0;
}