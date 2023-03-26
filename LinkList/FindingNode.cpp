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

// If the given number present in multiple time then printing the first occurence of that data(index).
/*int FindNode(Node *head, int num)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            return count;
        }
        temp= temp->next;
        count++;
    }
    return -1;
}*/

// If the is present multiple times then print the last occurence of the data(index).

int FindNode(Node *head, int num)
{
    Node *temp = head;
    int count = 0;
    int index = 0;
    int num_check = -1;
    while (temp != NULL)
    {

        if (temp->data == num)
        {
            num_check = temp->data;
            index = count;
        }
        count++;
        temp = temp->next;
    }
    if (temp == NULL && num_check == -1)
    {
        return -1;
    }
    return index;
}

int main()
{
    cout << "Enter the list : ";
    Node *head = TakeInput();
    print(head);

    int data;
    cout << "Enter the data which you want to find ";
    cin >> data;
    int num = FindNode(head, data);
    cout << "Index of the given data is : " << num;
    return 0;
}