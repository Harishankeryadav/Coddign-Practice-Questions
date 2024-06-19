// Ques-> inserting the data without any repetation and printing it.
/*
#include <iostream>
#include <unordered_map>
using namespace std;

class ques
{
public:
    unordered_map<int, int> h;

    void insert()
    {
        cout << "enter the data and value" << endl;
        int data;
        cin >> data;
        int value;
        cin >> value;
        while (data != -1)
        {
            h[data] = value;
            cin >> data;
            cin >> value;
        }
    }

    void print()
    {
        for (auto &pair : h)
        {
            cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
        }
    }
};

int main()
{
    ques h;
    h.insert();
    h.print();
}
*/

// Ques-> given an array  find the number of ways to pick two indices such a[i] == a[j] && (i != j).
// ex-> {1, 2, 1, 3, 3, 1, 1}

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class indice
{
public:
    unordered_map<int, int> mp;
    int totalPairsNum = 0;

    void totalPairs(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (mp.count(arr[i]) < 1)
            {
                mp[arr[i]] = 1;
            }
            else if (mp.count(arr[i]) >= 1)
            {
                int num = mp[arr[i]];
                mp[arr[i]] = ++num;
            }
        }

        for (auto &pair : mp)
        {
            int num = pair.second;
            if (num > 1)
            {
                totalPairsNum += (num * (num - 1)) / 2;
            }
        }
    }

    void print()
    {
        for (auto &pair : mp)
        {
            cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
        }
        cout << "Total pairs are " << totalPairsNum << endl;
    }
};

unordered_map<int, int> mp{};
void totalPairs(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (mp.count(arr[i]) < 1)
        {
            mp[arr[i]] = 1;
        }
        else if (mp.count(arr[i]) >= 1)
        {
            // cout << "12313\n";
            int num = mp[arr[i]];
            cout << num << "\n";
            mp[arr[i]] = ++num;
        }
    }
}

void pairs(vector<int> &v)
{
    int pair = 0;
    for (auto it : v)
    {
        pair += mp[it];
        mp[it]++;
    }
    cout << "pairs are : " << pair << endl;
    for (auto &pair : mp)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
    cout << "vector is : ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

void print()
{
    for (auto &pair : mp)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
}

unordered_map<int, int> freq(const vector<int> &nums)
{
    unordered_map<int, int> HM{};
    for (auto it : nums)
    {
        HM[it]++;
    }
    return HM;
}

// void _showHM(const unordered_map<int,int> &HM ){
//     cout << "key\tvalue\n";
//     for(auto it : HM)
//         cout << it.first << "\t" << it.second << "\n";
// }

int main()
{

    indice h;
    vector<int> nums = {1, 2, 1, 2, 1, 1, 2, 3};

    // vector<int> arr = {1, 2, 1, 3, 3, 1, 1};
    // h.totalPairs(arr, 7);

    // mp  = freq(nums);
    pairs(nums);
    // h.print();
    // print();

    // _showHM(HM);
}