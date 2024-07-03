#include <iostream>
#include "List_Node.cpp"
using namespace std;

Node *AddNode(int data, int i, Node *head)
{
    Node *temp = head;
    int count = 0;
    Node *NewNode = new Node(data);
    if (temp == NULL)
    {

        return NewNode;
    }
    else if (i == 0)
    {
        NewNode->next = head;
        head = NewNode;
        return head;
    }

    else if (count == i - 1)
    {
        NewNode = new Node(data);
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
    else
    {
        temp->next = AddNode(data, i - 1, head->next);
    }
    return head;
}

Node *DeleteNode(Node *head, int pos)
{
    Node *temp = head;
    int count = 0;
    if (pos == 0)
    {
        head = temp->next;
        delete temp;
        return head;
    }
    else if (count == pos - 1)
    {
        Node *NewNode = temp->next;
        temp->next = NewNode->next;

        return head;
    }
    else
    {
        head = DeleteNode(temp->next, pos--);
    }
    return head;
}

Node *TakeInput()
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = TakeInput();
    print(head);

    cout << endl;
    head = AddNode(121, 1, head);
    print(head);

    cout << endl;
    head = DeleteNode(head, 0);
    print(head);
    return 0;
}