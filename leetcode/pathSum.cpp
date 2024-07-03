#include <bits/stdc++.h>
using namespace std;

// template <typename T>
class Node
{
public:
    int data;
    Node *left;
    Node *right;

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

bool hasPathSum(Node *root, int targetSum)
{
    if (root == NULL)
        return false;
    if (root->data == targetSum && root->left == NULL)
    {
        cout << "data  " << root->data << endl;
        return true;
    }

    int sum = 0;

    while (root->left != NULL)
    {
        root = root->left;
        sum += root->data;
        cout << "sum  " << sum << "   root->data  " << root->data << endl;
    if (sum == targetSum && root->left == NULL)
    {
        return true;
    }
    }
    return false;
}

int main()
{
    // 5 4 8 11 -1 13 4 7 2 -1 -1 -1 1 -1 -1 -1 -1 -1 -1
    // 1 -1 -1
    cout << "enter data ";
    Node *root;
    takeinput(root);
    cout << "output    " << hasPathSum(root, 2);
}