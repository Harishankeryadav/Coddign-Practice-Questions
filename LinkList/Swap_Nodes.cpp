// Swapping two given nodes.

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

Node *swap(Node *head, int a, int b)
{
    int m = 0, n = 0;
    Node *c1 = head;
    Node *p1 = NULL;
    Node *c2 = head;
    Node *p2 = NULL;

    while (m < a)
    {
        p1 = c1;
        c1 = c1->next;
        m++;
    }
    while (n < b)
    {
        p2 = c2;
        c2 = c2->next;
        n++;
    }

    p1->next = c2;
    p2->next = c1;
    c1->next = c2->next;
    c2->next = p2;

    return head;
}

int main(){
    Node* head = TakeInput();
    print(head);

    head = swap(head, 3, 4);
    print(head);
}