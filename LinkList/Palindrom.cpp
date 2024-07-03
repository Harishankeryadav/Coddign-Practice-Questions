// Finding weather the given linked list is palindrome of not
//  Their are two approacch to do that
// 1. By creating the copy of given linked list and reversing it and then comparing it with original list, but its space complexity will increase.
// 2. By finding mid of the given list and the  reversing the second half and then comparing it with first half. Most appropriate sollution.

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
        Node *NewHead = new Node(data);
        if (head == NULL)
        {
            head = NewHead;
            tail = NewHead;
        }
        else
        {
            tail->next = NewHead;
            tail = NewHead;
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

Node *Reverse_List(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

int palindrom(Node *head)
{
    Node *temp = head;
    Node *slow = head;
    Node *fast = head->next;

    // getting middle.
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *middle = slow;
    middle->next = Reverse_List(slow->next);

    // compairing.
    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return -1;
        }
        else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    // reversing the half list again so we will get original list.
    middle->next = Reverse_List(slow->next);
    return 0;
}

int main()
{
    Node *head = Take_Input();
    print(head);

    cout << endl;
    cout << palindrom(head);
}