#include <bits/stdc++.h>
using namespace std;

bool checkPalindrom(string s)
{
    int j = s.size() - 1;
    for (int i = 0; i < j; i++)
    {
        if (s[i] != s[j])
            return false;
        j--;
    }
    return true;
}

// by using hashMap
string longestPalindrome1(string s)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]] = i;
    }
    int l = 0, r = 0;

    for (int i = 0; i < s.size();)
    {
        char a = s[i];
        if (mp.find(a) != mp.end())
        {
            int index = mp[a];
            if (i < index)
            {
                // string s1 = s.substr(i, index);
                if (checkPalindrom(s.substr(i, index)))
                {
                    if (r - l < index - i)
                    {
                        l = i;
                        r = index;
                    }
                }
            }
            // i++;
        }
        else
            i++;
    }
    return s.substr(l, r);
}

string longestPalindrome(string s)
{

    if (s.size() <= 1)
        return s;

    int x = 0;
    string a;
    for (int i = 0; i < s.size(); i++)
    {
        int j = i;
        // s1 += s[i];
        string s1 = "";
        // s1 += s[j];
        while (j < s.size())
        {
            s1 += s[j];
            cout << "s1-> " << s1 << ", s1[0] " << s1[0] << ", i " << i << ", j " << j << endl;
            if (s[j] == s1[0])
            {
                if (checkPalindrom(s1))
                {
                    cout << "s1-> " << s1 << " size " << s1.size() << " a " << a << " x " << x << endl;
                    if (s1.size() > x)
                    {
                        x = s1.size();
                        a = s1;
                    }
                };
            }
            j++;
        }
    }
    return a;
}

int main()
{

    string s = "aaac";
    cout << "output-> " << longestPalindrome1(s);
}