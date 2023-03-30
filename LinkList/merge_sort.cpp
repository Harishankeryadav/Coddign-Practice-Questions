#include <iostream>
#include "linkedList.cpp"
using namespace std;

Node *Take_Input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
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
    cout << endl;
}

// iterative sorting.
Node *Sorting(Node *head)
{                           // 5 3 1 4 9 6 7 -1
    Node *temp = head;
    Node *temp1 = head->next;
    Node *temp2 = new Node(0); // temporary node used for swaping.
    int count = 0;
    while (temp != NULL)
    {
        while (temp1 != NULL)
        {
            if (temp->data < temp1->data)
            {
                temp2->data = temp1->data;
                temp1->data = temp->data;
                temp->data = temp2->data;
            }

            temp1 = temp1->next;
            print(head);
        }
        count++;
        temp = temp->next;
        for (int i = 0; i <= count; i++)
        {
            temp1 = head->next;
        }
    }
    delete temp2;
    return head;
}

Node *merge_sort(Node *head1, Node *head2)
{
    Node *h1 = head1;
    Node *h2 = head2;
    Node *Newhead = new Node(0);
    Node *Newtail = Newhead;
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            Newtail->next = h1;
            h1 = h1->next;
        }
        else
        {
            Newtail->next = h2;
            h2 = h2->next;
        }
        Newtail = Newtail->next;
    }

    while (h1 != NULL)
    {
        Newtail->next = h1;
        h1 = h1->next;
        Newtail = Newtail->next;
    }
    while (h2 != NULL)
    {
        Newtail->next = h2;
        h2 = h2->next;
        Newtail = Newtail->next;
    }
    return Newhead->next;
}

int main()
{
    cout << "Enter the data : ";
    Node *head1 = Take_Input();
    cout << "head1 : ";
    // print(head1);

    head1 = Sorting(head1);
    print(head1);

    // Node *head2 = Take_Input();
    // cout << "head2 : ";
    // print(head2);
    // Node *head = merge_sort(head1, head2);
    // cout << "head : ";
    // print(head);
}