#include <iostream>
#include "List_Node.cpp"
using namespace std;

Node *InsertingList()
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
/* first approach  by tavesing the whole list.
void Midoflist(Node *head)
{

    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    temp = head;
    cout << "mid element is : " ;
    int num = 0;
    while (temp != NULL)
    {
        if (num == (count - 1) / 2)
        {
            cout << temp->data;
        }
        temp = temp->next;
        num++;
    }
}
*/
// by using secong approach via using 2 pointer method.

Node *Midoflist(Node *head)
{
    Node *ptr1 = head;
    Node *ptr2 = head->next;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

//if their is only two nodes.
    if (head->next->next == NULL)
    {
        return head->next;
    }

    while (ptr2 != NULL)
    {
        ptr2 = ptr2->next;
        if (ptr2 != NULL)
        {
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return ptr1;
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

    Node *head = InsertingList();
    print(head);

    Node *mid = Midoflist(head);
    cout << mid->data<<" ";
}
