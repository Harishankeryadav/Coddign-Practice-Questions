#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> v = {-1, -1};
    if (nums.empty())
        return v;
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        cout << "data-> " << nums[mid] << " l " << l << " r " << r << endl;

        // if (nums[mid] == target)
        //     break;
        if (nums[mid] < target)
        {
            
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
        cout << "data-> " << nums[mid] << " l " << l << " r " << r << endl;
    }

    if (nums[l] == target)
    {
        v[0] = l;
    }
    else
    {
        return v;
    }

    r = nums.size() - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2 + 1;
        cout << "data-> " << nums[mid] << " l " << l << " r " << r << endl;

        // if (nums[mid] == target)
        //     break;
         if (nums[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
        cout << "2data-> " << nums[mid] << " l " << l << " r " << r << endl;
    } 
        v[1] = r;

    return v;
}

vector<int> searchRange1(vector<int> &nums, int target)
{
    vector<int> result = {-1, -1};

    if (nums.empty())
        return result;

    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    if (nums[left] == target)
    {
        result[0] = left;
    }
    else
    {
        return result;
    }

    right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2 + 1;

        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid;
        }
    }
    result[1] = right;

    return result;
}

int main()
{
    vector<int> v = {1,2,3};
    v = searchRange(v, 2);

    cout << "OUTPUT =  f-> " << v[0] << "  s-> " << v[1] << endl;
}