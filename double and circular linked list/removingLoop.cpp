// We will be finding the loopsin linked list if any.
// if any then finding the first element of loop and then removing loop.

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
    tail->next = head->next;
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    Node *ptr = NULL;
    while (temp != ptr && temp != NULL)
    {
        ptr = head;
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void NonLoopPrint(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


Node *loopInList(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    if (head == NULL)
    {
        return NULL;
    }
    while (fast != NULL && slow != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        if (slow == fast)
        {
            cout << "Loop is present \n";
            return slow;
        }
        
    }
    return NULL;
}

void firstElement_And_removingLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = loopInList(head);
    Node *slow = head;
    Node *prev = NULL;
    while (slow != temp)
    {
        slow = slow->next;
        prev = temp;
        temp = temp->next;
    }
    cout << "First element of the loop is : " << slow->data << endl;
    prev->next = NULL;
}

int main()
{
    cout << "Enter the list : ";
    Node *head = takeInpute();
    // print(head);

    loopInList(head);
    firstElement_And_removingLoop(head);
    print(head);
    NonLoopPrint(head);
}