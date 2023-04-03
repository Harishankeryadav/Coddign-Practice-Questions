#include <iostream>
#include "stack_main.cpp"
using namespace std;

int main()
{
    stackUsingArray s(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    cout << s.top() << " ";
    cout << s.pop() << " ";
    cout << s.top() << " ";
    cout << s.size() << " ";
    cout << s.isEmpty()<<" ";
}