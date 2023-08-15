#include "TreeNode.h"
#include <queue>
using namespace std;

class BST
{
public:
    Node<int> *root;

    BST()
    {
        root == NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    // printing tree
    void Levelprinting(Node<int> *root)
    {
        // printing formate of tree-nodes in this order are : LEFT->NODE->RIGHT

        if (root == NULL)
        {
            cout <<"empty  " << endl;
            return;
        }

        Levelprinting(root->left);
        cout << root->data << " ";
        Levelprinting(root->right);
    }

    // serching of data.
    bool searchData(int x, Node<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == x)
        {
            return true;
        }

        else if (node->data > x)
            return searchData(x, node->left);
        else
        {
            return searchData(x, node->right);
        }
        return false;
    }

    // insertion of data
    Node<int> *insert(int data, Node<int> *root)
    {
        if (root == NULL)
        {
            Node<int> *newnode = new Node<int>(data);
            return newnode;
        }

        if (data > root->data)
        {
            root->right = insert(data, root->right);
        }
        else
        {
            root->left = insert(data, root->left);
        }
        return root;
    }

    // deletion of data.
    Node<int> *deleteNode(int x, Node<int> *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data > x)
            deleteNode(x, root->left);
        else if (root->data < x)
            deleteNode(x, root->right);
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            else if (root->left == NULL && root->right != NULL)
            {
                Node<int> *temp = root->right;
                root->right = NULL;
                delete (root);
                return temp;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                Node<int> *temp = root->left;
                root->left = NULL;
                delete (root);
                return temp;
            }

            else
            {
                Node<int> *temp = root->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                int minRight = temp->data;
                root->data = minRight;
                temp->right = deleteNode(minRight, temp);
                delete (root);
                return root;
            }
        }
    }

public:
    void Levelprinting()
    {
        cout << "printing ";
        Levelprinting(root);
    }

    bool
    searchData(int num)
    {
        cout << "serching  " << endl;
        return searchData(num, root);
    }

    void deleteNode(int x)
    {
        cout << "Deleting " << endl;
        deleteNode(x, root);
    }

    void insert(int data)
    {
        cout << "inseerting " << endl;
        Node<int> *root = insert(data, root);
    }
};