#include <iostream>
#include "List_Node.cpp"
using namespace std;

Node *TakeInpute()
{
    int data;
    cout << "Enter the data \n";
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

Node *InsrertNode(Node *head, int data, int i)
{
    int cout = 1;
    Node *NewNode = new Node(data);
    Node *temp = head;

    if (i == 0)
    {
        NewNode->next = temp;
        head = NewNode;
        return head;
    }

    while (cout <= i - 1 && temp != NULL)
    {
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
    return head;
}

Node *delete_Node(Node *head, int i)
{
    int count = 1;
    Node *temp = head->next;
    if (i == 0)
    {
        head = temp->next;
        return head;
    }

    while (head != NULL && count <= i - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp != NULL)
    {
        Node *newtemp = temp->next;
        temp->next = newtemp->next;
        delete newtemp;
    }
    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = TakeInpute();
    //print(head);

    head = InsrertNode(head, 987, 3);
    print(head);

    head = delete_Node(head, 2);
    print(head);

    return 0;
}