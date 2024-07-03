// Deleting alternate nodes of the given LL.
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

Node *Delete_Alternate(Node *head)
{
    Node *temp = head;
    Node *current = NULL;
    Node *prev = NULL;
    int count = 0;
    while (temp != NULL)
    {
        if (count % 2 == 0)
        {
            prev = temp;
            temp = temp->next;
        }
        else
        {
            current = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete current;
        }
        count++;
    }
    return head;
}

int main()
{
    Node *head = takeInpute();
    print(head);

    head = Delete_Alternate(head);
    print(head);
}