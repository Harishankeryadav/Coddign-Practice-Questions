#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node* prev;
    int data;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};