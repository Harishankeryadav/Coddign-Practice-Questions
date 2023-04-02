/*We have given a linked list we have to rearrange that linked list as all odd element prints first and then even element*/

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

//we can merge the Arrange_data function in takeinpute(upper) function also
Node *Arrange_data(Node *head)
{
    Node *temp = head;
    Node *odd = new Node(1);
    Node *even = new Node(-1);
    Node *h1 = odd;
    Node *h2 = even;

    while (temp != NULL)
    {

        if (temp->data % 2 == 0)
        {
            h2->next = temp;
            h2 = h2->next;
        }
        else
        {
            h1->next = temp;
            h1 = h1->next;
        }
        temp = temp->next;
    }
    h1->next = NULL;
    h2->next = NULL;
    h1->next = even->next;
    Node *Newhead = odd->next;
    delete odd;
    delete even;
    return Newhead;
}

int main()
{
    Node *head = TakeInput();
    print(head);

    Node *odd = Arrange_data(head);
    print(odd);
}