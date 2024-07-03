// // we have 2 palyer and N cards, this cards are divided b/w them randomly(may be equal or not) if we compaire the top
// // card and whovers is bigger get both card and place them at end, first the opponents care then theirs.find the winner

#include <iostream>
#include <vector>
// #include <unordered_map>
#include <map>
using namespace std;

// unordered_map<pair<vector<int>,vector<int>>,int> HM;
map<pair<vector<int>, vector<int>>, int> HM;

void game(vector<int> p1, vector<int> p2)
{
    while (p1.size() > 0 && p2.size() > 0)
    {
        if (p1.begin() > p2.begin())
        {
            p1.push_back(p2[0]);
            p1.push_back(p1[0]);
        }
        else
        {
            p2.push_back(p1[0]);
            p2.push_back(p2[0]);
        }

        if (HM[{p1, p2}] != 0)
        {
            cout << "No result -1";
            return;
        }
        else
        {
            HM[{p1, p2}] = 1;
        }

        p1.erase(p1.begin());
        p2.erase(p2.begin());
    }
    if (p1.size() != 0)
    {
        cout << "p1 is winner " << endl;
    }
    else
    {
        cout << "p2 is winner " << endl;
    }
}

//via using linked-list

int main()
{
    vector<int> p1 = {2};
    vector<int> p2 = {1, 3};
    // card_Game a;
    game(p1, p2);
}