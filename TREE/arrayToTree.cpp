#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

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

void takeInput(Node *root, int data)
{
    if (root == NULL)
    {
        return;
    }

    // creating the node and putting the data at its position.
    if (root->left == NULL && root->data > data)
    {
        root->left = new Node(data);
    }
    else if (root->right == NULL && root->data < data)
    {
        root->right = new Node(data);
    }

    // if doesn't meets above condition then traversing in root.
    if (root->data < data)
    {
        takeInput(root->right, data);
    }
    else
    {
        takeInput(root->left, data);
    }
}

Node *arrayToTree(int arr[], int size)
{
    static int x = ceil(size / 2);
    cout << "ceil : " << x << " size " << size << " data " << arr[x] << endl;
    Node *root = new Node(arr[x]);
    static int i = 0;
    while (i < size)
    {
        if (i != x)
        {
            cout << "i " << i << " sending data " << arr[i] << " with root data " << root->data << endl;
            takeInput(root, arr[i]);
        }
        i++;
    }

    return root;
}

int main()
{
    //     7
    // 1 2 3 4 5 6 7
    int size = 7;
    // cout << "Enter the size of array  " << endl;
    // cin >> size;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // int arr[] = {15, 20,23,25,28,30,40,50,65,70,72,75,80,85};
    // cout << "Enter the array  " << endl;
    // for (int i = 0; i < size; i++)
    //     cin >> arr[i];

    Node *root = arrayToTree(arr, size);
    cout << "\nPrinting tree " << endl;
    // Levelprinting(root);
    print(root);
}