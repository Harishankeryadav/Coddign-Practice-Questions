#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class subsequence
{
private:
    int count = 0;

public:
    unordered_map<int, bool> map;

    void insertion(vector<int> &v)
    {
        for (auto &it : v)
        {
            map[it] = 1;
        }
    }

    //  void insertion(vector<int> &v)
    // {
    //     for (int value : v)
    //     {
    //         map[value] ;
    //     }
    // }

    void largest_subsequence(vector<int> v)
    {

        int start = 0;
        int end = 0;
        int size = 0;
        for (auto it : v)
        {
            int count1 = 0;
            int count2 = 1;
            int start1 = it;
            int end1 = 0;

            cout << "it " << it << " start " << start << " end " << end << " size " << size << endl;

            while (map[it + count1] == 1)
            {
                map[it + count1] = 0;
                end1 = it + count1;
                count1++;
            }

            while (map[it - count2] == 1)
            {
                map[it - count2] = 0;
                start1 = it - count2;
                count2++;
            }

            if (count1 + count2 - 1 > size)
            {
                start = start1;
                end = end1;
                size = count1 + count2 - 1;
            }
            cout << " after if loop start " << start << " end " << end << " size " << size << endl;
        }
        cout << "start: " << start << ",  end: " << end << ", size: " << size << endl;
    }

    void print()
    {
        int count = 1;
        for (auto pair : map)
        {
            cout << count << " Key: " << pair.first << ", Value: " << pair.second << endl;
            count++;
        }
    }

    void value(int x)
    {
        auto xb = map.find(x);
        cout << "krnr " << xb->first << endl;
    }
};

// example
// Sample Input 1 :
// 13
// 2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6

// Sample Output 1 :
// 8 12

// Sample Input 2 :
// 7
// 3, 7, 2, 1, 9, 8, 41

// Sample Output 2 :
// 7 9
// Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.

// Sample Input 3 :
// 7
// 15, 24, 23, 12, 19, 11, 16

// Sample Output 3 :
// 15 16

int main()
{
    subsequence m;
    vector<int> v = {3, 7, 2, 1, 9, 8, 41};
    m.insertion(v);
    // m.print();
    // m.value(12);
    m.largest_subsequence(v);
}