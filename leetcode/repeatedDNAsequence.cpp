#include <bits/stdc++.h>
using namespace std;

bool stringMatching(string s1, string s2)
{
    // int i = 0;
    // int j = s2.size() - 1;
    cout << "s[i+10] " << s1 << " s[j-10] " << s2 << endl;
    for (int i = 0; i < 10; i++)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

vector<string> findRepeatedDnaSequences(string s)
{
    unordered_map<string, int> mp;
    vector<string> x;

    for (int i = 0; i + 10 < s.size(); i++)
    {
        for (int j = i + 1; j + 10 < s.size(); j++)
        {
            cout << "s[i] " << s[i] << " s[j] " << s[j] << " i " << i << " j " << j << endl;
            if (s[i] == s[j])
            {
                if (stringMatching(s.substr(i, 10), s.substr(j, 10)))
                {
                    cout << "after matching \n";
                    // cout << "s[i+10] " << s.substr(i, 10) << " s[j-10] " << s.substr(j - 10, 10) << endl;
                    if (mp.find(s.substr(i, 10)) == mp.end())
                    {
                        x.push_back(s.substr(i, 10));
                        mp[s.substr(i, 10)] = 1;
                    }
                }
            }
        }
    }
    return x;
}

vector<string> findRepeatedDnaSequences1(string s)
{
    unordered_set<string> seen; // Use unordered_set for faster lookup
    vector<string> result;

    for (int i = 0; i + 10 <= s.size(); i++)
    {
        string current = s.substr(i, 10);
        if (seen.find(current) != seen.end()) // If current sequence is already seen, continue
            continue;

        // If the current sequence occurs again later in the string, add it to the result
        if (s.find(current, i + 1) != string::npos)
        {
            result.push_back(current);
            seen.insert(current); // Add the current sequence to the set to avoid duplicates
        }
    }

    return result;
}

vector<string> findRepeatedDnaSequences2(string s)
{
    unordered_set<string> seen; // Use unordered_set for faster lookup
    vector<string> result;

    for (int i = 0; i + 10 <= s.size(); i++)
    {
        string current = s.substr(i, 10);
        if (seen.find(current) != seen.end()) // If current sequence is already seen, continue
            continue;

        // If the current sequence occurs again later in the string, add it to the result
        if (s.find(current, i + 1) != string::npos)
        {
            result.push_back(current);
            seen.insert(current); // Add the current sequence to the set to avoid duplicates
        }
    }

    return result;
}

int main()
{
    string s = "AAAAAAAAAA";
    // string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> x = findRepeatedDnaSequences(s);

    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < x[i].size(); j++)
            cout << "coutput " << x[i][j];
        cout << " ";
    }
}