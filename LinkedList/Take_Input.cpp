#include <iostream>
#include "List_Node.cpp"
using namespace std;

class Input : public Node
{
public:
    Node *Take_Input()
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
    }
};