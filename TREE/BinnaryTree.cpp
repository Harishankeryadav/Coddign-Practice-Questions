// by love babbar : binarry tree.
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;

    Node(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node<int> *takeInput(Node<int> *root)
{
    int data;
    cout << "Enter the  node " << endl;
    ;
    cin >> data;
    root = new Node<int>(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the left node of " << data << endl;
    root->left = takeInput(root->left);
    cout << "Enter the right node of " << data << endl;
    root->right = takeInput(root->right);

    return root;
}

void InOrder_print(Node<int> *root)
{
    // printing formate of tree-nodes in this order are : LEFT->NODE->RIGHT

    if (root == NULL)
    {
        return;
    }

    InOrder_print(root->left);
    cout << root->data << " ";
    InOrder_print(root->right);
}

void preOrder_Print(Node<int> *root)
{
    // printing formate of tree-nodes in this order are : NODE -> LEFT -> RIGHT
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder_Print(root->left);
    preOrder_Print(root->right);
}

void postOrder_print(Node<int> *root)
{
    // printing formate of tree-nodes in this order are : LEFT -> RIGHT -> NODE
    if (root == NULL)
    {
        return;
    }

    postOrder_print(root->left);
    postOrder_print(root->right);
    cout << root->data << " ";
}

// printing the data level wise.
void print(Node<int> *root)
{
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
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

int main()
{
    // // input example : 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 -1
    Node<int> *root = NULL;
    root = takeInput(root);

    cout << "binary iteration :" << endl;
    print(root);

    cout << "In order iteration : ";
    InOrder_print(root);
    cout << endl;

    cout << "pre_order iteration : ";
    preOrder_Print(root);
    cout << endl;

    cout << "pre_order iteration : ";
    postOrder_print(root);
    cout << endl;
}