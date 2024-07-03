#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class HashMap
{
private:
    int B = 10;
    int size;
    vector<pair<int, string>> v[10];

public:
    int hash(int phone)
    {
        return phone % 20;
    }

    void insert(int phone, string s)
    {
        int index = hash(phone);
        v[index].push_back({phone, s});
    }

    string search(int phone)
    {
        int index = hash(phone);
        for (auto &entry : v[index])
        {
            if (entry.first == phone)
            {
                return entry.second;
            }
        }
        return "Value Not Found";
    }

    void remove(int phone)
    {
        int index = hash(phone);
        for (int i = 0; i <= v[index].size(); i++)
        {
            if (v[index][i].first == phone)
            {
                swap(v[index][i], v[index][v[index].size() - 1]);
                v[index].pop_back();
                cout << "Value has been removed " << endl;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < B; i++)
        {
            cout << "#" << i << ": ";
            for (auto &entry : v[i])
            {
                cout << "{" << entry.first << " " << entry.second << "}, ";
            }
            cout << endl;
        }
    }
};
