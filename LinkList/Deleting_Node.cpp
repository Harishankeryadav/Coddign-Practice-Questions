// We  have to delete M nodes after every N nodes.
//  1 2 3 4 5 6 7 8 9        m = 3, n = 2.
// LL -> 1 2 3 6 7 8.

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

Node *Deleting_Node(Node *head, int m, int n)
{
    Node *temp = head;
    int a = 0, b = 0;
    Node *newNode = NULL;
    Node *prev = NULL;

    while (temp != NULL)
    {
        // if(m == 0 || n == 0){
        //     return head;
        // }
        if (a < m)
        {
            prev = temp;
            temp = temp->next;
            a++;
        }
        else if (a == m && b < n)
        {
            newNode = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete newNode;
            b++;
        }
        else
        {
            a = 0;
            b = 0;
        }
    }
    return head;
}

int main()
{
    int m, n;
    cout << "Enter the list : ";
    Node *head = TakeInput();
    print(head);
    cout << "m is number of node you want to skip and n is number of nodes you want to delete\n";
    cout << "Enter the value m and n : ";
    cin >> m >> n;
    Node *newhead = Deleting_Node(head, m, n);
    print(newhead);
}