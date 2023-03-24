//dynamically creating Linked LIst.
#include <iostream>
#include "list_Node.cpp"
using namespace std;

Node *TakeInput()
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
        /*
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NewNode;
        }
        */
       //better complexity.
       else{
        tail->next = NewNode;
        tail = tail->next;
        //OR -> for line 34.
        //tail = newNode;
       }
        cin >> data;
    }

    return head;
}


void print(Node *head){
    while(head != NULL){
    cout <<head -> data << " ";
    head = head->next;
    }
}

int main(){

    Node *head = TakeInput();
    print(head);
    return 0;   
}