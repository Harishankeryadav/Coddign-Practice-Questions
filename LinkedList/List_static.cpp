#include <iostream>
#include "list_Node.cpp"
using namespace std;

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

    Node n1(1);
    Node *head = &n1;
    Node n2(3);
    Node n3(5);
    Node n4(7);
    Node n5(9);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);
}