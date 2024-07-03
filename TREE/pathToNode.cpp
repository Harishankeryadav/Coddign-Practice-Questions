// we are given a tree and we have to find the node and print the path to the node.
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
// without recursion
void pathToNode(Node *root, int x)
{
    Node *temp = root;
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    while (temp->data != x)
    {
        if (temp->data > x && temp->right != NULL)
        {
            temp = temp->left;
        }
        else if (temp->data < x && temp->right != NULL)
        {
            temp = temp->right;
        }
        cout << temp->data << " ";
    }
}

// with recursion
void nodePath(Node *root, int x)
{
    
    static queue<int> v;
    if (root == NULL)
    {
        cout <<"Node not found " << endl;
        return;
    }
    v.push(root->data);

    if(root->data == x){
        while(!v.empty()){
            cout << v.front() <<" ";
            v.pop();
        }
        return;
    }

    if (root->data > x)
        nodePath(root->left, x);
    else
        nodePath(root->right, x);
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
    // {
    //     timer T;
    //     cout << "path to node  " << endl;
    //     pathToNode(root, 40);
    // }
    {
        timer T;
        cout << "enter the node to find the path " << endl;
        int x;
        cin >> x;
        nodePath(root, x);
    }
}