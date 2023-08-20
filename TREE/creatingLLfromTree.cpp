#include <iostream>
#include <queue>
#include <stdlib.h>
#include <math.h>
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

// creating sorted linked from the tree.
// used Node for tree and LNode for LL.
// for left part of tree.
void LLfromTree(Node *root, LNode *&head, LNode *&tail)
{
    if (root == NULL)
    {
        return;
    }

    LLfromTree(root->left, head, tail);
    static int i = 0;
    cout << root->data << " data  " << i << "   iteration " << endl;
    i++;
    LNode *newnode = new LNode(root->data);
    if (!head)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
    }
    tail = newnode;

    LLfromTree(root->right, head, tail);
}

// printing LL
void printLL(LNode *head)
{
    LNode *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void printLLS(LNode *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    printLLS(head->next);
}

int main()
{
    // 50 25 75 20 30 70 80 15 23 28 40 65 72 76 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Enter the tree ";
    Node *root;
    takeinput(root);
    Levelprinting(root);
    LNode *head = NULL;
    LNode *next = NULL;

    LLfromTree(root, head, next);
    cout << "Linked list from tree is : " << endl;
    printLL(head);
    cout << "\nSecond method " << endl;
    printLLS(head);
}