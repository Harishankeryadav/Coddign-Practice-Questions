#include <iostream>
using namespace std;
#include <queue>

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

void Take_Input(Node *&root)
{
    int data = 0;
    cout << "Enter the data ";
    cin >> data;
    root = new Node(data);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *newnode;
        newnode = q.front();
        q.pop();
        cout << "\nEnter the left node of " << newnode->data << " ";
        cin >> data;
        if (data != -1)
        {
            newnode->left = new Node(data);
            q.push(newnode->left);
        }

        cout << "\nEnter the right node of " << newnode->data << " ";
        cin >> data;
        if (data != -1)
        {
            newnode->right = new Node(data);
            q.push(newnode->right);
        }
    }
}

void Level_printing(Node *root)
{
    if (root == NULL)
    {
        cout << "Empty tree " << endl;
        return;
    }
    else
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                    q.push(NULL);
            }
            else
            {
                cout << temp->data << " ";
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
    }
}

void count_Node(Node *root)
{
    int count = 0;
    if (root == NULL)
    {
        cout << "Empty tree  ";
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            count++;
            q.push(temp->left);
        }
        if (temp->right)
        {
            count++;
            q.push(temp->right);
        }
    }
    cout << "Total number of node in the given tree is : " << count << endl;
}

int main()
{
    // ex: 50 25 75 20 30 70 80 15 23 28 40 65 72 76 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    Node *root;
    Take_Input(root);
    cout << "printing data " << endl;
    Level_printing(root);
    count_Node(root);
}


