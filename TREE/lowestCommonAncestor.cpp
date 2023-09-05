#include <iostream>
#include <queue>
#include "TimerClock.h"
#include <stdlib.h>
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

bool findData(Node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    if (x < root->data)
        return findData(root->left, x);
    if (x > root->data)
        return findData(root->right, x);
    return false;
}

// lowest common ancestor  means first common ancestor.
// x < y
void LCA(Node *root, int x, int y)
{
    if (root == NULL)
    {
        return;
    }

    if (x <= root->data && y >= root->data || x <= root->data && y <= root->data || x >= root->data && y >= root->data)
    {
        cout << "in if loop " << root->data << endl;
        int l = findData(root, x);
        int r = findData(root, y);

        cout << "l r " << l << " " << r << endl;

        if (l != 0 && r != 0)
        {
            cout << "LCA is " << root->data << endl;
            return;
        }
        else if (l != 0)
        {
            cout << "LCA is " << x << endl;
            return;
        }
        else if (r != 0)
        {
            cout << "LCA is " << y << endl;
            return;
        }
        else
        {
            cout << "Nodes are not available " << endl;
            return;
        }
    }
    LCA(root->left, x, y);
    LCA(root->right, x, y);
}
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp != NULL)

        {
            cout << temp->data << " : ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
                cout << " l " << temp->left->data << " ";
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
                cout << " r " << temp->right->data << " ";
            }
            cout << endl;
        }
    }
}

int main()
{ // BST ex: 50 25 75 20 30 70 80 15 23 28 40 65 72 76 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

    // Sample Input 1:
    // 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    // 2 10
    // Sample Output 1:
    // 10

    // Sample Input 2:
    // 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    // 2 6
    // Sample Output 2:
    // 5

    // Sample Input 3:
    // 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    // 12 78
    // Sample Output 3:
    // -1
    cout << "Enter the root data ";
    Node *root;
    {
        timer T;
        takeinput(root);
    }
    // // print(root);
    {
        timer T;
        // Levelprinting(root);
        print(root);
    }
    cout << "Enter the value of both nodes " << endl;
    int x, y;
    cin >> x >> y;
    LCA(root, x, y);
}
