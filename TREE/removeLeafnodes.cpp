#include <iostream>
#include <queue>
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

Node *deleteLeafNode(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    root->left = deleteLeafNode(root->left);
    root->right = deleteLeafNode(root->right);
    return root;
}

int main()
{ // ex: 50 25 75 20 30 70 80 15 23 28 40 65 72 76 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    //     Sample Input :
    // 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
    //     Sample Output :
    // 8
    // 3 10
    // 6 14

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

    root = deleteLeafNode(root);
    Levelprinting(root);
}