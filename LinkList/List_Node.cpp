#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};