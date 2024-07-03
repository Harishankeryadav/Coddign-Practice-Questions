#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto i : mp){
            if(i.second>=2){
                return  true;
            }
        }
        return false;
    }


int main()
{
    vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << " asd " << containsDuplicate(nums);
    return 0;
}