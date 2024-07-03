// We will be finding the loopsin linked list if any.

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
    cout << endl;
}

bool loopInList(Node *head)
{
    Node *temp = head;
    Node *slow = head;
    Node *fast = head->next;

    while (temp != NULL && slow == fast)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        temp = temp->next;
    }
    if (slow == fast)
    {
        cout << "Loop is present ";
        return true;
    }
    cout  << "Loop is not present ";
    return false;
}

int main()
{
    Node *head = takeInpute();
    print(head);
    cout << loopInList(head);
}