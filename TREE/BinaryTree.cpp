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

// Taking input by using different order
void LevelOrderInput(Node<int> *&root)
{
    queue<Node<int> *> q;
    int data;
    cout << "Enter the root data " << endl;
    cin >> data;
    root = new Node<int>(data);
    q.push(root);

    while (!q.empty())
    {
        Node<int> *temp = q.front();
        q.pop();
        cout << "Enter the left node for " << temp->data << endl;
        int nodeData;
        cin >> nodeData;
        if (nodeData != -1)
        {
            temp->left = new Node<int>(nodeData);
            q.push(temp->left);
        }

        cout << "Enter the right node for " << temp->data << endl;
        // int rightData;
        cin >> nodeData;
        if (nodeData != -1)
        {
            temp->right = new Node<int>(nodeData);
            q.push(temp->right);
        }
    }
}
void InOrder_print(Node<int> *root)
{
    // printing formate of tree-nodes in this order are : LEFT->NODE->RIGHT
    cout << "Formed tree is : " << endl;

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
    cout << "Formed tree is : " << endl;
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
    cout << "Formed tree is : " << endl;
    if (root == NULL)
    {
        return;
    }

    postOrder_print(root->left);
    postOrder_print(root->right);
    cout << root->data << " ";
}

// printing the data level wise.
void LevelOrderprint(Node<int> *root)
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
    // root = takeInput(root);
    //input example : 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 
    LevelOrderInput(root);
    LevelOrderprint(root);

    // cout << "sequencial form " << endl;
    // print(root);
    // cout << endl;

    // cout << "In order : ";
    // InOrder_print(root);
    // cout << endl;

    // cout << "pre_order : ";
    // preOrder_Print(root);
    // cout << endl;

    // cout << "pre_order : ";
    // postOrder_print(root);
    // cout << endl;
}