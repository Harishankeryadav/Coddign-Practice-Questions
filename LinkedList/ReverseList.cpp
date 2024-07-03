// reversing the given linkedlist
#include <iostream>
#include "List_Node.cpp"
using namespace std;

Node *takeInpute()
{
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    cin >> data;

    while (data != -1)
    {
        Node *NewNode = new Node(data);
        if (head == NULL)
        {
            head = NewNode;
            tail = NewNode;
        }
        else
        {
            tail->next = NewNode;
            tail = NewNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// iterative approach
Node *Revlist(Node *head)
{
    Node *previous = NULL;
    Node *forward = NULL;

    while (head != NULL)
    {
        forward = head->next;
        head->next = previous;
        previous = head;
        head  = forward;
    }
    return previous;
}


int main()
{
    Node *head = takeInpute();
    print(head);

    cout << endl;
     head = Revlist(head);
     print(head);

}