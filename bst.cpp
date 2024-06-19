#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    Node *left;
    int data;
    Node *right;
};
class Tree
{
    Node *root;

public:
    void create(vector<int> nums)
    {
        Node *p, *q, *temp;
        root = new Node;
        root->data = nums[0];
        root->left = NULL;
        root->right = NULL;
        for (int i = 1; i < nums.size(); i++)
        {
            p = root;
            q = root;
            while (p)
            {
                q = p;
                if (p->data < nums[i])
                    p = p->right;
                else
                    p = p->left;
            }
            temp = new Node;
            temp->data = nums[i];
            temp->left = NULL;
            temp->right = NULL;
            if (q->data > nums[i])
                q->left = temp;
            else
                q->right = temp;
        }
    }

    bool search(Node *p, int target)
    {
        if (!p)
            return false;
        if (p->data == target)
            return true;
        else if (p->data > target)
            return search(p->left, target);
        else
            return search(p->right, target);
    }

    void insert(int x)
    {
        Node *p = root, *q, *temp;
        while (p)
        {
            q = p;
            if (p->data > x)
                p = p->left;
            else
                p = p->right;
        }
        temp = new Node;
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        if (q->data > x)
            q->left = temp;
        else
            q->right = temp;
    }

    Node *dlt(Node *root, int x)
    {
        if (root == NULL)
            return root;
        if (root->data == x)
        {
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            else if (root->left && !root->right)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else if (!root->left && root->right)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else
            {
                int min;
                Node *temp = root->left;
                while (temp->right)
                    temp = temp->right;
                min = temp->data;
                root->data = min;
                root->left = dlt(root->left, min);
                return root;
            }
        }
        else if (root->data < x)
        {
            root->right = dlt(root->right, x);
            return root;
        }
        else
        {
            root->left = dlt(root->left, x);
            return root;
        }
    }

    void inorder(Node *p)
    {
        if (p)
        {
            inorder(p->left);
            cout << p->data << " ";
            inorder(p->right);
        }
    }

    Node *getRoot()
    {
        return root;
    }
};
int main()
{
    vector<int> nums = {7, 10, 1, 5, 4, 3, 11, 9};
    Tree tree;
    tree.create(nums);
    // tree.search(tree.getRoot(), 3) ? cout << "Found\n" : cout << "Not Found\n";
    // tree.insert(8);
    tree.dlt(tree.getRoot(), 1);
    cout << "Inorder Traversal: ";
    tree.inorder(tree.getRoot());
    cout << endl;
    return 0;
}