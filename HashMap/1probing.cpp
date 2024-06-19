#include <iostream>
#include <string>
using namespace std;

class hashMapProbing
{
private:
    bool isFresh[7];
    pair<int, string> p[7];

public:
    hashMapProbing()
    {
        for (int i = 0; i < 7; i++)
        {
            isFresh[i] = true;
        }
    }

    int hash(int num)
    {
        return num % 7;
    }

    void insert(int num, string name)
    {
        for (int i = 0; i < 7; i++)
        {
            int index = hash(num + i);
            if (isFresh[index] == true)
            {
                p[index] = make_pair(num, name);
                isFresh[index] = false;
                break;
            }
        }
    }

    string search(int num)
    {
        for (int i = 0; i < 7; i++)
        {
            int index = hash(num + i);
            if (p[index].first == num)
            {
                return p[index].second;
            }
        }
        return "Not found";
    }

    void remove(int num)
    {
        for (int i = 0; i < 7; i++)
        {
            int index = hash(num + i);
            if (isFresh[index] == true)
            {
                return;
            }
            else if (p[index].first == num)
            {
                p[index].second = "NIL";
                return;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < 7; i++)
        {
            // if (isFresh[i] == true)
            //     return;
            // else
            // {
                cout << "#" << i << ": {" << p[i].first << " , " << p[i].second << "}" << endl;
            // }
        }
    }
};

int main()
{
    hashMapProbing hp;

    hp.insert(12345, "a");
    hp.insert(12346, "b");
    hp.insert(12347, "c");
    hp.insert(12348, "d");
    hp.insert(12349, "e");
    hp.insert(12340, "f");

    hp.print();
    cout << "search : " << hp.search(12349) << endl;

    hp.remove(12349);
    cout << "search : " << hp.search(12349) << endl;
    hp.print();
}