#include <iostream>
#include <queue>
#include "TimerClock.h"
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

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


Node *searching(Node *root, int data)
{
    Node *temp = root;
    if (temp == NULL)
    {
        cout << "Node not available ";
        return NULL;
    }
    else
    {
        if (data == temp->data)
        {
            return temp;
        }
        else if (data < temp->data)
        {
            return searching(temp->left, data);
        }
        else if (data > temp->data)
        {
            return searching(temp->right, data);
        }
    }
    return temp;
}


// deleting the given node.
void Delete_Node(Node *&root, int num)
{
    Node *temp = searching(root, num);
    Node* prev = NULL;

    if (root == NULL)
    {
        cout << "Tree is empty " << endl;
        return;
    }

    if (temp->left == NULL && temp->right == NULL)
    {
        delete temp;
        return;
    }
    Node *temp1 = temp->left;
    while (temp1->right != NULL)
    {
        prev = temp1;
        temp1 = temp1->right;
    }

    if (temp1->left != NULL)
    {
        temp->data = temp1->data;
        temp1->data = temp1->left->data;
        temp1->left = NULL;
        delete prev->right;
    }
    else if (temp1->right == NULL && temp1->left == NULL)

    {
        cout << "else if right if NULL " << endl;
        temp->data = temp1->data;
        delete temp1;
    }
}
int main()
{ // ex: 50 25 75 20 30 70 80 15 23 28 40 65 72 76 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Enter the root data ";
    // Node *root = insertTree(root);

    Node *root;
    takeinput(root);
    Levelprinting(root);

    // deleting node.
    int num = 0;
    cout << "Enter the number to delete from the tree ";
    cin >> num;
    Delete_Node(root, num);
    Levelprinting(root);

}