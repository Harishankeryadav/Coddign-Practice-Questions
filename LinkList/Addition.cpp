// sum of tw linked list.
#include <iostream>
#include "List_Node.cpp"
using namespace std;

Node *TakeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *temp = new Node(data);
        if (head == NULL && tail == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        cin >> data;
    }
    return head;
}

void Print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *Reverse(Node *&head)
{
    Node *next = NULL;
    Node *prev = NULL;
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void InsertAtEnd(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *addition(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    head1 = Reverse(head1);
    head2 = Reverse(head2);

    int carry = 0;
    while (head1 != NULL || head2 != NULL || carry != 0)
    {
        int val1 = 0;
        if (head1 != NULL)
            val1 = head1->data;

        int val2 = 0;
        if (head2 != NULL)
            val2 = head2->data;

        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        InsertAtEnd(head, tail, digit);

        if (head1 != NULL)
            head1 = head1->next;
        if (head2 != NULL)
            head2 = head2->next;
    }
    head = Reverse(head);
    return head;
}

int main()
{
    cout << "Enter the first list ";
    Node *head1 = TakeInput();
    // Print(head1);
    cout << "Enter the second list ";
    Node *head2 = TakeInput();
    // Print(head2);

    Node *head = addition(head1, head2);
    cout << "Sum of both lists are : ";
    Print(head);
}