// merging to sorted array via Linked List.

#include <iostream>
#include "List_Node.cpp"
using namespace std;

Node *Take_Input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
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

Node *Merge_Sort(Node *head1, Node *head2)
{
    Node *h1 = head1;
    Node *h2 = head2;
    Node *NewHead = new Node(0);
    Node *NewTail = NewHead;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            NewTail->next = h1;
            h1 = h1->next;
        }
        else
        {
            NewTail->next = h2;
            h2 = h2->next;
        }
        NewTail = NewTail->next;
    }
    while (h1 != NULL)
    {
        NewTail->next = h1;
        h1 = h1->next;
        NewTail = NewTail->next;
    }
    while (h2 != NULL)
    {
        NewTail->next = h2;
        h2 = h2->next;
        NewTail = NewTail->next;
    }
    return NewHead->next;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    cout << "Enter the data of first list ";
    Node *head1 = Take_Input();
    print(head1);
    cout << "Enter the data of second list ";
    Node *head2 = Take_Input();
    print(head2);
    Node *NewHead = Merge_Sort(head1, head2);
    cout << "After merging the list \n";
    print(NewHead);
}