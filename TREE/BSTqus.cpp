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

// printing the data in the given range of tree.

void printInRange(Node *root, int x, int y)
{
    if (root == NULL)
    {
        return;
    }

    printInRange(root->left, x, y);

    if (root->data >= x && root->data <= y)
    {
        cout << root->data << "  ";
    }

    printInRange(root->right, x, y);
}

// void printInRange(Node *root, int x, int y)
// {
//     queue<Node *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();
//         if (temp->data >= x && temp->data <= y)
//         {
//             cout << temp->data << "  ";

//             if (temp->left != NULL)
//                 q.push(temp->left);
//             if (temp->right != NULL)
//                 q.push(temp->right);
//         }
//         else
//         {
//             if (temp->left != NULL)
//                 q.push(temp->left);
//             if (temp->right != NULL)
//                 q.push(temp->right);
//         }
//     }
// }

Node *replaceNodeWithLevel(Node *root, int x)
{
    if(root == NULL){
         return root;
    }
    // cout <<" root " << root <<" " <<root->data << endl;
    root->data = x;
    replaceNodeWithLevel(root->left, x + 1);
    // cout <<" root " << root <<" " <<root->data << endl;
    replaceNodeWithLevel(root->right, x + 1);
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

    // 40 20 60 10 30 50 70 -1 -1 -1 -1 -1 -1 -1 -1
    // {
    //     timer T;
    //     cout << "Enter the range to print the data ";
    //     int x, y;
    //     cin >> x >> y;
    //     printInRange(root, x, y);
    // }
    {
        timer T;
        Node *temp;
        int a = 0;
        cout << "After replacing the nodes with their respective levels : " << endl;
        temp = replaceNodeWithLevel(root, a);
        cout << temp->data <<" temp\n";
        Levelprinting(temp);
    }
}