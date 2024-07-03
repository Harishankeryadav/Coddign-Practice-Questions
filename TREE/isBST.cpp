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

int maximum(Node *root)
{
    if (root == NULL)
    {
        return INT8_MIN;
    }
    int mx = max(root->data, max(maximum(root->left), maximum(root->right)));
    return mx;
}

int minimum(Node *root)
{
    if (root == NULL)
    {
        return INT8_MAX;
    }
    int mini = min(root->data, min(minimum(root->left), minimum(root->right)));
    return mini;
}

// checking weather the given tree is balanced BST or not.
bool isBST(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftNode = maximum(root->left);
    int rightNode = minimum(root->right);
    bool output = ((root->data > leftNode) && (root->data < rightNode) && isBST(root->left) && isBST(root->right));
    return output;
}

//better than above code - same meethod different code
bool isBst(Node* root, int min = INT8_MIN, int max = INT8_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }

    bool leftNode = isBst(root->left, min, root->data-1);
    bool rightNode = isBst(root->right, root->data, max);
    return leftNode && rightNode;
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

    bool x = isBst(root);
    cout << "isBst " << x << " " << endl;
}