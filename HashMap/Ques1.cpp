
#include <iostream>
#include <vector>
#include <unordered_Map>
using namespace std;

// Ques-> given an array  find the number of ways to pick two indices such a[i]+a[j]=k && a[i] == a[j] && (i != j).
// ex-> {1, 2, 1, 3, 3, 1, 1}
class pairSum
{
public:
    unordered_map<int, int> map;

    void insertion(vector<int> v)
    {
        for (auto it : v)
        {
            map[it];
        }
    }

    void sum(int k, vector<int> v)
    {
        int count1 = 0;
        for (int it : v)
        {
            count1 += map[abs(k - it)];
            map[it]++;
        }
        cout << "total pair sum are : " << count1 << endl;
    }

    void print()
    {
        for (auto it : map)
        {
            cout << "key " << it.first << "  value " << it.second << endl;
        }
    }
};

// for the given array or vector find the sum of sub array whose sum is equal to k.

void subArraySum(const vector<int>& arr, int targetSum) {
    unordered_map<int, int> prefixSumMap;
    int prefixSum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        prefixSum += arr[i];

        if (prefixSum == targetSum) {
            cout << "Subarray with sum " << targetSum << " found between indices 0 and " << i << ": ";
            for (int j = 0; j <= i; ++j) {
               cout << arr[j] << " ";
            }
            cout << endl;
        }

        if (prefixSumMap.find(prefixSum - targetSum) != prefixSumMap.end()) {
            cout << "Subarray with sum " << targetSum << " found between indices " << prefixSumMap[prefixSum - targetSum] + 1 << " and " << i << ": ";
            for (int j = prefixSumMap[prefixSum - targetSum] + 1; j <= i; ++j) {
               cout << arr[j] << " ";
            }
           cout << endl;
        }

        prefixSumMap[prefixSum] = i;
    }
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 5};
    int targetSum = 16;

    subArraySum(arr, targetSum);
    return 0;
}
// int main()
// {
//     pairSum p;
//     vector<int> nums = {1, 2, 1, 2, 1, 1, 2, 3};
//     // p.insertion(nums);
//     // p.sum(4, nums);
//     // p.print();

//     subArraySum s;
//     s.arraySum(nums, 1);
//     s.print();
// }
