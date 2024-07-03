#include <iostream>
#include "Stack_MaintemplateLL.cpp"
using namespace std;

int main()
{
    StackUsingLL<char> s;
    char data;
    cout << "Enter the data : ";
    cin >> data;
    while (data != '~')
    {
        if (data == '(' || data == '[' || data == '{')
        {
            s.push(data);
        }
        else
        {
            if (data == ')' && s.top() == '(')
            {
                s.pop();
            }
            else if (data == ']' && s.top() == '[')
            {
                cout << " ~in else if ";
                s.pop();
            }
            else if (data == '}' && s.top() == '{')
            {
                s.pop();
            }
        }
        cin >> data;
    }
    if (s.isEmpty())
        cout << "Balanced Paranthesis ";
    else
        cout << "Unbalanced Paranthsis ";
}
