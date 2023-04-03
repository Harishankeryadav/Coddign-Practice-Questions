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

Node *reverse(Node *&head, int n)
{
    int count = 0;
    Node *forptr = NULL;
    Node *prevptr = NULL;
    Node *temp = head;
    while (count < n && temp != NULL)
    {
        forptr = temp->next;
        temp->next = prevptr;
        prevptr = temp;
        temp = forptr;
        count++;
    }
    if (forptr != NULL)
    {
        head->next = reverse(forptr, n);
    }
    return prevptr;
}
int main()
{
    cout << " Enter the list : ";
    Node *head = Take_Input();
    print(head);

    head = reverse(head, 2);
    print(head);
}