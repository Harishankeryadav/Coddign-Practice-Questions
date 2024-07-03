#include <iostream>
#include "stack_maintemplate.cpp"                   //for array
#include "Stack_maintemplateLL.cpp"                 // for LL
using namespace std;

int main()
{
    // stackUsingArray<int> s;                  //for array
    StackUsingLL<char> s;                      // For LL
    s.push(100);
    s.push(95);
    s.push(96);
    s.push(97);
    s.push(98);
    s.push(99);

    cout << s.pop() << " ";
    cout << s.top() << " ";
    cout << s.pop() << " ";
    cout << s.pop() << " ";
    cout << s.top() << " ";
    cout << s.getsize() << " ";
    cout << s.isEmpty() << " ";
}