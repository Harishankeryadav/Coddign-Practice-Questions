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

// Searching of element
Node *search(Node *root, int x)
{
    // cout << root->data << " root data searching  " << endl;

    if (root == NULL)
    {
        return NULL;
    }
    // cout << "searcching for " << x << " root data " << root->data << endl;

    if (root->data == x)
    {

        return root;
    }
    else
    {
        if (root->data < x)
        {
            return search(root->right, x);
        }
        else
        {
            return search(root->left, x);
        }
    }
}
// finding all the possible pair whose sum is equal to the given number.
void pairSum(Node *root,Node* root1, int sum)
{
    //  Node *temp = root;
    if (root == NULL)
    {
        return;
    }
    static int x1 = 0;
    static int x2 = 0;
    static int num = 0;
    // cout << "now at node " << root->data << endl;

    if (root->data <= sum)
    {
        x1 = root->data;
        x2 = sum - x1;
        // cout << " x1 -> " << x1 << " x2->  " << x2 << endl;

        Node *temp1 = search(root1, x2);
        if (temp1 != NULL)
        {
            int a = temp1->data;
            temp1->data = INT8_MIN;
            if (sum == x1 + x2)
            {
                cout << x1 << ", " << x2 << endl;
            }
        }
    }
    pairSum(root->left,root1, sum);
    pairSum(root->right,root1, sum);
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

    cout << "Enter the sum to find pair sum " << endl;
    int x;
    cin >> x;
    // ex:- 5 2 10 1 3 6 9 -1 -1 -1 -1 -1 -1 -1 -1  
    pairSum(root,root, x);
}