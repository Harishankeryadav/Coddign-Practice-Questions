//we will  be finding the height and diameter of the tree.
#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

// recursive approach for taking input.
Node<int> *TakeInput(Node<int> *root)
{
    cout << "Enter the root node " << endl;
    int data;
    cin >> data;
    root = new Node<int>(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the left node " << data << endl;
    root->left = TakeInput(root->left);

    cout << "Enter the right node " << data << endl;
    root->right = TakeInput(root->right);
    return root;
}

// iterative approach for taking input.
void IterativeInput(Node<int> *&root)
{
    queue<Node<int> *> q;
    int data;
    cout << "Enter the root node " << endl;
    cin >> data;
    root = new Node<int>(data);
    q.push(root);

    while (!q.empty())
    {
        Node<int> *temp = q.front();
        q.pop();

        cout << "Enter the left Node for " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->left = new Node<int>(data);
            q.push(temp->left);
        }

        cout << "Enter the right node for " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->right = new Node<int>(data);
            q.push(temp->right);
        }
    }
}

void print(Node<int> *root)
{
    cout << "Formed tree is : " << endl;
    queue<Node<int> *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node<int> *temp = q.front();
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

// finding the  height of the given tree.

int height(Node<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return (max(left, right) + 1);
}

// finding the width of tree.

int diameter(Node<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int l = diameter(root->left);
    int r = diameter(root->right);
    int h = height(root->left) + height(root->right) + 1;
    int ans = max(l, max(r, h));
    return ans;
}

int main()
{
    Node<int> *root = NULL;
    // root = TakeInput(root);
    IterativeInput(root);
    // example : 1 2 3 4 5 6 7 8 9 10 11 -1 -1 12 -1 13 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    print(root);

    int ans = height(root);
    cout << "\nThe height of the guven tree is : " << ans << endl;
    int width = diameter(root);
    cout << "The diameter of the given tree is : " << width << endl;
}