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
        Node *temp = new Node(data);
        if (head == NULL && tail == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        cin >> data;
    }
    return head;
}
void Print(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "Empty list ";
    }
    while (temp != NULL)
    {
        cout << temp->data << " and add " << temp << endl;
        temp = temp->next;
    }
    cout << endl;
}

Node *deleteDuplicates(Node *head)
{
    Node *temp = head;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            // Node *newt = temp->next;

            if (temp->next->next != NULL)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp->next = NULL;
                return head;
            }
        }
        if (temp->data != temp->next->data)
            temp = temp->next;
    }
    return head;
}

Node *removeNthFromEnd(Node *head, int n)
{
    if (head->next == NULL)
    {
        return NULL;
    }
    if(n == 1 && head->next->next == NULL){
        head->next = NULL;
        return head;
    }
    Node *slow = head;
    Node *fast = head;

    for (int i = 0; i < n + 1; i++)
    {
        if (fast->next != NULL)
            fast = fast->next;
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // if (slow->next != NULL && slow->next->next != NULL)
        slow->next = slow->next->next;

    return head;
}

int main()
{
    cout << "Enter the first list ";
    Node *head = TakeInput();

    cout << "printing the data \n";
    Print(head);

    // cout <<"\naddress of next ";
    // cout << head->next;
    // cout <<"\naddress of next->next ";
    // cout << head->next->next;
    // Node* tmep = head->next->next;
    // cout << "\ntemp = " << tmep;

    // Node *temp = deleteDuplicates(head);
    // cout << "after removing duplicate \n";
    // Print(temp);

    head = removeNthFromEnd(head, 2);
    cout << "after removing \n";
    Print(head);
}