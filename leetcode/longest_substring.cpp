#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// void longest_substring(string s)
// {
//     vector<char> v;
//     int count = 0;
//     int j = 0;

//     for (int i = 0; i < s.length() - 1; i++)
//     {
//         if (s[i] != s[j] && s.find(s[i]) != s[i])
//         {
//             v[j] = s[i];
//             j++;
//         }
//         else if (s[i] == s[j])
//         {
//             j = 0;
//         }
//         else
//         {
//             if (count < j)
//             {
//                 count = j;
//             }
//         }
//     }
//    for(auto it: v){
//     cout << it <<" ";
//    }
// }

int longest_substring(string s)
{
    int n = s.length();
    int maxLength = 0;
    unordered_map<char, int> map;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (map.count(s[i]) == 0 )
        {
            map[s[i]] = i;
            maxLength = max(maxLength, i - j + 1);
        }
        else
        {
            j = map[s[i]] + 1;
            map[s[i]] = i;
        }
    }

    return maxLength;
}

int main()
{
    string s = "pwwkew";
    // string s = "abcabcbb";
    // string s = "bbbbb";
    cout<< longest_substring(s);
    return 0;
}