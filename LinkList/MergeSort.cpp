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

// finding mid.
Node *Middle_element(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {

        slow = slow->next;
        fast = fast->next->next;
    }
    Node *temp = slow;
    slow = slow->next;
    temp->next = NULL;
    return slow;
}
Node *merge(Node *head1, Node *head2)
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

Node *Merge_sort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *h2 = Middle_element(head);
    Node *h1 = head;

    h1 = Merge_sort(h1);
    h2 = Merge_sort(h2);

    Node *newhead = merge(h1, h2);
    return newhead;
}

int main()
{
    cout << "Enter the data : ";
    Node *head = Take_Input();
    print(head);

    cout << "sorted list \n";
    head = Merge_sort(head);
    print(head);
    return 0;
}