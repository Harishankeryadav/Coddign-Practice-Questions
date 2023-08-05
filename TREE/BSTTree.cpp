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

// Node *insertTree(Node *root)
// {
//     int data;
//     cin >> data;
//     root = new Node(data);

//     if (data == -1)
//     {
//         return NULL;
//     }

//     cout << "Enter the left data of " << data << endl;
//     root->left = insertTree(root->left);

//     cout << "Enter the right data of " << data << endl;
//     root->right = insertTree(root->right);

//     return root;
// }

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

// taking input as undefined data and puting it accordingly,
// like if it smaller  than parent node then in the left ortherwise in the right.

void input(Node *&root)
{
    int data;
    cout << "Enter the root data ";
    cin >> data;
    root = new Node(data);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "enter the left and right number for node " << temp->data << "   ";
        int num1, num2;
        cin >> num1 >> num2;
        if (num1 != -1)
        {
            if (num1 < temp->data)
            {
                temp->left = new Node(num1);
                q.push(temp->left);
            }
            else if (num1 > temp->data)
            {
                temp->right = new Node(num1);
                q.push(temp->right);
            }
        }

        if (num2 != -1)
        {
            if (num2 < temp->data)
            {
                temp->left = new Node(num2);
                q.push(temp->left);
            }
            else if (num2 > temp->data)
            {
                temp->right = new Node(num2);
                q.push(temp->right);
            }
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
// in-Order printing the given tree.
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

// Node *searching(Node *root, int data)
// {
//     Node *temp;
//     queue<Node *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         temp = q.front();
//         q.pop();
//         if (root == NULL)
//         {
//             cout << "Empty Tree " << endl;
//             return NULL;
//         }
//         else
//         {
//             if (data == temp->data)
//             {

//                 return temp;
//             }
//             if (temp->left != NULL)
//                 q.push(temp->left);

//             if (temp->right != NULL)
//                 q.push(temp->right);
//         }
//     }
//     return NULL;
// }

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

// void Inserting(Node *&root, int PrNode, int data)
// {
//     Node *newNode = new Node(data);
//     if (root == NULL && PrNode == -1 && data == -1)
//     {
//         return;
//     }
//     Node *temp = searching(root, PrNode);

//     if (data < temp->data)
//     {
//         if (temp->left == NULL)
//         {
//             temp->left = newNode;
//             return;
//         }
//         Node *temp1 = temp->left;
//         temp->left = newNode;

//         if (temp1->data < data)
//         {
//             temp->left->left = temp1;
//         }
//         else
//         {
//             temp->left->right = temp1;
//         }
//     }
//     if (data > temp->data)
//     {
//         if (temp->right == NULL)
//         {
//             temp->right = newNode;
//             return;
//         }
//         Node *temp1 = temp->right;
//         temp->right = newNode;

//         if (temp1->data < data)
//         {
//             temp->right->left = temp1;
//         }
//         else
//         {
//             temp->right->right = temp1;
//         }
//     }
// }

// deleting the given node.
void Delete_Node(Node *root, int num)
{
    int count = 0;
    if (root == NULL)
    {
        cout << "Tree is empty " << endl;
        return;
    }
    Node *temp = searching(root, num);
    Node *prev = temp;
    cout << temp->data;
    if (temp->left == NULL && temp->right == NULL)
    {
        Node *parent = root;
        Node *child = root;
        while (child != temp)
        {
            if (child->data < temp->data)
            {
                parent = child;
                child = child->right;
            }
            else
            {
                parent = child;
                child = child->right;
            }
        }
        cout << "inside if " << parent->data << endl;
        if (parent->right->data = temp->data)
            parent->right = NULL;
        else
            parent->left = NULL;
        delete (temp);
        cout << "after deleting " << temp->data << endl;
        return;
    }

    Node *temp1 = temp->left;
    while (temp1->right != NULL)
    {
        prev = temp1;
        temp1 = temp1->right;
        count++;
    }

    if (temp1->left != NULL)
    {
        temp->data = temp1->data;
        temp1->data = temp1->left->data;
        temp1->left = NULL;
        delete temp1;
    }
    else if (temp1->right == NULL && temp1->left == NULL)
    {
        cout << "else if right if NULL " << endl;
        temp->data = temp1->data;
        if (count > 0)
            prev->right = NULL;
        else
            prev->left = NULL;
        delete temp1;
    }
}

// deleting by using reccurtion.
//  Node *Delete_Node(Node *root, int num)
//  {
//      if (root == NULL)
//      {
//          cout << "Tree is empty " << endl;
//          return root;
//      }

//     if (root->data == num)
//     {
//         if (!root->right && !root->left)
//         {
//             delete root;
//             return NULL;
//         }

//         else if (!root->left && root->right)
//         {
//             Node *temp = root->right;
//             delete root;
//             return temp;
//         }
//         else if (!root->right && root->left)
//         {
//             Node *temp = root->left;
//             delete root;
//             return temp;
//         }
//         else
//         {   int min;
//             Node *temp = root->left;
//             while (temp->right)
//                 temp = temp->right;
//             min = temp->data;
//             root->data = temp->data;
//             root->left = Delete_Node(root->left, min);
//             return root;
//         }
//     }
//     else
//     {
//         if (root->data > num)
//         {
//             root->left = Delete_Node(root->left, num);
//             return root;
//         }
//         else if (root->data < num)
//         {
//             root->right = Delete_Node(root->right, num);
//             return root;
//         }
//     }
// }

int main()
{ // ex: 50 25 75 20 30 70 80 15 23 28 40 65 72 76 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Enter the root data ";
    // Node *root = insertTree(root);

    Node *root;
    takeinput(root);
    // Levelprinting(root);

    // Delete_Node(root, 15);

    // taking input, setting them accordingly.
    // input(root);

    // cout << "formed tree is in the form of : \n";
    // // print(root);
    Levelprinting(root);

    // deleting node.
    int num = 0;
    cout << "Enter the number to delete from the tree ";
    cin >> num;
    Delete_Node(root, num);
    Levelprinting(root);

    // searching of number.
    // cout << "Enter the data for search ";
    // int num;
    // cin >> num;
    // Node *temp;
    // temp = searching(root, num);
    // cout << temp->data << "   \n";
    // if (temp != NULL)
    // {
    //     cout << "the node " << temp->data << " is present " << endl;
    //     if (temp->left != NULL)
    //     {
    //         cout << "child of the node is : Left = " << temp->left->data << ", ";
    //     }
    //     if (temp->right != NULL)
    //     {
    //         cout << "Right = " << temp->right->data << endl;
    //     }
    // }
    // else
    // {
    //     cout << "the node " << num << " is not present " << endl;
    // }

    // Inserting node in the tree
    // int PrNode, data;
    // cout << "Enter the parent node and data where we are inserting the new node ";
    // cin >> PrNode >> data;
    // Inserting(root, PrNode, data);
    // Levelprinting(root);
}