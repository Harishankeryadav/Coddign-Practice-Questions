// sorting the given linked list
#include <iostream>
#include "List_Node.cpp"
using namespace std;

Node *takeInput()
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
    if (temp == NULL)
    {
        cout << "Empty list \n";
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *sorting(Node *head)
{
    Node *dummy = new Node(1000);
    dummy->next = head;
    Node *curr = head;
    Node *prev = dummy;
    Node *temp = NULL;
    Node *prev1 = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        prev1 = curr;
        while (temp != NULL)
        {

            if (temp->data < curr->data)
            {
                prev->next = temp;
                prev1->next = temp->next;

                // prev= prev->next;
                temp->next = curr;
                curr = temp;
                temp = prev1->next;
                
            }
            else
            {
                prev1 = temp;
                temp = temp->next;
            }
            cout << "after while ";
            print(head);
        }
        prev = curr;
        curr = curr->next;
    }

    head = dummy->next;
    delete dummy;
    return head;
}

int main()
{
    cout << "Enter the list ";
    Node *head = takeInput();
    print(head);
    head = sorting(head);
    cout << "sorted ";
    print(head);
}