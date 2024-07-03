// following all the rule of mathmatics adding two number of the linked list.
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// inserting the data into the linked list.
Node *insertion()
{
    cout << "Enter the data " << endl;
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

// printing the data from ll
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// adding two numbers of LL.
Node *addingTwoNumber(Node *l1, Node *l2)
{
    Node *dummy;
    Node *temp = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;
        cout << sum <<"<- ->" ;
        carry = sum / 10;
        cout << sum <<" " <<endl;
        Node *newnode = new Node(sum % 10);
        temp->next = newnode;
        temp = temp->next;
    }
    return dummy->next;
}

int main()
{
    // 2 4 3 -1
    Node *head1 = insertion();
    // 5 6 4 -1
    Node *head2 = insertion();

    print(head1);
    print(head2);

    Node *newHead;
    cout << "Sum is " << endl;
    newHead = addingTwoNumber(head1, head2);
    print(newHead);
}