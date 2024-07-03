#include <bits/stdc++.h>
using namespace std;

vector<string> letterCombinations(string digits)
{
    unordered_map<int, string> mp{{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

    vector<string> v;
    int d1 = digits[0] - '0';
    string s1 = mp[d1];

    for (int i = 0; i < s1.size(); i++)
    {
        string a = "";
        a += s1[i];
        v.push_back(a);
    }
    int i = 1;
   for (int i = 1; i < digits.size(); i++) {
        int d = digits[i] - '0';
        string s = mp[d];
        vector< string> v1;
        // for (char c : s)
         for(int i = 0; i < s.size(); i++){
            char c = s[i];
            // for ( string str : v)
            for(int j = 0; j < v.size(); j++) {
                string str = "";
                str += v[j];
                v1.push_back(str + c);
            }
        }
        v = v1;
    }
    return v;
}

int main()
{
    string x = "234";
    vector<string> v = letterCombinations(x);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}