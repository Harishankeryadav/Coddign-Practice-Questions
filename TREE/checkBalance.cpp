#include <iostream>
#include <queue>
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

int checkAllNodes(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int left = checkAllNodes(root->left);
    int right = checkAllNodes(root->right);

    return (abs(left - right) + 1);
}

bool checkBalancedBst(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int x = checkAllNodes(root);
    if (x > 1)
        return false;

    return true;
}

int main()
{ // ex : 50 25 75 20 30 70 80 15 23 28 40 65 72 76 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // Sample Input 1 :
    //  5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
    //  Sample Output 1 :
    //  false

    // Sample Input 2 :
    // 1 2 3 -1 -1 -1 -1

    // Sample Output 2 :
    // true
    cout << "enter the root data ";
    Node *root;
    takeinput(root);
    Levelprinting(root);
    cout << endl;
    cout << "the tree is : " << checkBalancedBst(root) << endl;
    return 0;
}