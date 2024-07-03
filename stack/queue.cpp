#include <iostream>
// #include "queue_maintemplate.cpp"
#include "queueUsingarray.cpp"
using namespace std;

int main()
{
    // queue<int> q;

    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // q.enqueue(40);
    // q.enqueue(50);
    // q.enqueue(60);

    // cout << q.front() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.getsize() << endl;
    // cout << q.isEmpty() << endl;
    
    queue_using_array q(4);

    q.push(10);
    q.push(20);
    // cout << q.pop()<<" ";
    // cout << q.pop()<<" ";
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(10);
    q.push(20);

    cout << q.front() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    // cout << q.pop() << endl;
    // cout << q.pop() << endl;
    // cout << q.pop() << endl;
    // cout << q.pop() << endl;
    cout << q.getsize() << endl;
    cout << q.isEmpty() << endl;
}