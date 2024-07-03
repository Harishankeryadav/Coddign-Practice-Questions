// creating a double LInked list.
// If we return head then we will get entered data but if we retrun tail then we will get reversed data.

#include <iostream>
#include "List_class.cpp"
using namespace std;

Node *TakeInput()
{
    int data;
    cin >> data;

    Node *prev = NULL;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newhead = new Node(data);

        if (head == NULL && tail == NULL)
        {
            head = newhead;
            tail = newhead;
        }
        else
        {
            tail->next = newhead;
            tail->prev = prev;
            prev = tail;
            tail = tail->next;
        }
        cin >> data;
    }
    tail->prev = prev;
    tail->next = NULL;
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

int main()
{
    Node *head = TakeInput();
    print(head);
}