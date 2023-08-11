#include <iostream>
#include "TimerClock.h"
using namespace std;
#include <queue>

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

// taking input level wise.
void Take_Input(Node *&root)
{
    {
        int data;
        cout << "Enter the data ";
        cin >> data;
        root = new Node(data);
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *newnode = q.front();
            q.pop();
            int newdata;
            cout << "enter the left of " << newnode->data << endl;
            cin >> newdata;
            if (newdata != -1)
            {
                newnode->left = new Node(newdata);
                q.push(newnode->left);
            }

            cout << "Enter the right of " << newnode->right << endl;
            cin >> newdata;
            if (newdata != -1)
            {
                newnode->right = new Node(newdata);
                q.push(newnode->right);
            }
        }
    }
}
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

// adding duplicate
Node *addDuplicate(Node *root, int x)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == x)
    {
        Node *temp = root->left;
        Node *newNode = new Node(x);
        root->left = newNode;
        newNode->left = temp;
    }
    else
    {
        if (root->data > x)
        {
            addDuplicate(root->left, x);
        }
        else
        {
            addDuplicate(root->right, x);
        }
    }
    return root;
}

// creating duplicate on all node of the tree.
// Node *duplicate(Node *root)
// {
// if (root == NULL)
// {
//     cout << "empty tree " << endl;
//     return NULL;
// }

// if (root->data != root->left->data)
// {
//     cout << "if loop data " << root->data << endl;
//     Node *temp = NULL;
//     if (root->left != NULL)
//         Node *temp = root->left;
//     Node *newNode = new Node(root->data);
//     root->left = newNode;
//     newNode->left = temp;
//     root = temp;
// }
// duplicate(root->left);

// duplicate(root->right);
// return root;
// }

Node *duplicate(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node *newNode = new Node(root->data);
    newNode->left = root->left;
    root->left = newNode;

    duplicate(newNode->left);
    duplicate(root->right);

    return root;
}

int main()
{ // ex: 50 25 75 20 30 70 80 15 23 28 40 65 72 76 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    cout << "Enter the root data ";
    Node *root;
    {
        timer T;
        Take_Input(root);
    }
    // // print(root);
    {
        timer T;
        Levelprinting(root);
    }

    // cout << "Enter the data to make its duplicate ";
    // int x;
    // cin >> x;
    // root = addDuplicate(root, x);
    // Levelprinting(root);

    cout << "Duplicate of all nodes " << endl;
    root = duplicate(root);
    Levelprinting(root);
