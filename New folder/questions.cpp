#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int strStr(string haystack, string needle)
{
    int p1 = 0;
    int index = 0;
    while (p1 <= haystack.size() - 1)
    {
        int p2 = 0;
        index = p1;
        cout << "p1 " << p1 << " p2 " << p2 << endl;
        cout << "hp " << haystack[p1] << " nd " << needle[p2] << endl;
        while ((haystack[p1] == needle[p2]) && p2 < needle.size())
        {
            p1++;
            p2++;
        }
        if (p2 == needle.size())
            return index;
        p1 = index;
        p1++;
    }
    return index;
}

int removeElement(vector<int> &nums, int val)
{
    int size = 0;
    int i = 0;
    int end = nums.size() - 1;
    // for (int i = 0; i != end; i++)
    // {
    //     cout << nums[i] << " ";
    // }
    cout << endl;
    while (i < nums.size())
    {
        if (nums[i] == val )
        {
            // nums.erase(nums.begin() + i);//delete element at given pos

            if (nums[i] != nums[end] && end > i)
            {
                swap(nums[i], nums[end]);
                end--;
                size++;
            }
            else if (end <= i)
            return size;
            else  
                end--;
        }
        else
            i++;
        cout <<" i -> " << i <<endl;
        for (int j = 0; j < nums.size(); j++)
        {
            cout << nums[j] << " ";
        }
        cout << endl;
    }
    // cout <<"after ->";
    // for (int i = 0; i < nums.size() ; i++)
    // {
    //     cout << nums[i] << " ";
    // }
    cout << endl;
    return size;
}

int main()
{
    // string x = "mississippi";
    // string y = "issip";
    // cout << strStr(x, y);

    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    cout << "val-> " << removeElement(nums, val);
}
