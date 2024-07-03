#include <iostream>
#include <queue>
#include <vector>
#include <stdlib.h>
#include "TimerClock.h"
using namespace std;

// tree class
class Node
{
public:
    Node *left;
    Node *right;
    int data = 0;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Linked list class
class LNode
{
public:
    LNode *next;
    LNode *tail;
    int data;

    LNode(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// level wise printing.
void takeinput(Node *&root)
{
    int data;
    cin >> data;
    queue<Node *> q;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        int Nodedata;
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left of " << temp->data << endl;
        cin >> Nodedata;
        if (Nodedata != -1)
        {
            temp->left = new Node(Nodedata);
            q.push(temp->left);
        }

        cout << "Enter the right of " << temp->data << endl;
        cin >> Nodedata;
        if (Nodedata != -1)
        {
            temp->right = new Node(Nodedata);
            q.push(temp->right);
        }
    }
}

// Level-wise printing.
void Levelprinting(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    if (root == NULL)
    {
        cout << "Tree is empty " << endl;
        return;
    }

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void LLFromtree(Node *root, LNode *&head, LNode *tail)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";

    LLFromtree(root->left, head, tail);
    LLFromtree(root->right, head, tail);
    LNode *newnode = new LNode(root->data);
    cout << root->data <<" ";
    cout << "\nhead " << head << " tail " << tail << endl;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        cout << "\nhead " << head << " tail " << tail << endl;
        cout << head->data <<" ll \n";
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
        cout << "\nhead " << head << " tail " << tail << endl;
        cout << tail ->data <<" ll \n";
    }
}

void printLL(LNode *head)
{
    LNode *temp;
    if (head == NULL)
    {
        return;
    }

    cout << head->data << " ";
    printLL(head->next);
}

int main()
{ // ex: 50 25 75 20 30 70 80 15 23 28 40 65 72 76 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    // Sample Input:
    // 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

    // Sample Output:
    // 5
    // 6 10
    // 2 3
    // 9
    cout << "Enter the root data ";
    Node *root;
    {
        timer T;
        takeinput(root);
    }
    // // print(root);
    {
        timer T;
        Levelprinting(root);
    }
    LNode *head = NULL;
    LNode *tail = NULL;
    LLFromtree(root, head, tail);
    cout << "printing Linked List " << endl;
    printLL(head);
}