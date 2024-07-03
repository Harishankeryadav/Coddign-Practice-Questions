#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num)
{
    // unordered_map<int, char> mp = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
    // string s = to_string(num);
    // string ans = "";

    // int n = 0, i = 0;
    // while (num != 0)
    // {

    //     if (num >= 1000)
    //     {
    //         n = s[0] - '0';
    //         i++;
    //         for (int j = 0; j < n; j++)
    //         {
    //             ans += mp[1000];
    //         }
    //         num %= 1000;
    //         s = to_string(num);
    //     }
    //     else if (num >= 500)
    //     {
    //         // n = s[i] - '0';
    //         i++;
    //         // for (int j = 0; j < n; j++)
    //         // {
    //         ans += mp[500];
    //         num %= 500;
    //         cout << "num-> " << num << " i -> " << i << endl;
    //         s = to_string(num);
    //         // }
    //     }
    //     else if (num >= 100)
    //     {
    //         n = s[0] - '0';
    //         i++;
    //         for (int j = 0; j < n; j++)
    //         {
    //             ans += mp[100];
    //         }
    //         num %= 100;
    //         s = to_string(num);
    //     }
    //     else if (num >= 50)
    //     {
    //         // n = s[i] - '0';
    //         i++;
    //         // for (int j = 0; j < n; j++)
    //         // {
    //         ans += mp[50];
    //         num -= 50;
    //         s = to_string(num);
    //         // }
    //     }
    //     else if (num >= 10)
    //     {
    //         n = s[0] - '0';
    //         cout << "n ->" << n << " 10   i->" << i << "   s[i] " << s[i] << endl;
    //         i++;
    //         cout << "num->" << num << endl;
    //         for (int j = 0; j < n; j++)
    //         {
    //             ans += mp[10];
    //         }
    //         num %= 10; 
    //     }
    //     else if (num >= 5)
    //     {
    //         n = s[0] - '0';
    //         i++;
    //         ans += mp[5];
    //         num -= 5; 
    //     }
    //     else
    //     {
    //         for (int j = 0; j < num; j++)
    //         {
    //             ans += mp[1];
    //             num--;
    //         } 
    //     }
    // }

    // return ans;

    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const std::string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    std::string result = "";

    for (int i = 0; i < 13 && num > 0; i++) {
        while (num >= values[i]) {
            num -= values[i];
            result += symbols[i];
        }
    }

    return result;
}

int main()
{
    cout << intToRoman(1994);
}