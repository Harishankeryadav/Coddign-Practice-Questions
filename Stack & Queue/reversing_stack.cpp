// Adding 1 in LL using stack.
#include <iostream>
#include <Stack>
using namespace std;

void reverse(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string  word = "";
        while (s[i] != ' ' && s[i] < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    string s = "Hey, how are you doing?";
    // cin >> s;
    reverse(s);
}