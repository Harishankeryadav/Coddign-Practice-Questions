/*We have to append last N nodes to the front of the list.
For example list is 1 2 3 4 5 6
N = 3 then after appending list will be
4 5 6 1 2 3
*/

#include <iostream>
#include "List_Node.cpp"
using namespace std;

Node *TakeInput()
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

Node *Append_Last_N_To_First(Node *head, int n)
{
    Node *tail = head;
    Node *NewHead = NULL;
    Node *Newtail = NULL;
    int count = 0;

    cout << " addresses are : ";
    while (tail != NULL)
    {
        count++;
        //cout << tail << " ";
        tail = tail->next;
    }
    cout << endl;
    tail = head;
    int n1 = 0;
    while (tail->next != NULL)
    {
        if (n1 == count - n - 1)
        {
            Newtail = tail;
        }
        if (n1 == count - n )
        {
            NewHead = tail;
        }
        tail = tail->next;
        n1++;
    }
    //to check the addresing of nodes.
    //cout << "Newhead, Newtail, Tail and head are : " << NewHead << " " << Newtail << " " << tail << " " << head << endl;

    Newtail->next = NULL;
    tail->next = head;
    return NewHead;
}

int main()
{
    cout << "Enter the input of the  list : ";
    Node *head = TakeInput();
    print(head);

    int n;
    cout << "Enter the value of N : ";
    cin >> n;
    head = Append_Last_N_To_First(head, n);
    print(head);
}