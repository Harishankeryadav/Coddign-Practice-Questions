// eleminating duplicate from sorted linked list.
#include <iostream>
#include "List_Node.cpp"
using namespace std;

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newhead = new Node(data);
        if (head == NULL)
        {
            head = newhead;
            tail = newhead;
        }
        else
        {
            tail->next = newhead;
            tail = newhead;
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

Node *Eleminate_duplicate(Node *head)
{
    Node *temp1 = head;
    Node *temp2 = head->next;

    if (temp1 == NULL || temp1->next == NULL)
    {
        return head;
    }

    while (temp2 != NULL)
    {
        if (temp1->data == temp2->data)
        {
            Node* temp = temp2;
            temp2 = temp2->next;
            delete temp;
            
        }
        else
        {
            temp1->next = temp2;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    temp1->next = temp2;

    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);

    head = Eleminate_duplicate(head);
    print(head);
    return 0;
}